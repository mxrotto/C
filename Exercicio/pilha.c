#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 			100


void revstring(char string[], char revstr[], int topo){
	int i = 0, sizeT = topo;
	for(topo; topo >= 0; topo--){
		if(string[topo-1] == ' ' || topo == 0){
			while((topo + i) <= sizeT || string[topo + i] == ' '){
				revstr[topo + i] = string[sizeT - i];
				i++;
			}
			sizeT = topo - 2;
			revstr[topo - 1] = ' ';
			i = 0;
			topo--;
		}
	}
	printf("%s\n", revstr);
	printf("a\n");
}

int stringset(char string[]){
	int topo;
	do{
		printf("Limite maximo de %d caracteres\n", size);
		printf("texto:");
		topo = (strlen(gets(string))-1);	
	}while(topo > size);
}

int main(){
	char string[size], revstr[size];
	int topo;
	topo = stringset(string);
	string[topo+1] = '\0';
	revstr[topo+1] = '\0';	
	revstring(string, revstr, topo);
}
