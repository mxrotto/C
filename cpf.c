
#pragma warning(disable:4996)			//Visual Studio Suppress Error

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h> 
#include <math.h>

#define error	0xe7
#define cancel	0xa2
#define exit	0xa1


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

void router(int op){ 
	if(op == 1)
		teste();
	if(op == 2)
		teste2();
	if(op == 3)
		teste3();	
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
		if (buffer == 27) 
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
	
void CPFValidator(){
	int cpf[11];
	if(maskInput(cpf) != cancel){
		
		
		
	}
	
}	
	
	
	
int main() {
	int escolha, cpf[12];
	int teste;
	menu();
	return 0;
}
