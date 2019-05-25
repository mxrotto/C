#include <stdio.h>
#include <stdlib.h>

#define TRUE		1
#define FALSE		0

#define size		5

int verif(int tipo, int topo){				//verif(tipo da verificacao, indice da pilha)
	int response = FALSE;
	if(tipo == 1){					//Vetificacao se a pilha esta cheia
		if(topo < size)				//indice menor que tamanho
			response = TRUE;		//ainda eh possivel inserir
	}
	if(tipo == 2){					//Vetificacao se a pilha esta vazia
		if(topo >= 0)				//indice maior ou igual a 0 
			response = TRUE;		//ainda eh possivel remover ou listar
	}	
	return response;				//retorno da resposta  
}

void inserir(float pilha[], int *topo){
	if(verif(1, *topo) == TRUE){			//Vetificacao se a pilha esta cheia	
		(*topo)++;							
		printf("Pilha %d indice:", (*topo + 1));
		scanf("%f", &pilha[*topo]);
	}
	else{
		printf("Pilha cheia!\n");
		system("pause");
	}	
}

void remover(float pilha[], int *topo){
	if(verif(2, *topo) == TRUE){			//Vetificacao se a pilha tem conteudo
		(*topo)--;
		printf("Removido!\n");
	}else
	printf("Pilha vazia!\n");
	system("pause");		
}

void listar(float pilha[], int topo){
	int i;
	if(verif(2, topo) == TRUE){			//Vetificacao se a pilha tem conteudo
		for(i = 0;i <= topo;i++){
		printf("Valor:%g\n", pilha[i]);	
		}
	}else
	printf("Pilha vazia!\n");
	system("pause");		
}

void menu(){
	system("@cls||clear");
	printf(" _____________Pilha_____________\n");
	printf("|1 - inserir                    |\n");
	printf("|2 - remover                    |\n");
	printf("|3 - listar                     |\n");
	printf("|4 - sair                       |\n");
	printf("````````````````````````````````\n");
}

int main(){
	int option;
	float pilha[size];
	int top = -1, *topo = &top;
	while(!EXIT_SUCCESS){
		menu();
		printf("escolha:");
		scanf("%d", &option);
		getchar();	
		if(option == 1)
			inserir(pilha, topo);
		if(option == 2)
			remover(pilha, topo);
		if(option == 3)
			listar(pilha, *topo);
		if(option == 4)
			exit(EXIT_SUCCESS);
	}
}
