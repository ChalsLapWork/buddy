#ifndef SISTEMAOPERATIVO_H
#define SISTEMAOPERATIVO_H

#include "PE_Types.h"
#include "system.h"

#define FreeBlockPointerSize 8 


struct _Nodo_ {
	byte id;
	byte *Address;  //direccion de la memoria
	byte NumBlock; //numero de block
	byte size;//tamaño del blockque
	struct _Nodo_* next;
};

struct _MemoManagement_ {
	struct _Nodo_ FBp[8];//apuntadores de tamaño
	struct _Nodo_ nodo[PROC_MAX];//nodos libres para se usados flotantes para el arbol de espacio libre
	byte MEMORIA_DE_PROCESOS[MEMO_PROC_SIZE];
	int FreeSpace;
	int UsedSpace;
};

void ordenarNodos(struct _MemoManagement_ mm1, struct _Nodo_* n);
byte buscando_nodos_hijos(struct _Nodo_ nodo, byte* index, byte* a);
void init_memoria_de_Procs(void);
struct _Nodo_* get_FreeNodo(struct _Nodo_* n);

#endif