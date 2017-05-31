#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "F_E.h"

int main(){

	Fila* f = fila_criar();

	T a1 = 10;
	T a2 = 20;
	T a3 = 30;
	T a4 = 40;
	T a5 = 50;

	fila_inserir(f, a1);
	fila_inserir(f, a2);
	fila_inserir(f, a3);
	fila_inserir(f, a4);
	fila_inserir(f, a5);

	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));

/*
	printf("Remoção 1\n");
	printf("Removeu o Valor -[%d]-\n", *fila_remover1(f));
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));

	printf("Remoção 2\n");
	printf("Removeu o Valor -[%d]-\n", *fila_remover1(f));
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));

	printf("Remoção 3\n");
	printf("Removeu o Valor -[%d]-\n", *fila_remover1(f));
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));

	printf("Remoção 4\n");
	printf("Removeu o Valor -[%d]-\n", *fila_remover1(f));
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));
*/
	T temp;

	fila_remover2(f, &temp);
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));
	printf("Item Removido: [%d]\n", temp);

	fila_remover2(f, &temp);
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));
	printf("Item Removido: [%d]\n", temp);

	fila_remover2(f, &temp);
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));
	printf("Item Removido: [%d]\n", temp);

	fila_remover2(f, &temp);
	fila_imprimir(f);
	printf("Qantidade de itens: %d \n", fila_tamanho(f));
	printf("Primeiro Item: [%d]\n", *fila_primeiro(f));
	printf("Item Removido: [%d]\n", temp);


	fila_desalocar(f);

return 0;
}