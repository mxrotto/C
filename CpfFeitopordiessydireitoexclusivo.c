#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define dirtyCPFs 14
#define size 11

int inline getRealValue(char unicode) { return (unicode - 48);}

char *vanityInput(char dirtyCPF[]) {
	static char response[size];
	char clean[size];
	int i, j;
	if(strlen(dirtyCPF) != dirtyCPFs)
		return NULL;	
	for(i = 0, j = 0;i < dirtyCPFs;i++){
		if(getRealValue(dirtyCPF[i]) > -1 && getRealValue(dirtyCPF[i]) < 10)
			clean[j++] = dirtyCPF[i];
		clean[j] = '\0';
	}
	if(j != size)
		return NULL;
	strcpy(response, clean);
	return response;
}

bool verifCpf(char cpf[]){
	int i, j, sector = 9, sum = 0, verif = 10;
	for(i = 0;i < 2;i++, verif++, sector++, sum = 0) {
		for(j = 0;j < sector;j++) {
			sum += (getRealValue(cpf[j]) * (verif - j));
		}
		sum = (size - (sum % size) > 9)? 0:(size - (sum % size));
		if(!(sum == getRealValue(cpf[sector])))
			return false;
	}
	return true;
}

int main(){
	char cpf[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '9'};
	verifCpf(cpf);
	printf("%s", vanityInput("123.123.123-12"));
}
