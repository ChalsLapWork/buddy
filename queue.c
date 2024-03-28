#include "PE_Types.h"
#include "system.h"
#include "queue.h"







void init_FIFO_General_1byte(struct _FIFO_1byte_* s, unsigned char* h, unsigned char size) {//FIFO_SER_KEYPAD[SIZE_SER_KEYPAD];

	s->tail = h + size - 1;
	s->head = h;
	s->pop = s->push = h;
	s->ncount = 0;
	s->popf = FIFO_general_1byte_pop;
	s->appendByte = FIFO_general_1byte_push;
	s->size = size;
	s->resetFIFO = reset_FIFO_general_UChar;
	return;
}//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



unsigned char FIFO_general_1byte_push(unsigned char dato, struct _FIFO_1byte_* s) {
	auto unsigned char ret = 0;
	//byte  ncount;


	if (s->pop == s->head)
		if (s->push == (s->tail - 1))
			return FALSE;
	if (s->push + 1 == s->pop)
		return FALSE;
	*(s->push) = dato;
	s->ncount++;
	if (s->push == s->tail)
		s->push = s->head;
	else s->push++;
	ret = TRUE;

	return ret;
}//fin de push+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


unsigned char FIFO_general_1byte_pop(unsigned char* dato, struct _FIFO_1byte_* s) {
	byte ret = 0;
	byte* pop0, * push0, ncount0;

	pop0 = s->pop;
	push0 = s->push;
	ncount0 = s->ncount;

	if (s->pop == s->push)
		return FALSE;//vacio empty
	*dato = *(s->pop);
	*(s->pop) = 0;
	if (s->pop == s->tail)
		s->pop = s->head;
	else s->pop++;
	s->ncount--;
	ret = TRUE;

return ret;
}//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void reset_FIFO_general_UChar(struct _FIFO_1byte_ *s,unsigned char *arr,unsigned short int  size){
	unsigned char i;
   	   s->pop=s->push=s->head;
	   s->tail=s->head+s->size-1;
	   s->ncount=0;
	   s->ncount=0;
	   for (i = 0; i < size; i++)
		   *(arr + i) = 0;
}//fin de clean array----------------------------------------------------------------

