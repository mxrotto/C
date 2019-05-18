/*\>-----------------------------------------------------------------------<\*/
/*\								Fila Circular								\*/
/*\							Diessy Soares oppata							\*/
/*\								RA: 2098318									\*/
/*\>-----------------------------------------------------------------------<\*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE		10											//						
#define FALSE		5											//"codigos" de verificacao		(valores sem significado real)		
#define FULL		15											//	

#define size		3											//Tamanho da fila

void menu() {
	system("@cls||clear");
	printf("========================Lista Circular========================\n");
	printf("1 - Inserir\n");
	printf("2 - Remover\n");
	printf("3 - Listar\n");
	printf("4 - Sair\n"	);
}

int verif(int inicio, int fim, int opc, int overlap){
	int response = FALSE;
	if (opc == 1){												//sub-rotina de verificacao inserir()
		if (fim == size && (inicio + fim) != 0) {
			response = FULL;
		}
		if(overlap == TRUE){
			if (fim == inicio) 
				response = FULL;
		}
	}
	if (opc == 2){												//sub-rotina de verificacao listar() e remover()
		if ((inicio + fim) != 0)
			response = TRUE;
		if (overlap == FALSE){
			if (inicio != fim)
				response = TRUE;
		}
	}
	if (opc == 3){												//sub-rotina de verificacao reinicializacao do fim
		if (fim == size && inicio != 0)
			response = TRUE;
	}

	if (opc == 4) {												//sub-rotina de verificacao reinicializacao do inicio
		if (inicio == size && fim != 0) 
			response = TRUE;
	}
	return response;
}

void inserir(int inicio, int *fim, int fila[], int *overlap) {
	if (verif(inicio, *fim, 3, 0) == TRUE) {						//sub-rotina de verificacao reinicializacao do fim
		(*fim) = 0;
		(*overlap) = TRUE;
	}
	if (verif(inicio, *fim, 1, *overlap) != FULL){						//sub-rotina de verificacao inserir()
		system("@cls||clear");
		printf("Valor:");
		scanf_s("%d", &fila[*fim]);
		(*fim)++;
	}
	else{
		printf("\nFila cheia!\n");
		system("pause");
	}
}

void remover(int *inicio, int fim, int fila[], int *overlap){
	if (verif(*inicio, fim, 4, 0) == TRUE) {						//sub-rotina de verificacao reinicializacao do fim
		(*inicio) = 0;
		(*overlap) = FALSE;
	}
	if (verif(*inicio, fim, 2, 0) == TRUE) {						//sub-rotina de verificacao remover()
		(*inicio)++;
		printf("\nEspaco na lista deletado....\n");
		system("pause");
	}
	else {
		printf("\nFila esta vazia!\n");
		system("pause");
	}
}

void listar(int inicio, int fim, int fila[], int overlap) {
	int i;
	if (verif(inicio, fim, 2, 0) == TRUE) {
		system("@cls||clear");
		if (overlap == FALSE) {
			for (i = inicio; i < fim; i++) {
				printf("Valor:%d\n", fila[i]);
			}
		}
		if (overlap == TRUE) {
			for (i = inicio; i < size; i++) {
				printf("Valor:%d\n", fila[i]);
			}
			for (i = 0; i < fim; i++) {
				printf("Valor:%d\n", fila[i]);
			}
		}
	}
	else {
		printf("\nFila esta vazia!\n");
	}
	system("pause");
}


int main() {
	int over = FALSE;
	int opc;										
	int inicio = 0,	fim = 0, fila[size];						//inicio e fim iniciadas em 0		
	int *in = &inicio,	*fi = &fim, *overlap = &over;			//ponteiro
	while (!EXIT_SUCCESS){
		menu();
		printf("Manual debugger:%d-%d\n", inicio, fim);
		printf("escolha:");
		scanf_s("%d", &opc);
		if (opc == 1)
			inserir(inicio, fi, fila, overlap);
		if (opc == 2)
			remover(in, fim, fila, overlap);
		if (opc == 3)
			listar(inicio, fim, fila, over);
		if (opc == 4)
			exit(EXIT_SUCCESS);
	}
}