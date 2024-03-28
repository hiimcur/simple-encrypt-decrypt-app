#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PREFIX_OUTPUT_FILE_LENGTH 10
#define ENCRYPT 0
#define DECRYPT 1

typedef struct {
    char fileName[256];
    char* fileContent;
} FileInfo;

typedef struct {
    FileInfo* files;
    int fileCount;
    int mode;
    uint8_t* key;
    uint8_t* iv;
    char* outputFolder;
} ThreadData;

uint8_t* _HexStringToByteArray(char* hexString);
void _ReadTextFile(const char* filePath, char** fileContent);
int _HasExtension(char* fileName, char* extension);
void _ProcessFolder(const char* folderPath, FileInfo** files, int* fileCount);
void _ExportFile(uint8_t *content, size_t size, char *folderPath, char *fileName, char *mode);
char* _SetOutputFileName(char* fileName, int mode);

#endif // _UTILS_H_