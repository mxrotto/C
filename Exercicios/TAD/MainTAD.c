#include <stdio.h>
#include <stdlib.h>
#include "TADConta.h"

int main (){
    ContaBancaria conta1;
    double temp, temp2;
    inicializa(&conta1, 12345);
    printf("Informe a quantidade do deposito:");
    scanf("%lf", &temp);
    deposito(&conta1, temp);
    printf("..............................\n");
    imprime(conta1);
    printf("..............................\n");
    temp2 = (temp+1);                                  //gambiarra
    while (temp2 >  temp){
    printf("Qual o valor do saque?:");
    scanf("%lf", &temp2);
        if(temp2 >  temp){
           printf("\nseu saldo eh insuficiente ao valor requerido no saque\n");
        }
        else if(temp < 1){
            printf("\nNao ha saldo em sua conta\n");
        }
    }
    saque(&conta1, temp2);
    printf("..............................\n");
    imprime(conta1);
    printf("..............................\n");
    system("pause");
return 0;
}
