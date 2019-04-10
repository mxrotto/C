#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int coinc(int vet[], int num, int nTemp){
    int cont = 0, n;
    for (n = 0; n <= nTemp; n++){               //
        if (vet[n] == num){                     //Varrendo o vetor atras de numeros iguais
          cont++;                               //
        }
    }
    return cont;
}

int main(){
    int vet[MAX], num, numTemp, n;
    printf("quantos valores deseja informar(max 50)?:");
    scanf("%d", &numTemp);
    if(numTemp > 50){                           //Verificando limite maximo
       numTemp = 50;
    }
    for (n = 0; n < numTemp; n++){
        printf("%d%c Valor:", (n+1), 248);
        scanf("%d", &vet[n]);
    }
    printf("Informe o segundo numero:");
    scanf("%d", &num);
    printf("O total de numero do vetor que coincidem com o segundo eh de:%d\n", coinc(vet, num, numTemp));
}
