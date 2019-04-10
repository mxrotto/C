#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *fgets(char *s, int size, FILE *stream);

	typedef struct tipo_data{
		int dia, mes, ano, hora, minuto, seg;
		char descr[50];
	} info;

void alrm(int ano, int mes, int dia, int hora, int min, int seg, char descricao[]){
		printf("\n====================================================================================\n");
		printf("Ano:%d \tMes:%d \tDia:%d\n", ano, mes, dia);
		printf("Hora:%d \tMinuto:%d \tSegundo:%d\n", hora, min, seg);
		printf("\nDescricao:%s\n\n", descricao);
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
	printf("Informe a hora...\n");
	printf("Hora:");
	scanf("%d", &alarme.hora);
    printf("Minutos:");
	scanf("%d", &alarme.minuto);
    printf("Segundos:");
	scanf("%d", &alarme.seg);
	getchar();
	printf("Descricao:");
	gets(alarme.descr);
	//getchar();
	alrm(alarme.ano, alarme.mes, alarme.dia, alarme.hora, alarme.minuto, alarme.seg, alarme.descr);
	system("pause");
}
