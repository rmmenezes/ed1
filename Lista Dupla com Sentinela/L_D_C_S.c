#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L_D_C_S.h"

int main(){

	Lista* l = lista_cria();

	T e1 = 1;
	T e2 = 2;
	T e3 = 3;
	T e4 = 4;
	T e5 = 5;
	T e6 = 9;


	lista_insere_fim(l, e1);
	lista_insere_fim(l, e2);
	lista_insere_fim(l, e3);
	lista_insere_fim(l, e4);
	lista_insere(l, e6, 1);
	lista_insere_fim(l, e5);


	printf("Imprimindo Lista\n");
	lista_imprime(l, &imprime_t);

	printf("\nBUSCA do tipo 2\n");
	printf("Busca-1- [%d].\n", *lista_busca1(l, 4));
	printf("Busca-1- [%d].\n", *lista_busca1(l, 0));
	printf("Busca-1- [%d].\n", *lista_busca1(l, -3));
	printf("Busca-1- [%d].\n", *lista_busca1(l, 12));

	printf("\nBUSCA do tipo 1\n");
	T end;
	lista_busca2(l, 4, &end); printf("Busca-2 [%d].\n", end);
	lista_busca2(l, 0, &end); printf("Busca-2 [%d].\n", end);
	lista_busca2(l, -3, &end); printf("Busca-2 [%d].\n", end);
	lista_busca2(l, 12, &end); printf("Busca-2 [%d].\n", end);

	
	printf("Função contem\n");
	int temp = lista_contem(l, e2, &compara_t);
	printf("Posição -[ %d ]-\n", temp);

	temp = lista_contem(l, e1, &compara_t);
	printf("Posição -[ %d ]-\n", temp);

	temp = lista_contem(l, e5, &compara_t);
	printf("Posição -[ %d ]-\n", temp);

	temp = lista_contem(l, e6, &compara_t);
	printf("Posição -[ %d ]-\n", temp);
	
	printf("REMOVIDO: [%d]. \n", *lista_remove1(l, 2));
	printf("REMOVIDO: [%d]. \n", *lista_remove1(l, -1));

/*
	lista_remove2(l, 2, &end);
	printf("REMOVIDO: [%d]. \n", end);
	lista_remove2(l, -1, &end);
	printf("REMOVIDO: [%d]. \n", end);
	lista_remove2(l, 103, &end);
	printf("REMOVIDO: [%d]. \n", end);
	lista_remove2(l, 3, &end);
	printf("REMOVIDO: [%d]. \n", end);
*/

	printf("Imprimindo Lista\n");
	lista_imprime(l, &imprime_t);

	return 0;
}