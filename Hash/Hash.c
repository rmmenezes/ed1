#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hash.h"

int main(){

	Aluno a1;
	Aluno a2;
	Aluno a3;
	Aluno a4;
	Aluno a5;
	aluno_criar(&a1, 127, "Rafael Menezes");
	aluno_criar(&a2, 321, "Joao Carlos");
	aluno_criar(&a3, 454, "Suzani Aguiar");
	aluno_criar(&a4, 362, "David Santos");
	aluno_criar(&a5, 908, "Marcos Silveira");

	TabelaHash* t = tabela_criar();

	tabela_inserir(t, a1);
	tabela_inserir(t, a2);
	tabela_inserir(t, a3);
	tabela_inserir(t, a4);
	tabela_inserir(t, a5);

	tabela_imprimir(t);
	int i = tabela_buscar(t, a1);
	printf("%d\n", i);
	printf("#######################################################################\n");
	tabela_remover(t, a3);
	tabela_remover(t, a1);

	tabela_imprimir(t);

/*
*/

return 0;
}