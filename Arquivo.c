#include <stdio.h>
#include <stdlib.h>

typedef struct  {
	int hora, minutos, segundos;
}Horario;

typedef struct{
	int dia, mes, ano;
}Data;

typedef struct Compromisso{
	char descricao [100];
    Horario horario;
	Data data;
};

struct Compromisso compromisso[2];

void cad_compromisso(){
	int i;
		for(i=0;i<=1;i++){
			fflush(stdin);
			printf("Informe uma descricao para o compromisso: ");
			scanf("%[^\n]s", compromisso[i].descricao);
			printf("\n Informe a data: (D M A)");
			scanf("%d %d %d\n", &compromisso[i].data.dia, &compromisso[i].data.mes, &compromisso[i].data.ano);
			printf("Informe o horario: ");
			scanf("%d %d %d \n", &compromisso[i].horario.hora, &compromisso[i].horario.minutos, &compromisso[i].horario.segundos);
		}
		for(i=0;i<=1;i++){
			printf("Compromisso %d: \n Descricao: %s \n Data: %d %d %d \n Hora: %d %d %d\n", i+1, compromisso[i].descricao, compromisso[i].data.dia, compromisso[i].data.mes, compromisso[i].data.ano, compromisso[i].horario.hora, compromisso[i].horario.minutos, compromisso[i].horario.segundos);	
		}
}



int main(){
	
	cad_compromisso();
	
	return 0;
}
