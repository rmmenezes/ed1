#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_HASH 12

typedef struct{
	long ra;
	char nome[30];	
}Aluno;

typedef struct no{
	Aluno dado;
	struct no* prox;
}No;

typedef struct{
	No** vetor;
	int tam;	
}TabelaHash;

TabelaHash* tabela_criar();
void tabela_inserir(TabelaHash* t, Aluno a);
int tabela_remover(TabelaHash* t, Aluno a);
int tabela_buscar(TabelaHash* t, Aluno a);
void aluno_criar(Aluno *a, long ra, char *nome);
int hash(Aluno a, int tam);
No* no_cria(Aluno a);


void aluno_criar(Aluno *a, long ra, char *nome){
	a->ra = ra;
	strcpy(a->nome, nome);
}

TabelaHash* tabela_criar(){
	TabelaHash* t = (TabelaHash*)malloc(sizeof(TabelaHash));
	t->tam = TAM_HASH;
	t->vetor = (No**)calloc(t->tam, sizeof(No*));
return t;
}

int hash(Aluno a, int tam){
return a.ra % tam;
}

No* no_cria(Aluno a){
	No* n = (No*)malloc(sizeof(No));
	n->dado = a;
	n->prox = NULL;
return n;
}

void tabela_inserir(TabelaHash* t, Aluno a){
	No* n = no_cria(a);
	int posi_hash = hash(a, t->tam);
	n->prox = t->vetor[posi_hash];
	t->vetor[posi_hash] = n;
}


void aluno_imprime(Aluno a){
	printf("------------\n");
	printf("Nome: %s\n", a.nome);
	printf("Ra: %ld\n", a.ra);
	printf("------------\n\n");
}


void tabela_imprimir(TabelaHash* t){
	int i;
	for(i=0; i < t->tam; i++){
		if(t->vetor[i] != NULL){
			No* aux = t->vetor[i];
			while(aux != NULL){
				aluno_imprime(aux->dado);
				aux = aux->prox;
			}
		}
	}
}


int tabela_remover(TabelaHash* t, Aluno a){
	int i;
	No* aux;
	No* aux2;
	for(i=0; i < t->tam; i++){
		if(t->vetor[i] != NULL){
			aux = t->vetor[i];	
			if(t->vetor[i]->dado.ra == a.ra){
				t->vetor[i] = t->vetor[i]->prox;
				free(aux);
			return 1;
			}
			while(aux->prox != NULL){
				if(aux->prox->dado.ra == a.ra){
					printf("Removeu\n");
					aux2 = aux->prox->prox;
					free(aux->prox);
					aux->prox = aux2;	
					aux = aux->prox;		
				return 1;
				}
			}
		}
	}
return 0;
}


int tabela_buscar(TabelaHash* t, Aluno a){
	int i;
	for(i=0; i < t->tam; i++){
		if(t->vetor[i] != NULL){
			No* aux = t->vetor[i];
			while(aux != NULL){
				if(aux->dado.ra == a.ra){
					return 1;
				}
				aux = aux->prox;
			}
		}
	}
return 0;
}

