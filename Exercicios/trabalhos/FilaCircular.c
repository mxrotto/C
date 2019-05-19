/*\|>------------------------------------------------------<|\*/
/*\|				   Fila Circular						|\*/
/*\|				Diessy Soares oppata					|\*/
/*\|					RA: 2098318							|\*/
/*\|					-----------							|\*/
/*\|					Pablo Santos						|\*/
/*\|					RA: 2000113							|\*/
/*\|>------------------------------------------------------<|\*/

#include <stdio.h>
#include <stdlib.h>


#define TRUE		10										//<- 						
#define FALSE		5										//<- "codigos" de verificacao				
#define FULL		15										//<-  valores sem significado real	

#define size		3										//Tamanho da fila

void menu() {												//menu
	system("@cls||clear"	);
	printf("---------------Lista Circular---------------\n");
	printf("1 - Inserir\n"	);
	printf("2 - Remover\n"	);
	printf("3 - Listar\n"	);
	printf("4 - Sair\n"		);
}

int verif(int inicio, int fim, int opc, int overlap){		//Funcao de verificacao
	int response = FALSE;									//<- escolhesse um teste e a variavel 'response' fica em cargo de retornar uma reposta  
	if (opc == 1){											//Sub-rotina de verificacao inserir()
		if (fim == size)									//Se fim eh igual a tamanho maximo, entao
			response = FULL;								//<- A fila esta cheia
		if(overlap == TRUE){								//Caso o fim ja tenha recibido o valor 0
			if (fim == inicio)								//E ele seja semelhante a fim, entao
				response = FULL;							//<- A fila esta cheia
		}
	}
	if (opc == 2){											//Sub-rotina de verificacao listar() e remover()
		if ((inicio + fim) != 0 && inicio == fim)			//Se a lista nao esta na posicao inicia e incio e fim ocupam o mesmo indice
			response = TRUE;								//<- Lista vazia
	}
	if (opc == 3){											//Sub-rotina de verificacao reinicializacao do fim
		if (fim == size && inicio != 0)						//Se fim alcancou o valor maximo e inicio nao esteja no ponto inicial
			response = TRUE;								//<- Fim sera reiniciado
	}

	if (opc == 4) {											//sub-rotina de verificacao reinicializacao do inicio
		if (inicio == size && overlap == TRUE)				//Se inicio alcancou o valor maximo e fim ja tenha sido reinicializado
			response = TRUE;								//<- Inicio sera reiniciado	
	}
	return response;										//Retornando response 
}

void inserir(int inicio, int *fim, int fila[], int *overlap) {	//Funcao inserir
	if (verif(inicio, *fim, 3, 0) == TRUE) {				//Sub-rotina de verificacao reinicializacao do fim
		(*fim) = 0;											//<- Fim reiniciado
		(*overlap) = TRUE;									//Fim agora se encontra antes da variavel inicio
	}
	if (verif(inicio, *fim, 1, *overlap) != FULL){			//Sub-rotina de verificacao inserir()
		system("@cls||clear");									
		printf("Valor:");
		scanf_s("%d", &fila[*fim]);
		(*fim)++;											//<- O avance do indice fim
	}
	else{													//Caso a verif() retorne FULL
		printf("\nFila cheia!\n");
		system("pause");
	}
}

void remover(int *inicio, int fim, int fila[], int *overlap){	//Funcao remover
	if (verif(*inicio, fim, 4, *overlap) == TRUE) {			//Sub-rotina de verificacao reinicializacao do fim
		(*inicio) = 0;										//<- Inicio reiniciado
		(*overlap) = FALSE;									//Inicio agora se encontra antes da variavel fim
	}
	if (verif(*inicio, fim, 2, 0) != TRUE) {				//Sub-rotina de verificacao remover()
		(*inicio)++;										//<- O avance do indice inicio
		printf("\nEspaco na lista deletado....\n");
		system("pause");
	}
	else {													//Se verif() retornar TRUE, entao nao ha item para remover
		printf("\nFila esta vazia!\n");
		system("pause");
	}
}

void listar(int inicio, int fim, int fila[], int overlap) {		//Funcao listar
	int i;
	if (verif(inicio, fim, 2, 0) != TRUE) {					//Sub-rotina de verificacao reinicializacao do fim
		system("@cls||clear");
		if (overlap == FALSE) {								//Se inicio se encontra antes da variavel fim
			for (i = inicio; i < fim; i++) {
				printf("Valor:%d\n", fila[i]);
			}
		}
		if (overlap == TRUE) {								//Se fim se encontra antes da variavel inicio
			for (i = inicio; i < size; i++) {
				printf("Valor:%d\n", fila[i]);
			}
			for (i = 0; i < fim; i++) {
				printf("Valor:%d\n", fila[i]);
			}
		}
	}
	else {													//Se verif() retornar TRUE, entao nao ha item para mostrar
		printf("\nFila esta vazia!\n");
	}
	system("pause");
}

int main() {
	int opc, fila[size];									//variavel para armazenar a escolha, e um vetor para a lista
	int inicio = 0,	fim = 0, over = FALSE;					//inicio e fim iniciadas em 0, (over = FALSE) == estado inicial da fila
	int *begin = &inicio, *end = &fim, *overlap = &over;	//Declaracao e inicializacao dos ponteiros
	while (!EXIT_SUCCESS){
		menu();
		printf("Posicoes: incio:%d - fim:%d\n", inicio, fim);
		printf("escolha:");
		scanf_s("%d", &opc);
		if (opc == 1)
			inserir(inicio, end, fila, overlap);			//Ponteiro de fim (*end) e over (*overlap) pois eles poderam ser modificados
		if (opc == 2)
			remover(begin, fim, fila, overlap);				//Ponteiro de inicio (*begin) e over (*overlap) pois eles poderam ser modificados
		if (opc == 3)
			listar(inicio, fim, fila, over);				//Nao eh nessecario ponteiros
		if (opc == 4)
			exit(EXIT_SUCCESS);
	}
}
