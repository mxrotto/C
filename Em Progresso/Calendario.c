#include <iostream>
#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *fgets(char *s, int size, FILE *stream);


	typedef struct tipo_data{
		int dia, mes, ano;
		char hora[5], descr[50];
	} info;
	
	
	alrm(int ano, int mes, int dia, char hora[], char descricao[]){
		printf("\n====================================================================================\n");
		printf("Ano:%d\tMes:%d\tDia:%d\tHora:%s\n", ano, mes, dia, hora);
		printf("Descricao:%s\n", descricao);
		printf("====================================================================================\n");
		
	}
	
int main() {
	info alarme;
	printf("Iforme o lembrete...\n");
	printf("Ano:");
	scanf("%d", &alarme.ano);
	printf("Mes:");
	scanf("%d", &alarme.mes);
	printf("Dia:");
	scanf("%d", &alarme.dia);
	printf("Hora[ex: 23:59]:");
	fgets(alarme.hora, 5, stdin);
	getchar();
	printf("Descricao:");
	fgets(alarme.descr, 50, stdin);
	getchar();
	alrm(alarme.ano, alarme.mes, alarme.dia, alarme.hora, alarme.descr);

	system("pause");
}
