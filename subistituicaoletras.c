    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void letra(int *container, char *frase){
	int i, j;
	for(i = 0;i < strlen(frase);i++){
		container[3] = frase[i];
		for(j = 0;j < strlen(frase);j++){
			if(frase[j] == container[3] && frase[j] != ' '){
				container[2]++;
			}			
		}
		if(container[2] > container[0]){
			container[0] = container[2];
			container[1] = container[3];	
		}
		container[2] = 0;	
	}
}

char* trade(int *array, char *string){
	char *digest;
	strcpy(digest, string); 
	int i = 0;
	goto inCycle;
	inCycle:
		if(digest[i] == '\0')
			goto exitCycle;
		else
			goto runCycle;	
	runCycle:
		if (digest[i] == array[1]){
			digest[i] = '*';
		}
		i++;
		goto inCycle;
	exitCycle:
		return digest;		
}

void line(char *string, char *mode){
	int i;
	if(strcmp(mode, "up") == 0)
		printf("\xDA");
	if(strcmp(mode, "down") == 0)
		printf("\xC0");
	for(i = 0;i <= (strlen(string)+18);i++){
		printf("\xC4");	
	}
	if(strcmp(mode, "up") == 0)
		printf("\xBF");
	if(strcmp(mode, "down") == 0)
		printf("\xD9");
	printf("\n\n");
}

void show(int *array, char *string, char *cypher){
	system("cls||clear");
	line(string, "up");
	printf("  frase original: %s\n\n", string);
	printf("  frase de saida: %s\n\n", cypher);
	printf("  Letra:%-*cQntd:%d\n\n", (strlen(string)/2), array[1], array[0]);
	line(string, "down");
	system("pause"); 
}

void run(char* string){
	int container[] = {0, 0, 0, 0};
	char *cypher;
	letra(container, string);
	cypher = trade(container, string);
	show(container, string, cypher);
}

int main(){
	int i;
	char string[100];
	printf("Informe sua frase: ");
	scanf("%[^\n]", string);
	run(string);
}
