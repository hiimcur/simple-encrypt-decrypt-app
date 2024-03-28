#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <aes.h>
#include <utils.h>

#define CBC 1

int main(void)
{
    uint8_t iv[]  = { 0x75, 0x52, 0x5f, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x65, 0x73, 0x74, 0x69, 0x6e, 0x67, 0x21, 0x21 };
    char* report = "my super secret thing that needs to remain that way!";
    char* cipherText = "cdc4244c4828ed73e78c75a5db94d577d1f69472140204d7a6ce89f6f1d42d2962031470e3dd3d4b99a735504b4b9d8a277ba6bda54a06c2291380fae26f0fd0"; //report after encrypted
    char* key = "thisIstheKey";
    char* encryptoutputFolder = "../../EncryptedFolder";
    char* encryptoutputFileName = "encryptedText.txt";
    char* decryptoutputFolder = "../../DecryptedFolder";
    char* decryptoutputFileName = "decryptedText.txt";

    size_t iv_len = sizeof(iv) / sizeof(iv[0]);
    printf("iv: ");
    for (size_t i = 0; i < iv_len; i++) {
        printf("%02X ", iv[i]);
    }
    printf("\n");

    EncryptCBC(report, key, iv, encryptoutputFolder, encryptoutputFileName);

    DecryptCBC(cipherText, key, iv, decryptoutputFolder, decryptoutputFileName);
    return 0;
}