#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define strsize 20

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
	conteudo->prev = lista;
	conteudo->next = NULL;										//'conteudo->prev' recebendo o endereco anterior
	if(conteudo->prev != NULL){									//se 'conteudo->prev' for igual a NULL, entao a lista so tem 1 celula, caso contrario tem mais
		callback = conteudo->prev; 								//'callback' recebe o endereco do conteudo anterior, e entao...
		callback->next = conteudo;								//'callback' acessa o next do anterior e salva o endereço da celula atual
	}
	return conteudo;											//retornando celula atual 
}

void table(char nome[], double valor){
	int i = 0;
	while(i < 1){
		printf("+-------------------------------------------+\n");
		i++;
	}
	printf("|Nome:%-20s|Valor:R$%-9lg|\n", nome, valor);
	printf("+-------------------------------------------+\n");	
}

cell* search(cell* lista){
	cell* search = NULL;
	cell* reference = NULL;
	char nome[strsize];
	if(lista != NULL){
		do{
			printf("Nome para a pesquisa:");
			gets(nome);
		}while(strlen(nome)>strsize);	
		search = lista;			//Ultimo endereco
		while(search != NULL){
			if(0 == strcmp(search->data.nome, nome)){
				printf("Item eqncontrado!\n");
				table(search->data.nome, search->data.preco);
				reference = search;
				search = NULL;
				break;
			}
			search = search->prev;							
		}
	}
	return reference;
}

void modif(cell* lista){
	cell* conteudo;
	conteudo = search(lista);
		if(conteudo != NULL){
			do{
				printf("Novo nome:");
				gets(conteudo->data.nome);
			}while(strlen(conteudo->data.nome)>strsize);	
			printf("Novo valor:");	
			scanf("%lf", &conteudo->data.preco);
		}else
		printf("Valor nao encontrado\n");
}

void removeCell(cell* lista){
	cell* operator;
	cell* back_p, back_n;
	operator = search(lista);
	if(operator != NULL){
		if(operator->prev == NULL && operator->prev == NULL){
			 
		}
	
	}else
		printf("Valor nao encontrado\n");
	}

void menu(){
//	printf("+-------------------------------------------+\n");
	printf(":::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("|             Cadastro e modificacao        |\n");
	printf("|                  de  produto              |\n");
	printf(":::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("|\t\t\t[1] - Inserir                   |\n");
	printf("|\t\t\t[2] - Modificar                 |\n");
	printf("|\t\t\t[2] - Remover                   |\n");

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
		if(opc == 1)
			lista = insert(lista);
		if(opc == 2)
			modif(lista);
		if(opc == 3)
			removeCell(lista);		
	}
}
