#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "L_D_E.h"

int main (){

	int elem;

	Lista* l = Lista_criar();
	Lista_inserir_fim(l, 80);
	Lista_inserir_fim(l, 90);
	Lista_inserir_fim(l, 100);
	Lista_inserir_fim(l, 200);
	Lista_inserir(l, 10, 0);
	Lista_inserir(l, 30, 4);
	Lista_inserir(l, 40, 5);
 	Lista_imprimir(l, &print_int);

 	printf("\n");

	Lista_remover1(l, 6); 
	Lista_remover2(l, 0, &elem); 
 	Lista_imprimir(l, &print_int);


	printf("Busca do elemento por posição - 1\n");
	printf("Pos[0] = [%d]\n", *Lista_busca1(l, 0));
	printf("Pos[3] = [%d]\n", *Lista_busca1(l, 3));
	printf("Pos[2] = [%d]\n", *Lista_busca1(l, 2));

	printf("Busca do elemento por posição - 2\n");
	Lista_busca2(l, 0, &elem);
	printf("Pos[0] = [%d]\n", elem);
	Lista_busca2(l, 3, &elem);
	printf("Pos[3] = [%d]\n", elem);
	Lista_busca2(l, 2, &elem);
	printf("Pos[2] = [%d]\n", elem);

	int i = 10;
	i = Lista_contem(l, 100, &compara_int); 
 	printf("%d\n", i);

 	i = Lista_indice(l, 100, &compara_int);
 	printf("%d\n", i);

 	Lista_imprimir(l, &print_int);

 	printf("\n");

 	Lista_remove_elemento(l, 100, &compara_int);
 	Lista_imprimir(l, &print_int);

 	int j =lista_tamanho(l);
 	printf("tama[%d]\n", j);

return 0;
}