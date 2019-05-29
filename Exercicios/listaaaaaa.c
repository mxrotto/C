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


cell* init(){			//retorna NULL
	return NULL;
}

cell* insert(cell* lista){
	char nome[strsize];
	cell *callback = init();									//Recebendo NULL
	cell *conteudo = (cell*)malloc(sizeof(cell));				//Alocando a nova lista
	do{
		printf("nome:");										
		gets(conteudo->data.nome);								//capturando o nome
	}while(strlen(conteudo->data.nome)>strsize);				//recomeca se conteudo 'conteudo->data.nome' for maior que tamanho maximo  	
	printf("preco:");
	scanf("%lf", &conteudo->data.preco);						//salvando o preco
	conteudo->prev = lista;										//'conteudo->prev' recebendo o endereco anterior
	if(conteudo->prev != NULL){									//se 'conteudo->prev' for igual a NULL, entao a lista so tem 1 celula, caso contrario tem mais
		callback = conteudo->prev; 								//'callback' recebe o endereco do conteudo anterior, e entao...
		callback->next = conteudo;								//'callback' acessa o next do anterior e salva o endereço da celula atual
	}
	return conteudo;											//retornando celula atual 
}	

void modif(cell* lista){
	cell* search;
	char nome[strsize];
	do{
		printf("Nome para a pesquisa:");
		gets(nome);
	}while(strlen(nome));
	search = lista;
	if(search == NULL){
		printf("lista vazia");	
	}
	else{
		while(search != NULL){
			if (nome == search->data.nome){
				printf("Objeto encontrado!\n\n");
					do{
						printf("Nome para a pesquisa:");
						gets(nome);
					}while(strlen(nome)>strsize);
					strcpy(search->data.nome, nome);
					//search->data.nome = nome;
					printf("valor:");
					scanf("%lf", search->data.preco);
			}
			else{
				printf("objeto nao encontrado!\n");
			}
			search = lista->prev;
		}
	}
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
			lista = insert(lista);
		}
		if(opc == 2){
			modif(lista);
		}
	}
}
