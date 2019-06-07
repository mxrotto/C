#include <stdio.h>
#include <stdlib.h>
#include <string.h.>

#define TAM 81

typedef struct {
    char nome[TAM];
    float valor_hora;
    int horas_mes;
}Funcionario;

void inserirFuncionario(Funcionario *funcionario, int qtd){
    int i;
    FILE *lista;
    lista = fopen("lista.txt", "r");
    for (i = 0; i < qtd; i++) {
        fscanf(lista, "%s\n", funcionario[i].nome);
    }
}

void imprimirLista(Funcionario *funcionario, int qtd){
    int i;
    system("@cls||clear");
    printf("\n");
    printf("[Lista Nomes]\n");
    for (i = 0; i < qtd; i++) {
    
        printf("%d - %s\n", i+1, funcionario[i].nome);
    }
    printf("\n");
    system("pause");
}

int busca_bin(Funcionario *funcionario, int qtd){
    int inicio = 0, meio, fim = qtd-1;
    char nome[TAM];
    system("@cls||clear");
    printf("\n");
    printf("\t    [Buscar Nome]\n");
    printf("\n");
    printf(" Informe o nome: ");
    scanf("%s", &nome);
    fflush(stdin);

    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if(strcmp(nome, funcionario[meio].nome) < 0){
            fim = meio - 1;
        } else if(strcmp(nome, funcionario[meio].nome) > 0){
            inicio = meio + 1;
        } else {
            return meio;
        }
    }
    return -1;
}

void head(){
	printf("-----------------------------------------\n");
	printf("%-13cBUSCA BINARIA\n", ' ');
	printf("-----------------------------------------\n");
}

char menu(){
    char op;
    system("@cls||clear");
    head();
    printf(" [1] Imprimir Lista\n");
    printf(" [2] Buscar Nome\n");
    printf(" [3] Sair\n");	
    printf(" Opcao: ");
    scanf("%c", &op);
    fflush(stdin);
    return op;
}

int main() {
    const int qtd = 10;
    int indice = -1;
    Funcionario funcionario[qtd];

    inserirFuncionario(funcionario, qtd);


    while(1){
        switch(menu()) {
            case '1':
                imprimirLista(funcionario, qtd);
                break;
            case '2':
                indice = busca_bin(funcionario, qtd);

                if(indice != (-1)){
                    printf("\n Nome encontrado: {%s}\n", funcionario[indice].nome);
                } else{
                    printf("\n Nome nao encontrado.\n");
                }
                printf("\n");
                system("pause");
            case '3':
                exit(0);
                break;
            default:
                printf("\n Opcao Invalida!\n\n");
                system("pause");

        }
    }


    return 0;
}
