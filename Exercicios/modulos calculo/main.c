#include <stdio.h>
#include <stdlib.h>
#include "div.c"
#include "sub.c"
#include "vezes.c"
#include "soma.c"

float calcu(char simbol[], int n, int n2){
	float result;

	if(simbol[0] == '/'){
		if (n == 0 || n2 == 0){
			printf("divisao por 0 sao indefinidas\n");
			return(0);
		}
		return divisao(n, n2);
	}
	else if(simbol[0] == '-'){
		return (subt(n, n2));
	}
	else if(simbol[0] == '*'){
		return (vez(n, n2));
	}
	else if(simbol[0] == '+'){
		return (soma(n, n2));
	}
	else
		printf("Escolha incorreta");
			return(0);
}

int main() {
	char simb[1];
	int num, num2;
	printf("operacao disponivel: / + - *\n");
	printf("Escolha entre uma delas:");
	gets(simb);
	printf("informe o primeiro numero:");
	scanf("%d", &num);
	printf("informe o segundo numero:");
	scanf("%d", &num2);
	printf("Resultado:%g\n", calcu(simb, num, num2));
	system("pause");
	return 0;
}
