#pragma once
#ifndef DISPLAYDEBUG_H
#define DISPLAYDEBUG_H

#include "PE_Types.h"
#include "SistemaOperativo.h"
#include <Windows.h>

void displayFragmentacion(struct _MemoManagement_ mm);
byte ordenarNodos_v2(struct _Nodo_* m, struct _Nodo_ *p);
void displayMemoria_de_Procesos_Barra(struct _MemoManagement_ mm);
DWORD WINAPI procesador_de_comados(LPVOID in);

#endif