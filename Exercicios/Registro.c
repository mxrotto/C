#include <stdio.h>
#include <stdlib.h>

#define size 40
#define linha printf("\n-------------------------------");


typedef struct{
 	char nome[40];
 	char data[40];
 	char estdCivil[40];	
}registro;

void menu(){
	printf("1 - Cadastrar");	
	printf("\n2 - Remover");
	printf("\n3 - Listar");	
	printf("\n4 - Exit");
}

void cadastro(registro *person, int *i, int *id){
	*id++;
	printf("Informe o nome:");
    gets(person->nome + *i);
   // getchar();		//buffer clean
    printf("data:");
    gets(person->data + *i);
    //getchar();				//buffer clean
    printf("Informe o estado civil:");
    gets(person->estdCivil + *i);
    //getchar();				//buffer clean
    *i += size;
}


void remover(registro *person, int *i, int *id){
	
}


void listar(registro *person, int *id){
	int x, temp = 0;
		for(x = 0;x <= *id;x++){
			printf("\nNome:%s", person->nome + temp);
			printf("\nData Nascimento:%s", person->data + temp);
			printf("\nEstado Civil:%s", person->estdCivil + temp);
			temp += size;
			linha
		}	
}

int main(){
	int esc, indice =0 , id = 0;
	registro *reg;
	reg = (registro *) malloc(40 * sizeof(registro));
	while(1){
		system("clear");
		menu();
		printf("\nEscolha:");
		scanf("%d", &esc);
		getchar();
		if(esc == 1){
			cadastro(reg, &indice, &id);
		}
		if(esc == 2){
			//remover(reg, &indice, &id);
		}
		if(esc == 3){
			listar(reg, &id);
			printf("\n");
			system("pause");
		}
		if(esc == 4){
			printf("Saindo...");
			return 0;
		}
		if(esc < 1 || esc > 5){
			printf("Escolha incoreta");
		}
	}	
	/*registro *reg;*/	

}
