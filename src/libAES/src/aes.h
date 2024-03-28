#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>
#include <stddef.h>
#include <pthread.h>
#include "utils.h"

//NOTIFY::Recently using CBC algorythm for AES

#define AES128 1

#define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only

#define AES_KEYLEN 16   // Key length in bytes
#define AES_keyExpSize 176

struct AES_ctx
{
  uint8_t RoundKey[AES_keyExpSize];
  uint8_t Iv[AES_BLOCKLEN];
};

// buffer size MUST be mutile of AES_BLOCKLEN;
// Suggest https://en.wikipedia.org/wiki/Padding_(cryptography)#PKCS7 for padding scheme
// NOTES: you need to set IV in ctx via AES_init_ctx_iv() or AES_ctx_set_iv()
//        no IV should ever be reused with the same key 

void EncryptCBC(char* plainText, uint8_t* key, uint8_t* iv, char* outputFolder, char* outputFileName);
void DecryptCBC(char* cipherText, uint8_t* key, uint8_t* iv, char* outputFolder, char* outputFileName);
void HandleInput(int mode, char* inputFolder, char* outputFolder, FileInfo* files, int fileCount, uint8_t* key, uint8_t* iv);
void HandleInputUsingThread(int mode, char* inputFolder, char* outputFolder, FileInfo* files, int fileCount, uint8_t* key, uint8_t* iv, int num_threads);

void* _ProcessFilesUsingThread(void* arg);

#endif // _AES_H_
