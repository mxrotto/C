#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define linha printf("----------------------------------");
#define clearScreen system("@cls||clear");
#define pause system("pause");


void linhacoluna(int *l, int *c){
	printf("Informe o numero de linhas:");
	scanf("%d", l);
	printf("Informe o numero de colunas:");
	scanf("%d", c);
	getchar();			//limpeza buffer scanf
}

void code(int erro){
	if(erro == 1){
		printf("A matriz nao suporta essa escala!\n");
		printf("Execucao terminada\n");
	}
	if(erro == 2)
		printf("nenhum valor foi salvo ainda!\n");	
}

void menu(){
	clearScreen
	linha
	printf("\n(1)Inserir valores\n");
	printf("(2)Imprimir matriz\n");
	printf("(3)Limpar matriz\n");
	printf("(4)Sair\n");
	linha
}

void inserir(int **matriz, int linhas, int colunas, int *verif){
	int l, c;
	for(l = 0;l < linhas;l++){
		for(c = 0;c < colunas;c++){
			printf("valor[%d][%d]:", l+1, c+1);
			scanf("%d", &matriz[l][c]);
			*verif = 1;
		}	
	}
}		

void imprimir(int **matriz, int linhas, int colunas, int *verif){
	int l, c;
	if(*verif == 1){
		for(l = 0;l < linhas;l++){
			for(c = 0;c < colunas;c++){
				printf("M[%d][%d]:%d\t", l+1, c+1, matriz[l][c]);
			}
			printf("\n");
		}
	}
	else{	
		code(2);
	}	
	pause
}

void clean(int **matriz, int linhas, int colunas, int *verif){
	/*int l, c;
	for(l = 0;l < linhas;l++){
		for(c = 0;c < colunas;c++){
			free(&matriz[l][c]);
			printf("M[%d][%d] ", l+1, c+1);
			fflush(stdout);
			sleep(1);
		}
		printf("\n");
	}*/	
	free(matriz);
	printf("\nmatriz limpa!\n");
	*verif = 0;
	pause
}

int main(){
	int **matriz, linhas, colunas, esc, done=0, x;
	linhacoluna(&linhas, &colunas);		
		// Comeco alocacao
	matriz = (int **)malloc(linhas * sizeof(int));
	if(matriz == NULL){
		code(1);
		return 0;
	}
	for(x = 0;x < linhas;x++){
		matriz[x] = (int *)malloc(colunas * sizeof(int));
		if(matriz[x] == NULL){
			code(1);
			return 0;
		}	
	}
		//fim alocacao
 	while(1){
		menu();
		printf("\nEscolha:");
		scanf("%d", &esc);
		getchar();
		if(esc == 1)
			inserir(matriz, linhas, colunas, &done);
		if(esc == 2)
			imprimir(matriz, linhas, colunas, &done);
		if(esc == 3)
			clean(matriz, linhas, colunas, &done);
		if(esc == 4)
			return 0;	
		if(esc < 1 || esc > 5){
			printf("Escolha incoreta");
			sleep(2);
		}
	}	
}
