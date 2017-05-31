#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Tipo;

typedef struct no{
    Tipo* dado;
    struct no* prox;
}No;

typedef struct{
    No* topo;
    int qtde;
}Pilha;

Pilha* pilha_criar();
void pilha_desalocar(Pilha* p);
int pilha_inserir(Pilha* p, Tipo elemento);
Tipo* pilha_remover1(Pilha* p);
int pilha_remover2(Pilha* p, Tipo* endereco);
Tipo* pilha_topo(Pilha* p);
int pilha_tamanho(Pilha* p);
void pilha_imprimir(Pilha* p);
No* no_criar();

Pilha* pilha_criar(){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->qtde = 0;
	p->topo = NULL;
return p;
}

void pilha_desalocar(Pilha* p){
	while(p->topo){
		No* temp = p->topo;
		free(temp->dado);
		free(temp);
		p->topo = p->topo->prox;
	}
	free(p);
}

No* no_criar(Tipo elemento){
	No* n = (No*)malloc(sizeof(No));
	Tipo* d = (Tipo*)malloc(sizeof(Tipo));
	*d = elemento;  //note que: 'd' é um ponteiro e so recebe end. de memoria e que para receber 
					//um valor deve ser '*d' pois assim recebe no conteudo do mesmo o valor.
	n->dado = d;
	n->prox = NULL;
return n;
}

int pilha_inserir(Pilha* p, Tipo elemento){
	No* n = no_criar(elemento);
	n->prox = p->topo;
	p->topo = n;
	p->qtde++;
return 1;
}

Tipo* pilha_remover1(Pilha* p){
	if(p == NULL){return NULL;}
	Tipo* temp = (Tipo*)malloc(sizeof(Tipo));
	*temp = *p->topo->dado;
	No* n = (No*)malloc(sizeof(No));
	n = p->topo;
	p->topo = p->topo->prox;
	p->qtde--;
	free(n->dado);
	free(n);
return temp;
}

int pilha_remover2(Pilha* p, Tipo* endereco){
	if(p == NULL){return 0;}
	*endereco = *p->topo->dado;
	No* n = (No*)malloc(sizeof(No));
	n = p->topo;
	p->topo = p->topo->prox;
	free(n->dado);
	free(n);
return 1;
}

Tipo* pilha_topo(Pilha* p){
	if(p == NULL){return NULL;}
return (p->topo->dado);
}

int pilha_tamanho(Pilha* p){
	if(p == NULL){return 0;}
return (p->qtde);
}

void pilha_imprimir(Pilha* p){
	No* no = p->topo;
	while(no){
		printf("[%d]\n", *no->dado);
		no = no->prox;
	}
}