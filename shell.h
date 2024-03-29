#pragma once
#ifndef _SHELL_H_
#define _SHELL_H_

#include "PE_Types.h"
//#include "queue.h"


#define  SIZE_TOKEN_STRING 20//
#define  TOKENS_MAX   5 //maximo numero de otkens

byte Analisis_lexico(byte* token);


struct _Num_Tokens {
	byte Num_d_Tokens;
	byte *indexToken[TOKENS_MAX];//indice donde empieza el token
	byte sizeToken[TOKENS_MAX];//tamaño del token
	byte comando;
	byte parametros[TOKENS_MAX];
};//numero de tokens




#endif
