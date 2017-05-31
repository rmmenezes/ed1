#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef int T;

typedef struct no{
    T* dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int tam;
}Lista;


Lista* lista_cria();
void lista_insere(Lista* l, T elemento, int posicao);
void lista_insere_fim(Lista* l, T elemento);
T* lista_remove1(Lista* l, int posicao);
int lista_remove2(Lista* l, int posicao, T* endereco);
T* lista_remove_elemento(Lista* l, T elemento, int (*compara)(void*,void*));
T* lista_busca1(Lista* l, int posicao);
int lista_busca2(Lista* l, int posicao, T* endereco);
int lista_contem(Lista* l, T elemento, int (*compara)(void*,void*));
int lista_posicao(Lista* l, T elemento, int (*compara)(void*,void*));
int lista_tamanho(Lista* l);
void lista_imprime(Lista* l, int (*imprimeElemento)(void*));

Lista* lista_cria(){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	l->primeiro = NULL;
	l->ultimo = NULL;
	l->tam = 0;
return 0;
}

No* no_cria(T elemento){
	No* n = (No*)malloc(sizeof(No));
	*n->dado = elemento;
	n->prox = NULL;
	n->ant = NULL;
return n;
}

void lista_insere(Lista* l, T elemento, int posicao){
	no_cria(elemento);
}

void lista_insere_fim(Lista* l, T elemento){
	No* n = no_cria(elemento);
	if(l->primeiro == NULL){
		l->primeiro = n;
		l->ultimo = n;
		l->tam++;
	}
	else{
		l->ultimo->prox = n;
		n->ant = l->ultimo;
		l->ultimo = n;
		l->tam++;
	}
}


T* lista_remove1(Lista* l, int posicao){

}
int lista_remove2(Lista* l, int posicao, T* endereco);
T* lista_remove_elemento(Lista* l, T elemento, int (*compara)(void*,void*));
T* lista_busca1(Lista* l, int posicao);
int lista_busca2(Lista* l, int posicao, T* endereco);
int lista_contem(Lista* l, T elemento, int (*compara)(void*,void*));
int lista_posicao(Lista* l, T elemento, int (*compara)(void*,void*));
int lista_tamanho(Lista* l);
void lista_imprime(Lista* l, int (*imprimeElemento)(void*));

