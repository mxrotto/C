#include <stdio.h>
#include <stdlib.h>

#define max 5

void menu(){
    printf("1 - inserir\n");
    printf("2 - remover\n");
    printf("3 - visualizar\n");
    printf("4 - sair\n");
}

void insercao(int *fim, int *fila){
    if(*fim < max){
        system("@cls||clear");
        printf("Inserir valor:");
        scanf("%d", &fila[*fim]);
        (*fim)++;
    }
    else
        printf("Sua lista esta cheia\n");
    system("pause");
}

void remocao(int *inicio, int *fim){
    if(*inicio != *fim){
        (*inicio)++;
    }
    else
        printf("A lista vazia\n");
        system("pause");
}

void impressao(int inicio, int fim, int *fila){
    int i;
    if(inicio != fim){
        for(i = inicio;i < fim;i++){
            printf("Valor: %d\t", fila[i]);
        }
    }
    else{
        printf("sua fila esta vazia\n");
    }
    system("pause");
}

int main(){
    int inicio = 0, fim = 0, fila[max];
    int opc = 0;
    while(!EXIT_SUCCESS){
        system("@cls||clear");
        menu();
        printf("escolha:");
        scanf("%d", &opc);
        if (opc == 1)
            insercao(&fim, fila);
        if (opc == 2)
            remocao(&inicio, &fim);
        if (opc == 3)
            impressao(inicio, fim, fila);
        if (opc == 4)
            exit(EXIT_SUCCESS);
    }
}
