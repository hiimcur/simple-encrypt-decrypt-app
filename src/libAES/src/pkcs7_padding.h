#ifndef PKCS7_PADDING
#define PKCS7_PADDING

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

int pkcs7_padding_pad_buffer( uint8_t *buffer,  size_t data_length, size_t buffer_size, uint8_t modulus );
int pkcs7_padding_valid( uint8_t *buffer, size_t data_length, size_t buffer_size, uint8_t modulus );
size_t pkcs7_padding_data_length( uint8_t * buffer, size_t buffer_size, uint8_t modulus );

#endif 