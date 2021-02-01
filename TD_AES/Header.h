#pragma once

//Definition du mode en AES 256
#define AES128 1

//Definition des valeur de Nk Nb Nr en fonction du mode d'execution dans le header
#if defined(AES256) && (AES256 == 1)
#define Nk 8
#define Nb 4
#define Nr 14
#elif defined(AES192) && (AES192 == 1)
#define Nk 6
#define Nb 4
#define Nr 12
#else
#define Nk 4 //AES 128
#define Nb 4
#define Nr 10
#endif

typedef uint8_t STATE[4][Nb];

void Cipher(STATE* , STATE* , STATE* );

void SubBytes(STATE* );

void ShiftRows(STATE );

void MixColumns(STATE );

void AddRoundKey(uint8_t,STATE* , STATE*);

uint8_t xtime(uint8_t);

void RotWord();