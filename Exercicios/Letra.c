#include <stdio.h>
#include <stdlib.h>

void showletra(char *crt){
    printf("\n\nletra: %c\n", *crt); // Exercicio 5.3
}

int main(){
    char *ltr, letra;
    ltr = &letra;
    letra = 'W';
    showletra(ltr);
}
