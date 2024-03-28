#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <logLib.h>
#include <aes.h>

#define MAX_THREADS 2
#define CBC 1

int main(int argc, char *argv[])
{
    printf("Hello app AES\n");

    uint8_t iv[]  = { 0x75, 0x52, 0x5f, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x65, 0x73, 0x74, 0x69, 0x6e, 0x67, 0x21, 0x21 };
    char* key = "thisIstheKey";

    char* option = argv[1];
    char* folderPath = argv[2];
    char* outputFolder = argv[3];
    FileInfo* files = NULL;
    int fileCount = 0;

    setLogLevel(4); 

    if (argc != 4) {
        printf("Usage: %s <-e/-d> <inputFolder> <outputFolder>\n", argv[0]);
        return 1;
    }

    if(strcmp(option, "-e") == 0)
    {
        //HandleInput(ENCRYPT, folderPath, outputFolder, files, fileCount, key, iv);
        HandleInputUsingThread(ENCRYPT, folderPath, outputFolder, files, fileCount, key, iv, MAX_THREADS);
    } else if(strcmp(option, "-d") == 0)
    {
        //HandleInput(DECRYPT, folderPath, outputFolder, files, fileCount, key, iv);
        HandleInputUsingThread(DECRYPT, folderPath, outputFolder, files, fileCount, key, iv, MAX_THREADS);
    } else 
    {
        printf("Invalid option: %s\n", option);
        return 1;
    }

    return 0;
}