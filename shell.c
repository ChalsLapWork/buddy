#include "shell.h"
#include <stdio.h>
#include "queue.h"
#include "errorController.h"


/*analisis del string de comando del prompt
  convierte los tokens string en tokens hexagesimal*/

byte Analisis_lexico(byte* token) {
//byte tokenstring[TOKENS_MAX][SIZE_TOKEN_STRING], dato, i = 0, ret = 1;
//byte ArrayInput[SIZE_BUFFER1];//TAMAÑO DE STRING DE comando prompt
struct _Num_Tokens Ntk;

     contar_tokens_e_indices(&Ntk);
	 getSize_tokens(&Ntk);
	 getComando(&Ntk);
	 getParametros(&Ntk);

return 0;
}//fin de analisis de lexico+++++++++++++++++++++++++++++++++



/* obtener el comando */
void getComando(struct _Num_Tokens *ntk) {

	 

}//fin de get comando++++++++++++++++++++++++++++++++++++++++++++++


void getSize_tokens(struct _Num_Tokens *ntk) {
byte i,*p, * pop, * tail, * head, * push,j,ncount;
 pop = shell.input.pop; 
tail = shell.input.tail;
head = shell.input.head;
push = shell.input.push;
   
for(i=0;i<ntk->Num_d_Tokens;i++) {
	p=ntk->indexToken[i];
	ncount=0;
	while((*p!=' ')||(*p!=0)){
		ncount++;
		p++;}
	ntk->sizeToken[i]=ncount;
	if(*p==0) break;}
}//fin sacar el numero de tokens+++++++++++++++++++++++++++++++

void  contar_tokens_e_indices(struct _Num_Tokens* s) {
	byte i, * pop, * tail, * head, * push;
  	 pop = shell.input.pop;
	tail = shell.input.tail;
	head = shell.input.head;
	push = shell.input.push;

	if (*pop == 0) {
		s->comando = 0;
		s->Num_d_Tokens = 0;
		return;}
	else {s->Num_d_Tokens = 0;
		while (*pop != 0) {
			while (*pop == ' ') {//elimina espacio en blanco al inicio
				incrementa(pop, head, tail);}
			s->indexToken[s->Num_d_Tokens] = pop;
			s->Num_d_Tokens++;
			incrementa(pop, head, tail);}}
}//fin de contar tokens++++++++++++++++++++++++++++++++++++++


/* p:incrementa el pointer en la fifo,
   head dela fifo
   tail de la fifo*/
	void incrementa(byte *p, byte *head, byte *tail) {
		if (pop == tail)
			pop = head;
		else pop++;
	}//fin de la incrementacion del pointer++++++++++++++++++++++++++
