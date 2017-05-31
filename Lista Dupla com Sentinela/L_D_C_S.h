#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int T;

typedef struct no{
    T* dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* primeiro;
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
int compara_t(void* a, void* b);
int lista_contem(Lista* l, T elemento, int (*compara)(void*,void*));
int lista_posicao(Lista* l, T elemento, int (*compara)(void*,void*));

int lista_tamanho(Lista* l);
void lista_imprime(Lista* l, int (*imprimeElemento)(void*));
No* no_cria(T elemento);
int imprime_t(void* a);

Lista* lista_cria(){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	No* sent = (No*)malloc(sizeof(No));
	l->primeiro = sent;
	l->tam = 0;
	sent->prox = sent;
	sent->ant = sent;
return l;
}

void lista_insere(Lista* l, T elemento, int posicao){
	if(posicao >= l->tam){ 
		posicao = l->tam-1;
	}else if(posicao < 0){
		posicao = 0;
	}

	No* aux1 = l->primeiro;
	No* aux2;
	No* n = no_cria(elemento);
	int i=0;

	while(i <= posicao){
		aux2 = aux1;
		aux1 = aux1->prox;
		i++;
	}
	
	n->ant = aux2;
	n->prox = aux1;
	aux2->prox = n;
	aux1->ant = n;
	l->tam++;
}

void lista_insere_fim(Lista* l, T elemento){
	No* n = no_cria(elemento);
	No* aux = l->primeiro->ant;
	aux->prox = n;
	n->ant = aux;
	l->primeiro->ant = n;
	n->prox = l->primeiro;
	l->tam++;
}

No* no_cria(T elemento){
	No* n = (No*)malloc(sizeof(No));
	T* elem = (T*)malloc(sizeof(T));
	*elem = elemento;
	n->prox = NULL;
	n->ant = NULL;
	n->dado = elem;
return n;
}

void lista_imprime(Lista* l, int(*imprimeElemento)(void* a)){
	No* aux = l->primeiro->prox;
	while(aux != l->primeiro){	
		imprime_t(aux->dado);
		aux = aux->prox;
	}
}

int imprime_t(void* a){
	printf("[%d]\n", *(int*)a);
return 0;
}

T* lista_busca1(Lista* l, int posicao){
	if(l == NULL) return NULL;
	if(posicao >= l->tam){ 
		posicao = l->tam-1;
	}else if(posicao < 0){
		posicao = 0;
	}

	No* aux = l->primeiro->prox;
	int i=0;
	while(i < posicao){
		aux = aux->prox;
		i++;
	}
return (aux->dado);
}

int lista_busca2(Lista* l, int posicao, T* endereco){
	if(l == NULL) return 0;
	if(posicao >= l->tam){ 
		posicao = l->tam-1;
	}else if(posicao < 0){
		posicao = 0;
	}

	No* aux = l->primeiro->prox;
	int i=0;
	while(i < posicao){
		aux = aux->prox;
		i++;
	}
	*endereco = *aux->dado;
return 1;
}

int compara_t(void* a, void* b){
	if(*(int*)a == *(int*)b){return 0;}
	if(*(int*)a < *(int*)b){return -1;}
	if(*(int*)a > *(int*)b){return 1;}
}

int lista_contem(Lista* l, T elemento, int (*compara)(void*,void*)){
	if(l == NULL) return 0;
	int i=-1;
	No* aux = l->primeiro->prox;
	while(aux != l->primeiro){
		if(compara(&elemento, aux->dado) == 0){
			return 1;
		}
		i++;
		aux = aux->prox;
	}
return 0;
}

int lista_posicao(Lista* l, T elemento, int (*compara)(void*,void*)){
	if(l == NULL) return -1;
	int i=-1;
	No* aux = l->primeiro->prox;
	while(aux != l->primeiro){
		if(compara(&elemento, aux->dado) == 0){
			return i+1;
		}
		i++;
		aux = aux->prox;
	}
return -1;
}

int lista_tamanho(Lista* l){
	if(l == NULL) return -1;
	else
		return l->tam;
}

T* lista_remove1(Lista* l, int posicao){
	if(l == NULL) return NULL;
	if(posicao >= l->tam){ 
		posicao = l->tam-1;
	}else if(posicao < 0){
		posicao = 0;
	}

	No* aux1 = l->primeiro;
	No* aux2;
	int i=0;
	while(i <= posicao){
		aux2 = aux1;
		aux1 = aux1->prox;
		i++;
	}

	aux1->prox->ant = aux2;
	aux2->prox = aux1->prox;

return (aux1->dado);
}

int lista_remove2(Lista* l, int posicao, T* endereco){
	if(l == NULL) return 0;
	if(posicao >= l->tam){ 
		posicao = l->tam-1;
	}else if(posicao < 0){
		posicao = 0;
	}

	No* aux1 = l->primeiro;
	No* aux2;
	int i=0;
	while(i <= posicao){
		aux2 = aux1;
		aux1 = aux1->prox;
		i++;
	}

	aux1->prox->ant = aux2;
	aux2->prox = aux1->prox;
	*endereco = *aux1->dado;
return 1;
}