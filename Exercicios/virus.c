
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define strsize 30

typedef struct{
	char nome[strsize];
	double preco;	
 }produto;

typedef struct elemento{
	produto data;
	struct elemento* prev;
	struct elememto* next;
}cell;

//typedef struct elemento cell;

void freeP(cell *pointer){
	pointer = NULL;
	free(pointer);
}

cell* init(){
	return NULL;
}

cell* inserir(cell* lista){
	char nome[strsize];
	cell* callback;	
	int teste;
	cell* conteudo = (cell*)malloc(sizeof(cell));
	do{
		printf("nome:");
		gets(nome);
	}while(strlen(nome)>strsize);
	printf("preco:");
	scanf("%lf", &conteudo->data.preco);
	strcpy(conteudo->data.nome, nome);	
	conteudo->prev = lista;
	printf("%lf      %s     %p\n", conteudo->data.preco, conteudo->data.nome, conteudo->prev);
	/*if(conteudo->prev != NULL){
		callback = conteudo->prev; 
		memcpy(callback->next, conteudo, sizeof(cell));
		//printf("%p", callback->next);
		freeP(callback);
	}*/
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
