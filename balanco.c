#include <stdio.h>
#include <stdlib.h>

void balanc(float *temp){
    printf("\n\nValor Balanco:%g", *temp); // Exercicio 5.2
}

int main(){
    float *temp, balanco;
    temp = &balanco;
    balanco = 45.7;
    balanc(temp);
}
