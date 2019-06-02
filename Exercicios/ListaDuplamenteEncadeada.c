#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define strsize 		20			//Tamanho maximo do nome



typedef struct {					//.DATA
	char nome[strsize];				//Nome do produto
	double preco;					//Preco do produto
}produto;

struct elemento {
	produto data;					//.DATA
	struct elemento* prev;				//Proximo link
	struct elemento* next;				//Link anterior
};

typedef struct elemento cell;

void head() {						//Cabecalho da "interface"													
	printf("--------------------------------------------\n\n");
	printf("%-11cCadastro e modificacao\n", ' ');
	printf("%-16cde produto\n\n", ' ');
	printf("--------------------------------------------\n\n");
}

cell* insert(cell* lista) {
	cell *callback = NULL;
	cell *conteudo = (cell*)malloc(sizeof(cell));			//Alocando a nova lista
	do {
		printf("nome:");
		scanf("%[^\n]s", &conteudo->data.nome);
	} while (strlen(conteudo->data.nome) > strsize);		//recomeca se conteudo 'conteudo->data.nome' for maior que tamanho maximo  	
	printf("preco:");
	scanf("%lf", &conteudo->data.preco);				//salvando o preco
	getchar();												                  //getchar() pra estancar qualquer erro no scanf (nao eh super efetivo)
	conteudo->prev = lista;
	conteudo->next = NULL;						//'conteudo->prev' recebendo o endereco anterior
	if (conteudo->prev != NULL) {					//se 'conteudo->prev' for igual a NULL, entao a lista so tem 1 celula, caso contrario tem mais
		callback = conteudo->prev; 				//'callback' recebe o endereco do conteudo anterior, e entao...
		callback->next = conteudo;				//'callback' acessa o next do anterior e salva o endereço da celula atual
	}
	return conteudo;										                 //retornando celula atual 
}

void table(char nome[], double valor) {						    //Tabela para mostrar dados
	printf("+-------------------------------------------+\n");
	printf("|Nome:%-20s|Valor:R$%-9lg|\n", nome, valor);
	printf("+-------------------------------------------+\n");
}

cell* search(cell* lista) {										        //Procedimento de procura
	cell* search = NULL;										            //<-
	cell* reference = NULL;										          //<- Ponteiros de procura e retorno recebem NULL
	char nome[strsize];											            //Array para a pesquisa
	if (lista != NULL) {											          //Se a lista nao estiver vazia
		do {													                    //<-
			printf("Nome para a pesquisa:");					      //<-
			scanf("%[^\n]s", &nome);
			getchar();											                //getchar() pra estancar qualquer erro no scanf
		} while (strlen(nome) > strsize);						      //<-Capturando o nome e testando se ele é maior que o tamanh maximo
		search = lista;											              //Ultimo endereco
		while (search != NULL) {								          //Enquanto o ultimo endereco for diferente de NULL				
			if (0 == strcmp(search->data.nome, nome)) {			//Testando se o nome capturado anteriormente é semelhante a algum ja salvo
				system("@cls||clear");
				head();											                  //Cabecalho da "interface"
				printf("Item encontrado!\n");
				table(search->data.nome, search->data.preco);	//Mostrando o item encontrado
				reference = search;								            //'reference' recebe o endereco da celula do item desejado
				search = NULL;									              //E 'search' recebe NULL, pois ja nao ha mais o que procurar
				break;											                  //Parando o while
			}
			search = search->prev;								          //Caminhando de tras pra frente nos links
		}
	}
	return reference;											              //Retornando NULL os se a lista esta vazia ou se a pesquisa nao encontrou resultados 
}

void procura(cell* lista) {										
	if (search(lista) == NULL) {
		printf("Lista vazia ou item nao encotrado!\n");
	}
	system("pause");
}

void modif(cell* lista) {									//Procedimento modificacao
	cell* conteudo;											//Ponteiro de troca
	conteudo = search(lista);								//Procedimento de procura, o o "argumento" 0 pois a msg "Lista vazia!" nao precisa ser mostrada
	if (conteudo != NULL) {									//Se o retorno 'reference' do Procedimento de procura é diferente de lista vazia e valor nao encontrado
		do {												//<-
			printf("Novo nome:");							//<-
			scanf("%[^\n]s", &conteudo->data.nome);			//<-
		} while (strlen(conteudo->data.nome) > strsize);	//<-Capturando o novo nome e testando se ele é maior que o tamanho maximo
		printf("Novo valor:");
		scanf("%lf", &conteudo->data.preco);				//Novo valor
		getchar();											//getchar() pra estancar qualquer erro no scanf
	}
	else {
		printf("Lista vazia ou item nao encotrado!\n");
		system("pause");
	}
}

void listar(cell* lista) {										//Procedimento listar
	cell* conteudo;												//Ponteiro 'conteudo' que caminha entre os links
	conteudo = lista;											//Ponteiro 'conteudo' recebe lista, o ultimo endereco
	if (conteudo != NULL) {										//Se a lista nao estiver vazia
		system("@cls||clear");
		head();													//Cabecalho da "interface"
		printf("+-------------------------------------------+\n");
		printf("%-4cLista de produtos\n", ' ');
		while (conteudo != NULL) {								//Enquanto 'conteudo' nao estiver vazio
			table(conteudo->data.nome, conteudo->data.preco);	//Tabela mostrando os dados salvos
			conteudo = conteudo->prev;							//Percorrendo a listado fim ao comeco
		}
	}
	else
		printf("Lista vazia!\n");
	system("pause");
}

cell* removeCell(cell* lista) {							//Procedimento remover
	cell* op;											//Ponteiro operador que vai testar condicoes
	cell* back_p;										//<-
	cell* back_n;										//<-Ponteiros de "backup"
	op = search(lista);								//Pesquisa
	if (op != NULL) {										//Se a pesquisa foiv bem sucedida
		if (op->prev == NULL && op->next == NULL) {		//apenas um item na lista
			free(lista);
			printf("Celula deletada.\n");
			lista = NULL;								//Reiniciando lista
		}
		if (op->prev == NULL && op->next != NULL) {		//Primeiro item da lista, se ja existem mais deles
			back_n = op->next;							//Back_n recebe o valor do proximo
			back_n->prev = NULL;						//E no proximo eu seto o anterior como NULL	
			free(op);									//Primeiro item da lista apagado
			printf("Celula deletada.\n");
		}
		if (op->prev != NULL && op->next == NULL) {		//Ultimo
			back_p = op->prev;							//<-
			back_p->next = NULL;						//<-
			free(op);									//<-Operacao contraria a do primeiro item da lista
			printf("Celula deletada.\n");
			lista = back_p;								//So que lista recebe o endereco da penultima celula 
		}
		if (op->prev != NULL && op->next != NULL) {		//Entre duas ou mais celulas
			back_p = op->prev;							//<-
			back_n = op->next;							//<-Salvando links da proxima e da anterior 
			back_p->next = back_n;						//Na celula anterior, o ponteiro "proximo" recebe o endereco da proxima 
			back_n->prev = back_p;						//Na celula proxima, o ponteiro "anterior" recebe o endereco anterior
			free(op);									//Entao o endereco entre eles eh livre
			printf("Celula deletada.\n");
		}
	}
	else
		printf("Lista vazia ou item nao encotrado!\n");
	system("pause");
	return lista;										//Retornando lista caso a ultima celula tenha sido apagada
}

void sair(cell* lista) {
	cell* dump;
	char opc;
	printf("Realmente quer sair? ([s] para sim)\n");
	scanf("%c", &opc);
	if (opc == 's' || opc == 'S') {
		if (lista != NULL) {
			printf("Apagando alocacoes...\n\n");
			while (lista->prev != NULL) {
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

void menu() {
	head();
	printf("%-7c[1] - Inserir\n", ' ');
	printf("%-7c[2] - Modificar\n", ' ');
	printf("%-7c[3] - Remover\n", ' ');
	printf("%-7c[4] - Listar produtos\n", ' ');
	printf("%-7c[5] - Buscar\n", ' ');
	printf("%-7c[6] - Sair\n\n", ' ');
}

int main() {
	cell* lista;
	int opc;
	lista = NULL;
	while (!EXIT_SUCCESS) {
		system("@cls||clear");
		menu();
		printf("escolha:");
		scanf("%d", &opc);
		getchar();
		if (opc == 1)
			lista = insert(lista);
		if (opc == 2)
			modif(lista);
		if (opc == 3)
			lista = removeCell(lista);
		if (opc == 4)
			listar(lista);
		if (opc == 5)
			procura(lista);
		if (opc == 6)
			sair(lista);
	}
}
