#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "carregar_pontos.h"
#include "recuperar_usuario.h" 
#include "carregar_estado.h" 
#include "acrescentar_usuario.h"


void acrescentar_usuario(char* jogador) {
	FILE *pFile; 
	char jogador2[50];
	pFile = fopen (file_user, "r"); 
	int flag = 0;
	if(pFile != NULL)
	{     
		while(fscanf(pFile, "%s", jogador2) != EOF) {  
			if (strcmp(jogador2, jogador) == 0)
			{   
				flag = 1;  
				break;
			}
		}
		if (flag == 0) {
			fclose(pFile); 
			pFile = fopen (file_user, "a");
			fprintf(pFile, "%s\n", jogador);
		}
	}
	else
	{
		fprintf(pFile, "%s", jogador);
	}
	fclose(pFile); 
}