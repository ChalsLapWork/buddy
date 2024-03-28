#include "SistemaOperativo.h"
#include "system.h"
#include <stdio.h>
#include <stdlib.h>
#include "errorController.h"

struct _MemoManagement_ mm;
struct _Nodo_ NodoError;


void init_memoria_de_Procs(void) {
	byte i;
	struct _Nodo_ *nodo1;
	mm.FreeSpace = PROC_MAX;
	mm.UsedSpace = 0;
	for (i = 0; i < FreeBlockPointerSize; i++) {//reset a todo el banco de pointers
		mm.FBp[i].next = 0;
		mm.FBp[i].NumBlock = 0;
		mm.FBp[i].id = 0;
		mm.FBp[i].size = 0;	}
	nodo1=get_FreeNodo(&mm.nodo[0]);//obtenemos un nodo libre del banco de nodos libres
	if (nodo1 == &NodoError) { errorCritico("ERROR 20"); }
	nodo1->Address = &mm.MEMORIA_DE_PROCESOS[0];
	nodo1->NumBlock = 0;
	nodo1->size = 255;
	mm.FBp[_256].next = nodo1;
}//fin de init memoria de porcedimientos


//** del array de nodos libres obtener un nodo libre 
struct _Nodo_ *get_FreeNodo(struct _Nodo_ *n){
	static byte nn;// Para que no recorra todo el array cada vez que entra aqui
	byte i,ret=0;
	struct _Nodo_ *ret2;
	ret2 = &NodoError;
	if(nn>PROC_MAX)n=0;
	for(i=nn;i<PROC_MAX;i++){
	    if((n+i)->Address==0){
		   ret2=(n+i);ret=TRUE;}}
	nn=i;
	if(ret)
	   return ret2;
return ret2;
}//fin de obtener un nodo del array de nodos libres+++++++++++++++++++++++++++++



void ordenarNodos(struct _MemoManagement_ mm1, struct _Nodo_* n) {
	//char* nodoNum[8] = { "2","4","8","16","32","64","128","256" };
	//byte b[PROC_MAX];
	//byte a[PROC_MAX], i, j = 0, k = 0, m;
	//byte index;//linked list array index
	/*struct Node {
		byte valor;
		struct Node* next;
	};*/
	//struct Node b[PROC_MAX];
	//struct Node c[PROC_MAX];
	//struct Node e, * g;
	/*printf("transfiriendo datos del nodo al array utileria -->a  ");
	for (i = 0; i < 8; i++) {
		printf("\nBuscando en Nodo=%s: ", nodoNum[i]);
		buscando_nodos_hijos(mm1.FBp[i], &j, a);
	}
	printf("\nNodos Encontrados: %i\n", j);
	for (i = 0; i < j; i++) {
		printf("%i,", a[i]);
	}
	printf("\nOrdenando:\nlinked list array index= ");
	*/
	/*
	for(i=0,k=0;i<j;i++,k++){
	  c[k].valor=a[i];c[k].next=0;a[i]=0;
	  index=(a[i]*j)/(PROC_MAX+1);printf(" %i",index);
	  if(b[index].next==0){//acomodando nodos en la lista B
		   b[index].next=&c[k];
		   b[index].valor=0;
		   a[i]=0;}
	  else{g=b[index].next;
		   if(g.valor>c[k].valor){
				 b[index].next=&c[k];
				 c[k].next=g;}
		   else{g->next=c[k];}}}
	 for(i=0,m=0;m<PROC_MAX;i++){
		 if(b[i].next!=0){
			  e=b[i].next;
			  a[m++]=e.valor;
			  e.valor=0;
			  while(e.next!=0){
					  e=e.next;
					  a[m++]=e.valor;
					  b[i].next=e;}
			  b[i].next=0;}}
	 */

	/*printf("\n Ordenando:a\n ");
	for (i = 0; i < PROC_MAX; i++)
		printf("%d,", a[i]);
		*/
}//fin de ordenar nodos++++++++++++++++++++++++++++++++++++++++++++++++++


/* busca cuantos nodos hay y mete en un array
	el numero de bloque de todos los nodos en un array como los
	va encontrando*/
byte buscando_nodos_hijos(struct _Nodo_ nodo, byte* index, byte* a) {

	if ((nodo.Address == 0) && (nodo.id == 0))
		return 0;
	else {
		*(a + *index) = nodo.NumBlock;
		printf("%i,", nodo.NumBlock);
		(*index)++;
		buscando_nodos_hijos(nodo, index, a);}
return 0;
}//fin de buscar en los nodos hijos el numero de bloque