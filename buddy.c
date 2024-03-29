// buddy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "PE_Types.h"
#include "system.h"
#include "displayDebug.h"
#include "SistemaOperativo.h"
#include <windows.h>
#include <conio.h>
#include "queue.h"


struct _MemoManagement_ mm;

DWORD WINAPI ThreadFunc(void* data) {
	byte c;
	//DWORD r = 1;
	// Do stuff.  This will be the first function called on the new thread.
	// When this function returns, the thread goes away.  See MSDN for more details.
	printf("\nThread:OK");
	while (!_kbhit()) {
        
		c = _getch();
		if (c == 13) {
			shell.sem = ROJO;
			printf("\n");
			shell.input.appendByte(c, &shell.input);
			SuspendThread(GetCurrentThread());}
		else { printf("%c", c);
			   shell.input.appendByte(c,&shell.input);}}
	return 1;
}//fin de thread++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main(){
byte procMemo[PROC_MAX] = { 2,1,2,3,4,6,8,25,55,8,12,11,2,3,4,33,10,50,2,3,4,5,6,8,15 };

printf("Test del Algorithmo Buddy v0.2.21\n");
init_queue();
init_memoria_de_Procs();
HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
HANDLE thread2 = CreateThread(NULL, 0, procesador_de_comados,(LPVOID)thread, 0, NULL);
WaitForSingleObject(thread, INFINITE);
shell.h = thread;
WaitForSingleObject(procesador_de_comados, INFINITE);


//procesador_de_comados(thread);

printf(" \nfin del programa");
//displayFragmentacion(mm);
//CloseHandle(thread);
}//main+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
