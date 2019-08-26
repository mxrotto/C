#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* letra(char *frase){
	int i, j;
	int container[] = {0, 0, 0, 0};
	for(i = 0;i < strlen(frase);i++){
		container[3] = frase[i];
		for(j = 0;j < strlen(frase);j++){
			if(frase[j] == container[3]){
				container[2]++;
			}			
		}
		if(container[2] > container[0]){
			container[0] = container[2];
			container[1] = container[3];	
		}
		container[2] = 0;	
	}
	return container;	
}
