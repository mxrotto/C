/* 		1. Carregar arquivo: Vai carregar na memória o conteúdo do arquivo.

		2. Inserir novo valor: Insere um novo valor na estrutura de armazenamento.
		
		3. Remover valor: Procura por um valor que será removido, caso exista.
		
		4. Buscar valor: Procura pelo valor na estrutura de armazenamento e
		imprime uma mensagem se o encontrou ou não. O método de busca
		deverá ser especificado.
		
		5. Ordenar valores: Ordena os valores da estrutura. O método de
		ordenação deverá ser especificado.
		
		6. Imprimir valores: Imprime todos os valores da estrutura.
		
		7. Gerar relatório: Gera um relatório da execução das operações do
		programa (mais detalhes abaixo).
		
		8. Sair do programa: Ao sair, a estrutura deve ser liberada da memória e o
		programa encerrado.
		
*/

/*		----------------------------------------------------------------------------------------

						*****Carregar arquivo*****									
																								
			Lista encadeada com matrizes dinamicas para a alocacao dos nomes, cada nome é salvo		
		em um ventor durante a criacao da lista, se o nome comeca com a letra 'A' entao ele	é		
		inserido na lista indice_A dentro da matriz indice_A, junto com um ponteiro que salvo		
		o indice de linhas, dois ponteiro apontado para o proximo e para o anterior, e o nome da 	
		lista, sendo indice_A ou indice_B e assim por diante.	
											
		----------------------------------------------------------------------------------------
		----------------------------------------------------------------------------------------
							
						*****Inserir novo valor*****
								
			O valor inserido eh salvo em um vetor, o primeiro caracter é verificado, e entao apos 
		a verificacao, ele é inserido na sua respctiva lista, precisamente na ultima linha da 
		matriz, se o elemento na lista nao existe, entao é criada uma lista pra ele, onde futuros 
		nomes com o mesmo caracter poderam ser incluidos.  
		
		----------------------------------------------------------------------------------------
		----------------------------------------------------------------------------------------
		
						*****Remover valor*****

			O valor inserido eh salvo em um vetor, se o caracter veficado nao consta em nenhum 
		nome da lista, certamente o valor nao existe, se foi possivel encontrar, entao é feita a
		busca, a matriz da respctiva letra é varrida, talvez uma variavel global salve o status
		da ordencao, se foi feita ou nao, ai pode se usar o bubble sort com o strcmp, caso 
		contraio a busca pode ser sequencial ou usando shell sort, mas so na matriz respctiva.
		
		----------------------------------------------------------------------------------------
		----------------------------------------------------------------------------------------
		
						*****Buscar valor*****
		
			Buscar tem semelhanca com o remover, o valor inserido eh salvo em um vetor, se o 
		caracter veficado nao consta em nenhum nome da lista, certamente o valor nao existe,
		remover e buscar podem ter a mesma funcao "busca();" so que uma apagado o retorno da
		lista com o indice, e outro mostra.
		
		----------------------------------------------------------------------------------------
		----------------------------------------------------------------------------------------									
									
						*****Ordenar valores*****
										
			Ordenar a lista (indice_A, indice_B), logo apos ordenar a matriz de cada um usando 
		bubble sort com o strcmp e outro metodo de ordenacao, o shell ou heap, caso eu use a 
		variavel global, posso usar ela pra verificar qual metodo eu uso na busca.
		
		----------------------------------------------------------------------------------------
		----------------------------------------------------------------------------------------
									
						*****Imprimir valores*****
									
			Imprimir valores fica dependete de ordenar, nao necessariamente ele nao funcione sem
		o ordenar, mas a impressao seria parcialmente ordenada, por letras, so que em ordem 
		aleatoria, {lista: L, C, A, U}  que vai depender dos nomes das listas, mas os nomes iriao
		estar nas suas listas, a impressao pode se parece com....
													
				Indice_A
					L Ana Julina
					L Ana Marcela
											
				Indice_B
					L Bruno Almeida
					L Bruno Zesmiack
											
				Indice_C
					L Carlos Bruno
					L Cristian Santos	
							(se ja ordenado)
																	
		----------------------------------------------------------------------------------------
		----------------------------------------------------------------------------------------																
										
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char nome[6];				//Nome da lista
	char **lista;				//Lista com os nomes		
	int size;					//Tamanho da lista	
}data;		
		
struct elemento{
	data lista;					//A listas com seus complementos	
	struct elemento* prev;		//Endereco do anterior
	struct elemento* next;		//Endereco do proximo
};

typedef struct elemento lista;

lista* verifLista(lista *block, char nome[]){			//Procurando na lista
	lista *referencia = NULL;
	lista *pesquisa = block;						
	while(pesquisa != NULL){
		if(nome[0] == pesquisa->lista.nome[0]){	//Se o caracter for igual, a lista existe (nao necessarimemte a string) 
			referencia = pesquisa;
			break;								
		}	
		pesquisa = pesquisa->prev;				
	}
	return referencia;									//So vai retonar algo se lista requisitada existe
}

lista* search(lista *procura, int *linha){
	char nome[120];
	lista *ref = procura;
	if(ref != NULL){
		printf("Nome pra pesquisa:");
		scanf("%[^\n]s", nome);
		ref = verifLista(ref, nome);
		if(ref != NULL){
			for(*linha = 0;*linha <= ref->lista.size;(*linha)++){
				if(strcmp(nome, ref->lista.lista[*linha]) == 0){
					printf("Nome encontrado!\n");
					break;				
				}else
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

void showPesquisa(lista *procura){
	int *linha;
	linha = (int *) malloc(sizeof(int));
	lista *ref = procura;
	ref = search(ref, linha);
		if(ref != NULL){
			printf("Nome:%s", ref->lista.lista[*linha]);
		}			
}	

void deleteNome(lista *procura){
	int *linha;
	linha = (int *) malloc(sizeof(int));
	lista *ref = procura;
	ref = search(ref, linha);
	if(ref != NULL){
		while(*linha <= ref->lista.size){
			ref->lista.lista[*linha] = ref->lista.lista[(*linha)+1];
			(*linha)++;	
		}
		ref->lista.size -= 1;
	}	
}

void matrizAlloc(lista *block){
	int i;  											//pointer to pointer
	matriz = (int **)malloc(linha * sizeof(int));			//alocacao linha
	if(matriz == NULL || !matriz)
		printf("A alocacao com a linha nao foi bem sucedida");
	for(i = 0;i < linha;i++){
		matriz[i] = (int *)malloc(coluna * sizeof(int));	//alocacao coluna	
		if(matriz[i] == NULL || !matriz[i])
			printf("A alocacao com a linha nao foi bem sucedida");
	}												//Valor de verificacao de alocacao
					//Enviando a matriz alocada ao "menu principal"
}

/*Matriz com as linhas dinamicas, colunas fixas em 50 ou 60*/


int main(){	
	lista *block;
		
		
}


/*cell* search(cell* lista, int p){								//Procedimento de procura
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



				
					
