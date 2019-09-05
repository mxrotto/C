#pragma warning(disable:4996)			//Visual Studio Suppress Error

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h> 
#include <unistd.h>
#include <math.h>

#define error	0xe7
#define cancel	0xa2
#define exit	0xa1


void router();
int CPFValidator();
int verifNum(int);
void errorMsg(int, int);
void header(char*);
int maskInout(int*);


int verifNum(int sum){
	if(sum % 11 < 2)
		return 0;
	return (11 - (sum % 11));
}

void teste(){
	printf("cpf");
	system("pause");
}

void teste2(){
	printf("ver");
	system("pause");
}

void teste3(){
	printf("sair");
	system("pause");
}

void errorMsg(int code, int action){
	if(code == 1){
		if(action == cancel)
			printf("\n\nOpercao cancelada\n");
		if(action == error)
			printf("\n\nCPF nao eh valido\n");
		sleep(3);
	}		
}

void router(int op){ 
	int response;
	if(op == 1)
		response = CPFValidator();
	if(op == 2)
		teste2();
	if(op == 3)
		teste3();
	if(response == cancel || response == error){
		errorMsg(op, response);
	}	
	if(response == exit){
	printf("cof valido");
		system("pause");
	}
}

// 38
void header(char in[]){
	char buffer[38];
	strcpy(buffer, in);
	if(strlen(in) % 2 != 0){
		strcat(buffer, " ");
		}
	int size = (20 - (ceil(strlen(buffer)/2.0)));
	printf("____________________________________________________\n");
	printf("------%*c%s%*c------\n", size, ' ', buffer, size, ' ');
	printf("````````````````````````````````````````````````````\n");
}

int arrayScan(int input[], int times) {
	int sum = 0, i, timescpy = 0;
	timescpy = (times + 2);
	for (i = 0; i < times; i++, timescpy--) {
		sum += (input[i] * timescpy);
	}
	return sum;
}

int charToInt(char input) {
	return input - 48;
}

char isdigit(unsigned char c){
	if (c >= '0' && c <= '9' && c != '`')
		return 1;
	return 0;
}

int maskInput(int output[]) {
	int i = 0;
	char buffer;
	do {
		fflush(stdin);
		buffer = getch();
		if (isdigit(buffer)){
			output[i] = charToInt(buffer);
			printf("%d", output[i]);
			if (i == 2 || i == 5)
				printf(".");
			if (i == 8)
				printf("-");
			i++;
		}
		if (buffer == 121) 
			return cancel;
	} while (i < 11);
	return exit;
}

void menu(){
	char key;
	int control = 1;
	while(1){
		system("cls||clear");
		header("Use as setas para controlar < >");
		switch(control){
			case 1:
				printf("[Validar cpf]\n");
				printf("ver cpf\n");
				printf("sair\n");
				break;
			case 2:
				printf("Validar cpf\n");
				printf("[ver cpf]\n");
				printf("sair\n");
				break;
			case 3:
				printf("Validar cpf\n");
				printf("ver cpf\n");
				printf("[sair]\n");
				break;
		}
		key = getch();
		if(key == 113)
			control++;
		if(key == 49)
			control--;
		 if(control > 3)
			control = 1;
		if(control < 1)
			control = 3;
		if(key == 10)
			router(control);
	}
}
	
int CPFValidator(){
	int soma, cpf[11];
	system("cls||clear");
	header("Informe o CPF");
	printf("CPF:");
	if(maskInput(cpf) != cancel){
		soma = arrayScan(cpf, 8);
		if(verifNum(soma) != cpf[9])
			return error;
		soma = arrayScan(cpf, 9);
		if(verifNum(soma) != cpf[10])
			return error;
		return exit;		
	}else
		return cancel;
		
}	
	
	
	
int main() {
	int escolha, cpf[12];
	menu();
	return 0;
}
