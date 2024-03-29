#include "displayDebug.h"
#include <stdio.h>
#include "system.h"
#include "SistemaOperativo.h"
#include "queue.h"
#include "shell.h"
#include <conio.h>


/* display la memoria particionada como se indica
 */
extern struct _MemoManagement_ mm;
extern byte buffer1[SIZE_BUFFER1];

/* desplegar la barra fragmentada donde se ven los espacions vacios
  y el bloque de pointers a los nodos de bloques de memoria libre*/
void displayFragmentacion(struct _MemoManagement_ mm) {
	int i,size=0;
	//struct _Nodo_ nodos[PROC_MAX];
	 printf("Numero de Procesos Maximo: %i\n",PROC_MAX);
	 printf("Tamaño de Memoria para Procesos:%i\n", MEMO_PROC_SIZE);
	 printf("Memoria Para Procesos:\n");
	 displayMemoria_de_Procesos_Barra(mm);
	 
	 for(i=0;i<size;i++)
		printf("");

	 for (i = 0; i < 50; i++) {
		 printf("_*");}
	 
}//FIN DE DISPLAY de fragmentacion+++++++++++++++++++++++++++++++++++++++++++++++

/* despliega la barra donde se ve fragmentada la memoria aplicada entre procesos
y la memoria libre*/
void displayMemoria_de_Procesos_Barra(struct _MemoManagement_ mm) {
struct _Nodo_ arrNodosOrdenados[PROC_MAX];
 printf("used space: %i    Free space:%i\n", mm.UsedSpace, mm.FreeSpace);
 printf("Ordenando Nodos de la lista de Pointers del Block de nodos Libres... \n");
 if (!ordenarNodos_v2(&mm.FBp[0], &arrNodosOrdenados[0])) {}



 printf("used space: %i,  Free space:%i\n",mm.UsedSpace,mm.FreeSpace);
 
}//fin de diplsay de la memoria de procesos como una barra deon

//ingresamos los nodos a los que apunta mm y los vaciamos a p ordenados
//regresa el numero de nodos que se encontro y ordeno, ret=0 es error
byte ordenarNodos_v2(struct _Nodo_ *m,struct _Nodo_ *p) {
	printf("\n Ordenando nodos m->p \n");

return 0;
}//fin de ordenamiento de memo managementy lo ordenan al array p


DWORD WINAPI procesador_de_comados(LPVOID in) {
	byte ret = 1,i;
	byte estado=0;
	byte tokens[TOKENS_MAX];
	printf("\nSistema Monitor:");
	Sleep(300);
	printf("ok");
	while (ret) {
		switch (estado) {
		case 1:printf("\nIngrese Comando"); estado++; break;
		case 2:printf(":"); estado++; break;
		case 3:if (shell.sem == ROJO)estado++;break;
		case 4:estado++; break;
		case 5:if(Analisis_lexico(&tokens[0])) estado++;
			  else { estado = 99; }break;

		case 99:shell.sem = 0;
			     Sleep(10);
				 for (i = 0; i < SIZE_BUFFER1; i++) {
					 if (buffer1[i] == 0) break;
					 printf("%c", buffer1[i]);}
			     printf("\nNo se reconoce como comando interno o externo, programa ejecutable.");
			    shell.input.resetFIFO(&shell.input,&buffer1[0],SIZE_BUFFER1);
				ResumeThread((HANDLE)in);
				estado = 0; 
				break;
		case 100:ret = 0; break;
		default:estado = 1; break;	}//fin switch
	}//fin while
 	 

	return 0;
}//fin procesador de comandos++++++++++++++++++++++++++++++++++++++++