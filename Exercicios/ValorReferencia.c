#include <stdio.h>
#include <stdlib.h>

void porcen(float *num){
    *num += (*num * 0.10);
}


int main(){
    float valor;
    printf("Informe o valor:");
    scanf("%f", &valor);
    porcen(&valor);
    printf("Valor Incrementado 10\% : %g", valor);
}
