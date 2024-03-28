// buddy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "PE_Types.h"
#include "system.h"
#include "displayDebug.h"
#include "SistemaOperativo.h"
#include <windows.h>
#include <conio.h>

struct _MemoManagement_ mm;

DWORD WINAPI ThreadFunc(void* data) {
	byte c;
	// Do stuff.  This will be the first function called on the new thread.
	// When this function returns, the thread goes away.  See MSDN for more details.
	printf(" \n estoy en thread \n");
	while (!_kbhit()) {
		c = _getch();
		if (c == 13)
			printf("\n");
		else printf("%c",c);}
	return 1;
}//fin de thread++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main(){
byte procMemo[PROC_MAX] = { 2,1,2,3,4,6,8,25,55,8,12,11,2,3,4,33,10,50,2,3,4,5,6,8,15 };

printf("Test del Algorithmo Buddy v0.2.9\n");
init_memoria_de_Procs();
HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
WaitForSingleObject(thread, INFINITE);



//displayFragmentacion(mm);
CloseHandle(thread);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
