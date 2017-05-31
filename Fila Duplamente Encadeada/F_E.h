#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int T;

typedef struct no{
    T* dado;
    struct no* prox;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int qtde;
}Fila;

Fila* fila_criar();
void fila_desalocar(Fila* f);
int fila_inserir(Fila* f, T elemento);
T* fila_remover1(Fila* f);
int fila_remover2(Fila* f, T* endereco);
T* fila_primeiro(Fila* f);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, T elemento);
void fila_imprimir(Fila* f);
No* no_cria(T elemento);


Fila* fila_criar(){
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->primeiro = NULL;
	f->ultimo = NULL;
	f->qtde = 0;
return f;
}


void fila_desalocar(Fila* f){
	while(f->primeiro){
		No* temp = f->primeiro;
		f->primeiro = f->primeiro->prox;
		free(temp->dado);
		free(temp);	
	}
}

No* no_cria(T elemento){
	No* n = (No*)malloc(sizeof(No));
	T* t = (T*)malloc(sizeof(T));
	*t = elemento;
	n->dado = t;
	n->prox = NULL;
return n;
}

int fila_inserir(Fila* f, T elemento){
	if(f == NULL){return 0;}
	No* n = no_cria(elemento);
	n->prox = f->primeiro;
	f->primeiro = n;
	f->qtde++;
return 1;
}

T* fila_remover1(Fila* f){
	T* t = (T*)malloc(sizeof(T));
	No* n = f->primeiro; 
	*t = *f->primeiro->dado;
	f->primeiro = f->primeiro->prox;
	free(n->dado);
	free(n);
return t;
}

int fila_remover2(Fila* f, T* endereco){
	if(f == NULL){return 0;}
	*endereco = *f->primeiro->dado; //DUVIDA NESTA LINHA. NO CASO ESTAMOS PASSANDO UMA VARIAVEL 
	f->primeiro = f->primeiro->prox;//POR TANTO DEVE RECEBER UM VALOR E NAO UM ENDEREÇO DE MEMORIA.
	f->qtde--;
return 1;
}

T* fila_primeiro(Fila* f){
	if(f == NULL){return NULL;}
return f->primeiro->dado;
}

int fila_tamanho(Fila* f){
	if(f == NULL){return 0;}
return (f->qtde);
}

int fila_contem(Fila* f, T elemento);

void fila_imprimir(Fila* f){
	No* temp = f->primeiro;
	while(temp){
		printf("[%d]\n", *temp->dado);
		temp = temp->prox;
	}
}
