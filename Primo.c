#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num){
	int i;
	for(i = 2 ; i <= num;i++){
		if(num % i == 0 && i != num){
			return false;
		}
	}
	return true;	
}

void prime(int num1, num2){
	int size = 0;
	for(num1;num1 <= num2;num1++){
		if(isPrime(num1) == true){
			printf("-%d-", num1);
			size++;	
		}	
	}
	printf("\n Quantidade de primos:%d", size);	
}

int main(){
	int *temp, num1, num2, quant = 0;
	printf("Informe os dois numeros:");
	scanf("%d %d", &num1, &num2);
	printf("\n\n");
	prime(num1, num2);
}
