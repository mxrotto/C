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


void head(){
	printf("--------------------------------------------\n\n");
	printf("%-11cCadastro e modificacao\n", ' ');
	printf("%-16cde produto\n\n", ' ');
	printf("--------------------------------------------\n\n");
}

cell* insert(cell* lista){
	char nome[strsize];
	cell *callback = NULL;									//Recebendo NULL
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
	printf("+-------------------------------------------+\n");
	printf("|Nome:%-20s|Valor:R$%-9lg|\n", nome, valor);
	printf("+-------------------------------------------+\n");	
}

cell* search(cell* lista, int p){
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
				system("@cls||clear");
				head();
				printf("Item encontrado!\n");
				table(search->data.nome, search->data.preco);
				reference = search;
				search = NULL;
					if(p == 1)
					system("pause");
				break;
			}
			search = search->prev;							
		}
	}
	return reference;
}

void modif(cell* lista){
	cell* conteudo;
	conteudo = search(lista, 0);
		if(conteudo != NULL){
			do{
				printf("Novo nome:");
				gets(conteudo->data.nome);
			}while(strlen(conteudo->data.nome)>strsize);	
			printf("Novo valor:");	
			scanf("%lf", &conteudo->data.preco);
		}
		else{
			printf("Valor nao encontrado\n");
			system("pause");
		}
}

void listar(cell* lista){
	cell* conteudo;
	conteudo = lista;
	if(conteudo != NULL){
		system("@cls||clear");
		head();
		printf("+-------------------------------------------+\n");
		printf("%-4cLista de produtos\n", ' ');
		while(conteudo != NULL){
			table(conteudo->data.nome, conteudo->data.preco);
			conteudo = conteudo->prev;
		}	
	}
	else{
		printf("lista vazia\n");
	}
	system("pause");
}

cell* removeCell(cell* lista){
	cell* op;
	cell* back_p;
	cell* back_n;
	op = search(lista, 0);
	if(op != NULL){
		if(op->prev == NULL && op->next == NULL){		//apenas um item na lista
			free(lista);
			printf("Celula deletada.\n");
			lista = NULL;
		}
		if(op->prev == NULL && op->next != NULL){		//Primeiro
			back_n = op->next;
			back_n->prev = NULL;
			free(op);	
			printf("Celula deletada.\n");
		}	
		if(op->prev != NULL && op->next == NULL){		//Ultimo
			back_p = op->prev;
			back_p->next = NULL;
			free(op);
			printf("Celula deletada.\n");
			lista = back_p;		
		}
		if(op->prev != NULL && op->next != NULL){		//entre duas ou mais celulas
			back_p = op->prev;
			back_n = op->next;
			back_p->next = back_n;
			back_n->prev = back_p;
			free(op);
			printf("Celula deletada.\n");		
		}			
	}else
		printf("Valor nao encontrado!\n");
	system("pause");
	return lista;
}

void sair(cell* lista){
	cell* dump;
	char opc;
	printf("Realmente quer sair? ([s] para sim)\n");
	scanf("%c", &opc);
	if(opc == 's' || opc == 'S'){
		if(lista != NULL){
			printf("Apagando alocacoes...\n\n");
			while(lista->prev != NULL){
				dump = lista;
				lista = lista->prev;
				free(dump);	
			}
			free(lista);
		}
		printf("saindo...\n");
		exit(EXIT_SUCCESS);
	}
}
	

void menu(){
	head();
	printf("%-7c[1] - Inserir\n", ' ');
	printf("%-7c[2] - Modificar\n", ' ');
	printf("%-7c[3] - Remover\n", ' ');
	printf("%-7c[4] - Listar produtos\n", ' ');
	printf("%-7c[5] - Buscar\n", ' ');
	printf("%-7c[6] - Sair\n\n", ' ');	
}

int main(){
	cell* lista;
	int opc;
	lista = NULL;
	while(!EXIT_SUCCESS){
		system("@cls||clear");
		menu();
		printf("escolha:");
		scanf("%d", &opc);
		getchar();
		if(opc == 1)
			lista = insert(lista);
		if(opc == 2)
			modif(lista);
		if(opc == 3)
			lista = removeCell(lista);	
		if(opc == 4)
			listar(lista);	
		if(opc == 5)
			search(lista, 1);
		if(opc == 6)
			sair(lista);
		if(opc < 1 || opc > 6){
			//nada	
		}
	}
}
