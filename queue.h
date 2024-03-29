#pragma once
#include <Windows.h>

#define SIZE_BUFFER1  100 //TAMAÑO DE buffer de entrada de string de consola 
#define PROMPT_SIZE 100

#define ROJO 'R'


/*version 310322-1641 add reset genaral */
struct _FIFO_1byte_ {//FIFO PARA UNA VARIABLE para un byte
	unsigned char* pop;//primer de la FIFO para salir
	unsigned char* head;//indice 0 del buffer
	unsigned char* tail;//ultimo indice del buffer
	unsigned char* push;//pointer buffer 2
	unsigned char (*popf)(unsigned char* n, struct _FIFO_1byte_* s);//quitar el prmer elemento de la fifo DDS
	unsigned char (*appendByte)(unsigned char  n, struct _FIFO_1byte_* s);//agregar byte al buffer de transmision
	void (*vaciarbuff)(unsigned char* p1, unsigned char* p2, unsigned short int size);
	void (*resetFIFO)(struct _FIFO_1byte_* s, unsigned char* arr, unsigned short int size);
	unsigned short int ncount;//cuenta los nodos llenos en la fifo
	unsigned short int size; //size de la fifo
};//fin de struct+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



struct _CONSOLE_{
	byte prompt[PROMPT_SIZE];
	byte sem;//semaforo para saber si terminaron de escribir el comando
	struct _FIFO_1byte_ input;
	HANDLE h;
}shell;




unsigned char FIFO_general_1byte_pop(unsigned char* dato, struct _FIFO_1byte_* s);
unsigned char FIFO_general_1byte_push(unsigned char dato, struct _FIFO_1byte_* s);
void init_FIFO_General_1byte(struct _FIFO_1byte_* s, unsigned char* h, unsigned char size);
void reset_FIFO_general_UChar(struct _FIFO_1byte_* s, unsigned char* arr, unsigned short int  size);
void init_queue(void);