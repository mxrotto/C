//nao corrigido - espaco no final da frase faz com que a ordem perca o sentido!! 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>					

#define size 			100

void revstring(char string[], char revstr[], int topo){
	int i = 0, sizeT = topo;
	for(topo; topo >= 0; topo--){					//decrementado topo
		if(string[topo-1] == ' ' || topo == 0){			//se indice da _string_ - 1 eh igual a espaco ou indice esta no ponto inicial
			while((topo + i) <= sizeT){			//enquanto indicie + i for menor que ultimo topo ou enquanto indicie + i for igual a espaco
				revstr[topo + i] = string[sizeT - i];	//_revstr_ topo decrementado mais i recebe _string_ ultimo topo menos i
				i++;												
			}
			sizeT = topo - 2;
			revstr[topo - 1] = ' ';
			i = 0;
			topo--;
		}
	}
}

int stringset(char string[]){
	int topo;
	do{
		printf("Limite maximo de %d caracteres\n", size);
		printf("texto:");
		gets(string);
		topo = (strlen(string)-1);	
	}while(topo > size);
}

int main(){
	char string[size], revstr[size];
	int topo;
	topo = stringset(string);
	string[topo+1] = '\0';
	revstr[topo+1] = '\0';	
	revstring(string, revstr, topo);
	printf("-----------------------------\n");
	printf("\nTexto comun	:%s\n", string);
	printf("Texto invertido	:%s\n", revstr);
}
