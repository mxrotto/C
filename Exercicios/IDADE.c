#include <stdio.h>
#include <stdlib.h>

int main(){
    int *idade, IDADE;
    idade = &IDADE;
    printf("digite a idade:");
    scanf("%d", &IDADE);
    printf("idade:%d", *idade);
}
