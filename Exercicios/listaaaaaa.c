#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define strsize 30

typedef struct{
	char nome[strsize];
	double preco;	
 }produto;

struct elemento{
	produto data;
	struct elemento* prev;
	struct elemento* next;
};

typedef struct elemento cell;


cell* init(){
	return NULL;
}

cell* inserir(cell* lista){
	char nome[strsize];
	cell *callback = init();	
	cell *conteudo = (cell*)malloc(sizeof(cell));
	do{
		printf("nome:");
		gets(nome);
	}while(strlen(nome)>strsize);
	strcpy(conteudo->data.nome, nome);	
	printf("preco:");
	scanf("%lf", &conteudo->data.preco);
	conteudo->prev = lista;
	if(conteudo->prev != NULL){
		callback = conteudo->prev; 
		callback->next = conteudo;
		printf("%lf--%s--%p--%p--%p--%p\n", conteudo->data.preco, conteudo->data.nome, conteudo, conteudo->prev, callback, callback->next);
	}
	
	return conteudo; 
}	

void menu(){
	printf("/////////////////////////////////////////\n");
	printf("|[1] - inserir							|\n");
}

int main(){
	cell* lista;
	int opc;
	lista = init();
	while(!EXIT_SUCCESS){
		menu();
		printf("escolha:");
		scanf("%d", &opc);
		getchar();
		if(opc == 1){
			lista = inserir(lista);
		}
	}
}
