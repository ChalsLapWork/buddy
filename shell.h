#pragma once
#ifndef _SHELL_H_
#define _SHELL_H_

#include "PE_Types.h"


#define PROMPT_SIZE 100


typedef struct {
	byte prompt[PROMPT_SIZE];
	byte sem;//semaforo para saber si terminaron de escribir el comando

}consola;





#endif
