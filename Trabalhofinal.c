
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define strsize 60

typedef struct {
	char nome[9];				//Nome da lista
	char **lista;				//Lista com os nomes		
	int size;					//Tamanho da lista	
}info;

struct elemento {
	info data;					//A listas com seus complementos	
	struct elemento* prev;		//Endereco do anterior
	struct elemento* next;		//Endereco do proximo
};

typedef struct elemento pkg;

char** listaAlloc(pkg *);
void menu();
void head();
void deleteNome(pkg *);	
void showPesquisa(pkg *);
pkg* openFile(pkg *, char );
pkg* insertValue(pkg *, char *);
pkg* search(pkg *, int *);
pkg* criaPkg(pkg *, char );
pkg* verifLista(pkg *, char *);


/*feof(ponteiro)
fgets(nome, tamanho, arquivo ponteuro)
*/

pkg* openFile(pkg *bloco, char mode){
	FILE *data;
	char nome[strsize];
	if(mode == '1')
		data = fopen("10nomes.txt", "r");
	if(mode == '2')
		data = fopen("100nomes.txt", "r");
	if(mode == '3')
		data = fopen("1000nomes.txt", "r");
	while(feof(data) == 0){
		fgets(nome, strsize, data);
		printf("a");
		bloco = insertValue(bloco, nome);	
	}
	fclose(data);	
	return bloco;
}

pkg* verifLista(pkg *block, char nome[]) {				//Procurando na lista
	pkg *referencia = NULL;
	pkg *pesquisa = block;
	while (pesquisa != NULL) {
		if (nome[0] == pesquisa->data.nome[0]) {		//Se o caracter for igual, a lista existe (nao necessarimemte a string) 
			referencia = pesquisa;
			break;
		}
		pesquisa = pesquisa->prev;
	}
	return referencia;									//So vai retonar algo se lista requisitada existe
}

pkg* criaPkg(pkg *bloco, char identif) {
	char nome[9] = { ' ', '_', 'i', 'n', 'd', 'i', 'c', 'e', '\0' };
	pkg *callback = NULL;
	pkg *conteudo = (pkg*)malloc(sizeof(pkg));
	nome[0] = identif;									//Letra de identificao
	strcpy(conteudo->data.nome, nome);
	conteudo->prev = bloco;
	conteudo->next = NULL;
	conteudo->data.size = 0;
	if (conteudo->prev != NULL) {						//se 'conteudo->prev' for igual a NULL, so existe 1 bloco, caso contrario existem mais
		callback = conteudo->prev; 						//'callback' recebe o endereco do conteudo anterior, e entao...
		callback->next = conteudo;						//'callback' acessa o next do anterior e salva o endereço da celula atual
	}
	return conteudo;
}

pkg* search(pkg *procura, int *linha){					//Funcao de pesquisa na matriz
	char nome[120];
	pkg *ref = procura;									//Ponteiro para manipulacao, sendo atribuido com o ultimo endereco ja na mesma linha
	if (ref != NULL) {									//se ref é null, nao ha o que procurar
		printf("Nome pra pesquisa:");			
		scanf("%[^\n]s", nome);
		ref = verifLista(ref, nome);					//Verificando se a lista existe, como nao ha uma padronizacao, nome com 'a' minusculos tem seu propio bloco, separado do 'A'
		if (ref != NULL) {
			for (*linha = 0; *linha <= ref->data.size; (*linha)++) {		//Varrendo a matriz atras de um nome igual
				if (strcmp(nome, ref->data.lista[(*linha)]) == 0) {
					printf("Nome encontrado!\n");
					break;
				}
				else
					printf("Nome nao encontrado!");
			}
		}
		else
			printf("Valor nao encontrado!");
	}
	else
		printf("Lista vazia!");
	return ref;
}

void showPesquisa(pkg *procura) {						//Funcao de mostrar o nome pesquisado
	int *linha = (int *)malloc(sizeof(int));			//alocando o ponteiro de referencia da linha da matriz				
	pkg *ref = procura;									
	ref = search(ref, linha);							//Pesquisando o nome
	if (ref != NULL) {									//se a pesquisa teve exito o retorno sera diferente de null
		printf("Nome:%s", ref->data.lista[*linha]);
	}
}

void deleteNome(pkg *procura) {							//Apagar elemento da matriz
	int *linha = (int *)malloc(sizeof(int));			//<--------------
	pkg *ref = procura;									//<--------------
	ref = search(ref, linha);							//<-------------- 
	if (ref != NULL) {									//<- Semelhante ao showPesquisa()
		while (*linha < ref->data.size) {
			strcpy(ref->data.lista[*linha], ref->data.lista[(*linha) + 1]);//Subistituicao de elementos da matriz
			//ref->data.lista[*linha] = ref->data.lista[(*linha) + 1];
			(*linha)++;
		}
		ref->data.size -= 1;							//elemento da matriz apagado
	}
}

char** listaAlloc(pkg *bloco) {
	if (bloco->data.lista == NULL) {									//Primeira alocacao						
		bloco->data.lista = (char **)malloc(sizeof(char));				//Linha							
		bloco->data.lista[0] = (char *)malloc(60 * sizeof(char));		//Coluna
	}
	else{	
		bloco->data.size++;
		bloco->data.lista = (char **)realloc(bloco->data.lista, sizeof(char));
		bloco->data.lista[bloco->data.size] = (char *)realloc(bloco->data.lista, strsize * sizeof(char));
	}
	return bloco->data.lista;
}

pkg* insertValue(pkg *bloco, char nome[]) {
	pkg* psq;											//psq de pesquisa
	pkg *retorno;
	psq = verifLista(bloco, nome);						//Verificando se ja existe um bloco com o indetificador (no caso, a letra)
	if (psq != NULL) {									//Se um endereco foi retornado...
		psq->data.lista = listaAlloc(psq);				//Alocando mais memoria a matriz
		strcpy(psq->data.lista[psq->data.size], nome);	//copiado nome
		//printf("Nome inserido!");
		retorno = bloco;
	}
	else {	
		printf("b");											//Se  o bloco nao existe ainda
		//printf("Criando lista....");
		psq = criaPkg(bloco, nome[0]);					//criando bloco com o seu indetificador 
		psq->data.lista = listaAlloc(psq);				//Alocando memoria a matriz
		strcpy(psq->data.lista[psq->data.size], nome);	//copiado nome
		//printf("Nome inserido!");
		retorno = psq;							
	}
	return retorno;		
}



/*Matriz com as linhas dinamicas, colunas fixas em 50 ou 60*/


void head(){												//Cabecalho da "interface"													
	printf("--------------------------------------------\n");
	printf("%-14cFile handlling\n", ' ');
	printf("--------------------------------------------\n\n");
}

void menu(){
	head();
	printf("%-7c[1] - Criar blocos\n", ' ');
	printf("%-7c[2] - Inserir nome\n", ' ');
	printf("%-7c[3] - Remover nome\n", ' ');
	printf("%-7c[4] - Buscar nome\n", ' ');
	printf("%-7c[5] - Ordenar tudo\n", ' ');
	printf("%-7c[6] - Ordenar bloco especifico\n", ' ');		
	printf("%-7c[7] - Mostrar blocos\n", ' ');
	printf("%-7c[8] - Gerar relatorio\n", ' ');
	printf("%-7c[9] - Sair\n\n", ' ');
	printf("--------------------------------------------\n\n");	
}

int main(){
	char op;
	pkg *bloco = NULL;
	while(!EXIT_SUCCESS){
		//system("@cls||clear");
		menu();
		printf("Escolha:");
		scanf("%c", &op);
		if(op == '1')
			openFile(bloco, '1');

		
		
	}


}


/*

pkg* insertValue(pkg *bloco) {
	pkg* psq;											//psq de pesquisa
	char nome[60];
	pkg *retorno;
	printf("Novo nome:");
	scanf("%[^\n]s", nome);
	psq = verifLista(bloco, nome);						//Verificando se ja existe um bloco com o indetificador (no caso, a letra)
	if (psq != NULL) {									//Se um endereco foi retornado...
		psq->data.lista = listaAlloc(psq);				//Alocando mais memoria a matriz
		strcpy(psq->data.lista[psq->data.size], nome);	//copiado nome
		printf("Nome inserido!");
		retorno = bloco;
	}
	else {												//Se  o bloco nao existe ainda
		printf("Criando lista....");
		psq = criaPkg(bloco, nome[0]);					//criando bloco com o seu indetificador 
		psq->data.lista = listaAlloc(psq);				//Alocando memoria a matriz
		strcpy(psq->data.lista[psq->data.size], nome);	//copiado nome
		printf("Nome inserido!");
		retorno = psq;
								
	}
	return retorno;		
}







cell* search(cell* lista, int p){								//Procedimento de procura
	cell* search = NULL;										//<-
	cell* reference = NULL;										//<- Ponteiros de procura e retorno recebem NULL
	char nome[strsize];											//Array para a pesquisa
	if(lista != NULL){											//Se a lista nao estiver vazia
		do{														//<-
			printf("Nome para a pesquisa:");					//<-
			gets(nome);											//<-
		}while(strlen(nome)>strsize);							//<-Capturando o nome e testando se ele é maior que o tamanh maximo
		search = lista;											//Ultimo endereco
		while(search != NULL){									//Enquanto o ultimo endereco for diferente de NULL
			if(0 == strcmp(search->data.nome, nome)){			//Testando se o nome capturado anteriormente é semelhante a algum ja salvo
				system("@cls||clear");
				head();											//Cabecalho da "interface"
				printf("Item encontrado!\n");
				table(search->data.nome, search->data.preco);	//Mostrando o item encontrado
				reference = search;								//'reference' recebe o endereco da celula do item desejado
				search = NULL;									//E 'search' recebe NULL, pois ja nao ha mais o que procurar
				if(p == 1)										//Se o procedimento search e chamado na opcao busca, a tabela aparece e nao some (explicacao a baixo)
					system("pause");
				break;											//Parando o while
			}
			search = search->prev;								//Caminhando de tras pra frente nos links
		}
	}else if(p == 1){											//Se o procedimento search e chamado na opcao busca, o aviso aparece e nao some (explicacao a baixo)
		printf("Lista vazia!\n");
		system("pause");
	}
	return reference;											//Retornando NULL os se a lista esta vazia ou se a pesquisa nao encontrou resultados
}
*/


