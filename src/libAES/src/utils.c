#include "utils.h"

uint8_t* _HexStringToByteArray(char* hexString) {
    size_t len = strlen(hexString);
    //printf("Hex string len: %ld \n", len);
    if (len % 2 != 0) {
        fprintf(stderr, "Invalid hex string length\n");
        return NULL;
    }

    size_t byteLen = len / 2;
    uint8_t* byteArray = (uint8_t*)malloc(byteLen);
    if (byteArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (size_t i = 0, j = 0; i < len; i += 2, j++) {
        sscanf(hexString + i, "%2hhx", &byteArray[j]);
    }

    return byteArray;
}

void _ReadTextFile(const char* filePath, char** fileContent) {
    FILE* file = fopen(filePath, "r");

    if (file == NULL) {
        printf("Cannot open file %s\n", filePath);
        *fileContent = NULL;
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *fileContent = (char*)malloc(fileSize + 1);

    if (*fileContent == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return;
    }

    size_t bytesRead = fread(*fileContent, 1, fileSize, file);

    if (bytesRead != (size_t)fileSize) {
        printf("Wrong content with file path: %s\n", filePath);
        free(*fileContent);
        *fileContent = NULL;
    } else {
        (*fileContent)[fileSize] = '\0';
    }

    fclose(file);
}

int _HasExtension(char* fileName, char* extension) {
    char* dot = strrchr(fileName, '.');
    return (dot && strcmp(dot + 1, extension) == 0);
}

void _ProcessFolder(const char* folderPath, FileInfo** files, int* fileCount) {
    DIR* dir = opendir(folderPath);
    struct dirent* entry;

    if ((dir = opendir(folderPath)) == NULL) {
        printf("Cannot open directory %s\n", folderPath);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG || S_ISREG(entry->d_type)) {
            // It's a regular file
            char filePath[PATH_MAX];
            snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, entry->d_name);

            if (_HasExtension(entry->d_name, "txt")) {
                FileInfo fileInfo;
                strcpy(fileInfo.fileName, entry->d_name);

                _ReadTextFile(filePath, &fileInfo.fileContent);

                *files = (FileInfo*)realloc(*files, (*fileCount + 1) * sizeof(FileInfo));
                (*files)[*fileCount] = fileInfo;
                (*fileCount)++;
            }
        }
    }
    closedir(dir);
}

void _ExportFile(uint8_t *content, size_t size, char *folderPath, char *fileName, char *mode) {
    
    struct stat st = {0};
    if (stat(folderPath, &st) == -1) {
        if (mkdir(folderPath, 0777) != 0) {
            perror("Error creating folder");
            return;
        }
    }

    char filePath[512];
    snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, fileName);
    FILE *file = fopen(filePath, "w");

    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    if (strcmp(mode, "-e") == 0) {
        for (size_t i = 0; i < size; i++) {
            fprintf(file, "%02x", content[i]);
        }
    } else if (strcmp(mode, "-d") == 0) {
        fwrite(content, 1, size, file);
    }

    fclose(file);

    printf("Exported to %s\n", filePath);
}

char* _SetOutputFileName(char* fileName, int mode)
{
    size_t fileNameLength = PREFIX_OUTPUT_FILE_LENGTH + strlen(fileName) + 1;
    char* outputFileName = (char*)malloc(fileNameLength);
    if (outputFileName == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return "none";
    }

    if(mode == ENCRYPT)
    {
        sprintf(outputFileName, "encrypted_%s", fileName);
        return outputFileName;
    }

    else if(mode == DECRYPT)
    {
        sprintf(outputFileName, "decrypted_%s", fileName);
        return outputFileName;
    }

    else
    {
        printf("Invalid mode. \n");
        return "none";
    }
}
