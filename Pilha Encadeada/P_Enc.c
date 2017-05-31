#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "P_Enc.h"

int main(){

	Tipo a1 = 10;
	Tipo a2 = 20;
	Tipo a3 = 30;
	Tipo a4 = 40;
	Tipo a5 = 50;

	Pilha* p = pilha_criar();
	
	pilha_inserir(p, a1);
	pilha_inserir(p, a2);
	pilha_inserir(p, a3);
	pilha_inserir(p, a4);
	pilha_inserir(p, a5);
	
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));

/*
	printf("Remoção 1");
	pilha_remover1(p);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));

	printf("Remoção 2");
	pilha_remover1(p);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));

	printf("Remoção 3");
	pilha_remover1(p);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));

	printf("Remoção 4");
	pilha_remover1(p);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));
*/

	Tipo temp;

	printf("Remoção 1");
	pilha_remover2(p, &temp);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));

	printf("Remoção 1");
	pilha_remover2(p, &temp);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));

	printf("Remoção 1");
	pilha_remover2(p, &temp);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));


	printf("Remoção 1");
	pilha_remover2(p, &temp);
	printf("#### Pilha Encadeada ####\n");
	pilha_imprimir(p);
	printf("Numero de Intens é: %d\n", pilha_tamanho(p));
	printf("O topo da Pilha é: [%d]\n", *pilha_topo(p));

	printf("#!# Pilha Desalocada #!#\n");
	pilha_desalocar(p);


return 0;
}