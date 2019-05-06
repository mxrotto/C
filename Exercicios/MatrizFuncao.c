#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void textMenu();
void inicializacao(int *, int *);
int ** allocator(int **, int , int , int *);
int** inserir(int **, int , int , int *);
void visualizar(int **, int , int , int );
void limpar(int **, int, int *);
int** realocar(int **, int *, int *, int *);
void menu(int **, int *, int *, int *);

int main(){
	int **matriz, linha, coluna, ativo;
	inicializacao(&linha, &coluna);
	matriz = allocator(matriz, linha, coluna, &ativo);
	menu(matriz, &linha, &coluna, &ativo);
}

void inicializacao(int *linha, int *coluna){
	*linha = 0;
	*coluna = 0;
	while(*linha == 0 || *coluna == 0){
		system("@cls||clear");
		printf("------------inicializacao-----------\n");
		printf("numero de linhas:");
		scanf("%d", linha);
		printf("numero de colunas:");
		scanf("%d", coluna);
		getchar();
		if(*linha == 0 || *coluna == 0){
			printf("Nenhum dos valores pode ser nulo!\n");
			sleep(2);
		}											
	}
}

int ** allocator(int **matriz, int linha, int coluna, int *ativo){
	int i; 											
	matriz = (int **)malloc(linha * sizeof(int));			//alocacao linha
	if(matriz == NULL || !matriz)
		printf("A alocacao com a linha nao foi bem sucedida");
	for(i = 0;i < linha;i++){
		matriz[i] = (int *)malloc(coluna * sizeof(int));	//alocacao coluna	
		if(matriz[i] == NULL || !matriz[i])
			printf("A alocacao com a linha nao foi bem sucedida");
	}
	*ativo = 1;	
	return matriz;	
}

int** inserir(int **matriz, int linha, int coluna, int *ativo){
	int l, c;
	if(*ativo >= 1){										//Se ja foi alocada, entao eh possivel inserir valores
		for(l = 0;l < linha;l++){
			for(c = 0;c < coluna;c++){
				printf("valor[%d][%d]:", l+1, c+1);
				scanf("%d", &matriz[l][c]);					//lendo valores			
			}	
		}
	*ativo = 2;												//a matriz foi preenchida
	}
	else{
		printf("Voce precisa antes alocar um espaco para a matriz\n");		//aviso, caso ela ainda nao tenha sido alocada
		system("pause");	
	}
	return matriz;
}

void visualizar(int **matriz, int linhas, int colunas, int verif){
	int l, c;
	if(verif == 2){											//se a matriz ja teve valores inseridos, entao eh possivel visualizar
		printf("-----------------------------------------\n");
		for(l = 0;l < linhas;l++){
			for(c = 0;c < colunas;c++){
				printf("M[%d][%d]:%-6d\t", l+1, c+1, matriz[l][c]);		//"Comecando" no M[1][1] pra ficar mais facil de visualizar, mas os os valores sao inseridos do 0
			}
			printf("\n");
		}
		printf("-----------------------------------------\n");
	}
	else
		printf("Voce precisa inserir valores na matriz antes\n");		//Aviso caso a matriz nao tenha sido preenchida
	system("pause");
}

void limpar(int **matriz, int linha, int *ativo){
	int i;
	if(*ativo != 0){										//Teste se a alocacao ja foi limpa
		free(matriz);										//liberando alocacao
		for(i = 0;i < linha;i++){
			free(matriz[i]);
		}
		*ativo = 0;											//A matriz esta limpa
		printf("\nMatriz limpa!\n");
	}
	else
		printf("A matriz ja foi limpa antes!\n");				//aviso que a matriz ja foi limpa
	system("pause");
}

int** realocar(int **matriz, int *linha, int *coluna, int *ativo){
	if(*ativo == 0){										//a realocacao so acontece se o espaco ja foi limpo
	inicializacao(linha, coluna);
	matriz = allocator(matriz, *linha, *coluna, ativo);
	}									//voltando ao estado inicial do programa
	else{
		printf("Apague a alocacao atual para criar uma nova!\n");
		system("pause");
	}	
	return matriz;
}

void menu(int **matriz, int *linha, int *coluna, int *ativo){
	int opc;
	while(!EXIT_SUCCESS){
		textMenu();											//"Interface" do menu
		printf("Escolha:");
		scanf("%d", &opc);
		getchar();											//Limpando buffer
		if(opc == 1)
			matriz = inserir(matriz, *linha, *coluna, ativo);
		if(opc == 2)
			visualizar(matriz, *linha, *coluna, *ativo);
		if(opc == 3)
			limpar(matriz, *linha, ativo);
		if(opc == 4)
			matriz = realocar(matriz, linha, coluna, ativo);
		if(opc == 5)
			exit(EXIT_SUCCESS);								//terminando a execucao
		if(opc < 1 || opc > 5){
			printf("\nEscolha incorreta!\n");
			system("pause");										
		}
	}
}

void textMenu(){											//opcoes pro menu
	system("@cls||clear");
	printf("1 - Inserir valores\n");
	printf("2 - Visualizar matriz\n");
	printf("3 - Apagar alocacao\n");
	printf("4 - Realocar espaco\n");
	printf("5 - Sair\n");
}
