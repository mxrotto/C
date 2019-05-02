#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
 	char nome[40], telefone[15];
 }CONTATO;

 char* spaceSolve(char text[], int way){
    int i, tam;
    tam = strlen(text);
    if(way == 1){                           //troca de caracters
        for (i = 0; i < tam;i++){
            if (text[i] == ' '){
                text[i] = '$';
            }
        }
    }
    if(way == 2){                           //troca de caracters inversa
        for (i = 0; i < tam;i++){
            if (text[i] == '$'){
                text[i] = ' ';
            }
        }
    }
    return text;
 }

void inserir(FILE *reg){
	CONTATO registro;
	do{												                         //enquanto os valores forem nulos
		printf("Nome:");
		gets(registro.nome);
		strcpy(registro.nome, spaceSolve(registro.nome, 1));                //tentado resolver o problema do !feof(reg) de ler espacos
		printf("Telefone:");
		gets(registro.telefone);
		strcpy(registro.telefone, spaceSolve(registro.telefone, 1));        //tentado resolver o problema do !feof(reg) de ler espacos
		if(!*registro.nome||!*registro.telefone){	                        //se os valores forem nulos
			system("@cls||clear");
			printf("Os registros nao podem ser nulos!\n");
		}
	}while(!*registro.nome||!*registro.telefone);	                        //enquanto os valores forem nulos
                                                                            // \/Manipulacao de arquivo\/
	reg = fopen("agenda.txt", "a");
	if(reg != NULL)
		fprintf(reg, "Nome:%s\tTelefone:%s\n", registro.nome, registro.telefone);
	else{
		printf(".........Erro ao acessar ou criar o arquivo.........\n");
		system("pause");
	}
	fclose(reg);                                                            //fechando arquivo
}

void listar(FILE *reg){
    CONTATO registro;
                                                                    //\/Manipulacao de arquivo\/
	reg = fopen("agenda.txt", "r");
	if(reg != NULL){				                                //testando se foi possivel abrir o arquivo
            printf("----------------------Contatos----------------------\n");
		while(!feof(reg)){		                                    //impressao de todas os dados salvos no txt
			fscanf(reg, "Nome:%s\tTelefone:%s\n", registro.nome, registro.telefone);
			strcpy(registro.nome, spaceSolve(registro.nome, 2));
			strcpy(registro.telefone, spaceSolve(registro.telefone, 2));
			printf("Nome:%-28sTelefone:%s\t\n\n", registro.nome, registro.telefone);
		}
    printf("----------------------------------------------------\n");
		fclose(reg);				                                //fechando arquivo
	}
	else
		printf("O Arquivo nao existe ou nao foi possivel abrir\n");
	system("pause");
}

void limpar(FILE *reg){
	if(remove("agenda.txt") == 0)				//apagando o arquivo dentro do if, se o retorno for 0 a opercao foi bem sucedida
		printf("Registro deletado!\n");
	else
		printf("O arquivo ja nao existe!\n");	//Se o retorno for diferente de 0 o arquivo nao existe ou ele tem protecao contra modificacao
	system("pause");
}

void menu(FILE *reg){
	int opc;
	while(!EXIT_SUCCESS){
		system("@cls||clear");
		printf("[1]-Inserir\n");
		printf("[2]-Listar\n");
		printf("[3]-Apagar registro\n");
		printf("[4]-Sair\n");
		printf("Escolha:");
		scanf("%d", &opc);
		getchar();								//Limpeza buffer
		if(opc == 1)
			inserir(reg);
		if(opc == 2)
			listar(reg);
		if(opc == 3)
			limpar(reg);
		if(opc == 4)
			exit(EXIT_SUCCESS);
		if(opc < 1 || opc > 4){
			printf("Escolha incorreta!\n");
			getchar();							//Por alguma razao o Enter vem ate aqui
			system("pause");
		}
	}
}

int main(){
	FILE *reg;
	menu(reg);
}
