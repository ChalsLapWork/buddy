#include "errorController.h"


void errorCritico(const unsigned char* mensaje) {

	printf("Error: %s ", mensaje);
	system("pause");
	exit(1);

}//fin error critico+++++++++++++++++++++++++++++++++++++++++
