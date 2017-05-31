#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	struct No* prox;
	struct No* ant;		
}No;

typedef struct{ 
	No* prim;
	No* ult;
	int tam;
}Lista;

Lista* Lista_criar();
int Lista_inserir(Lista* l, int elem, int pos);
int Lista_inserir_fim(Lista* l, int elem);
int* Lista_remover1(Lista* l, int pos);
int Lista_remover2(Lista* l, int pos, int* elem);
int* Lista_busca1(Lista* l, int pos);
int Lista_busca2(Lista* l, int pos, int* end);
int Lista_contem(Lista* l, int elem, int(*compara)(void*, void*));
int Lista_indice(Lista* l, int elem, int(*compara)(void*, void*));
void Lista_imprimir(Lista* l, void(*print)(void*));
int* Lista_remove_elemento(Lista* l, int elem, int(*compara)(void*, void*));
int lista_tamanho(Lista* l);
No* cria_elemento(int elem);
int compara_int(void* a, void* b);
void print_int(void* a);

int compara_int(void* a, void* b){
	if(*((int*)a) == *((int*)b)){
		return 0;
	}else if(*((int*)a) > *((int*)b)){
		return 1;
	}else
		return -1;
}

int lista_tamanho(Lista* l){
	if(l == NULL) return 0;
	No* aux = l->prim;
	int i=0;
	while(aux){
		i++;
		aux = aux->prox;
	}
return i;
}

int* Lista_remove_elemento(Lista* l, int elem, int(*compara)(void*, void*)){
	if(l == NULL) return NULL;
	No* aux = l->prim;
	int i;
	for(i=0; i < l->tam-1; i++){
		if(compara(&elem, &aux->dado) == 0){
			return (Lista_remover1(l, i));
		}
	aux = aux->prox;
	}
return NULL;
}

void print_int(void* a){
	printf("[%d]\n", *(int*)a);
}

void Lista_imprimir(Lista* l, void(*print)(void* a)){
	No* aux = l->prim;
	int i=0;
	for(i=0; i < l->tam-1; i++){
		print(&aux->dado);
		aux = aux->prox;
	}

}


int Lista_indice(Lista* l, int elem, int(*compara)(void*, void*)){
	No* aux = l->prim;
	int i;
	for(i=0; i< l->tam-1; i++){
		if(compara(&aux->dado, &elem) == 0){
			return i;
		}
		aux = aux->prox;
	}
return -1;
}

int Lista_contem(Lista* l, int elem, int(*compara)(void*, void*)){
	if(l == NULL) return 0;
	No* aux = l->prim;
	int i=0;
	for(i=0; i < l->tam-1; i++){
		if(compara(&aux->dado, &elem) == 0){
			return 1;
		}
		aux = aux->prox;
	}
return 0;
}

Lista* Lista_criar(){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	l->prim = NULL;
	l->ult = NULL;
	l->tam = 0;
return l;
}

No* cria_elemento(int elem){
	No* e = (No*)malloc(sizeof(No));
	e->prox = NULL;
	e->ant = NULL;
	e->dado = elem;
return e;
}

int Lista_inserir(Lista* l, int elem, int pos){
	if(l == NULL) return 0;
	if(pos > l->tam || pos < 0)return 0;

	// if(pos > l->tam) pos = l->tam;
	// if(pos < 0) pos=0;

	if(l->prim == NULL){
		Lista_inserir_fim(l, elem);
	}else if(pos == 0){ //caso posiçao seja o inicio da lista
		No* e = cria_elemento(elem);
		e->prox = l->prim;
		l->prim->ant = e;
		l->prim = e;
		l->tam++;		
	} else if(pos == l->tam){ //caso posiçao seja fim da lista
		No* e = cria_elemento(elem);
		Lista_inserir_fim(l, elem);	
	} else{ //caso posição esteja no meio da lista
		No* e = cria_elemento(elem);
		No* aux = l->prim;
		int i=0;
		while(i < pos-1){
			aux = aux->prox;
			i++;
		}
		e->ant = aux;
		e->prox = aux->prox;
		aux->prox->ant = e;
		aux->prox = e;
		l->tam++;
	}
return 1;
}

int Lista_inserir_fim(Lista* l, int elem){
	if(l == NULL)return 0;

	No* e = cria_elemento(elem);
	if(l->prim == NULL){
		l->prim = e;
		
	}else{
		e->ant = l->ult;
		l->ult->prox = e;
			
	}
	l->ult = e;
	l->tam++;

return 1;
}

int* Lista_remover1(Lista* l, int pos){
	No* aux1 = l->prim;
	No* aux2 = l->prim->prox;		
	if(l == NULL){return 0;}		//LISTA NAO EXISTE
	if(l->prim ==  NULL){return 0;} //LISTA VAZIA
	if(pos >= l->tam){return 0;}	//POSIÇÃO INVALIDA
	
	if(l->tam == 1){				//LISTA COM APENAS 1 ITEM
		l->prim = NULL;
		l->tam--;
	return &(aux1->dado);
	} else if(pos == 0){
		l->prim = aux1->prox;
		l->prim->ant = NULL;
	return &(aux1->dado);
	} else if(pos == l->tam-1){		//removendo o ultimo
		aux1 = l->ult;
		aux1->ant->prox = NULL;
		l->ult = aux1;
	} else{							//LISTA COM MAIS DE 1 ITEM
		int i=0;	
		while(i < pos-1){
			aux1 = aux1->prox;
			aux2 = aux2->prox;
			i++;
		}
		aux1->prox = aux2->prox;
		aux2->prox->ant = aux1;
		l->tam--;
	}
return &(aux2->dado);
}

int Lista_remover2(Lista* l, int pos, int* elem){
	if(l == NULL) return 0;
	if(pos < 0 || pos > l->tam) return 0;
	No* aux1;
	No* aux2; 
	if(l->tam == 1){			//se so tiver um item
		*elem = l->prim->dado;
		l->prim = NULL;
		l->ult = NULL;
		l->tam--;
	}else if(pos == 0){			//se remoçao for a primeira
		aux1 = l->prim;
		aux2 = l->prim->prox;
		*elem = aux1->dado;
		l->prim = aux2;
		l->prim->ant = NULL;
		l->tam--;
	}else if(pos == l->tam-1){	//se remoçao for a ultima
		aux1 = l->ult;
		aux2 = l->ult->ant;
		*elem = aux1->dado;
		l->ult = aux2;
		l->ult->prox = NULL;
		l->tam--;
	}else {						//se remoçao for no meio
		aux1 = l->prim;
		int i=0;
		while(i<pos-1){
			aux2 = aux1;
			aux1 = aux1->prox;
			i++;
		}
	}
return 1;
}

int* Lista_busca1(Lista* l, int pos){
	if(l == NULL) return NULL;
	if(pos < 0 || pos >= l->tam) return NULL;
	No* aux = l->prim;
	int i = 0;
	while(i < pos-1){
		aux = aux->prox;
		i++;
	}
return &(aux->dado);
}


int Lista_busca2(Lista* l, int pos, int* end){
	if(l == NULL) return 0;
	if(pos < 0 || pos >= l->tam) return 0;
	No* aux = l->prim;
	int i = 0;
	while(i < pos-1){
		aux = aux->prox;
		i++;
	}
	*end = aux->dado;
return 1;
}



// int Lista_contem(Lista* l, int elem, int(*compara)(void*, void*)){
// 	if(l == NULL) return 0;
// 	int i=0;
// 	No* aux = l->prim;
// 	while(i < l->tam){
// 		if(compara(&aux->dado, &elem)){
// 			return 1;
// 		}
// 		aux = aux->prox;
// 		i++;
// 	}
// return 0;
// }
