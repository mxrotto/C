#include <stdio.h>
#include <string.h>

int main() {

	char nome[40];
	int x, cont;
	printf("informe seu nome: ");
	gets(nome);
	cont = strlen(nome);
		for(x = 0; x <= cont; x++){             // percorrendo vetor
        nome[x] = tolower(nome[x]);             // Deixando todas minusculas
            }
			for(x = 0; x <= cont; x++){         // percorrendo vetor
            if(nome[x] == ' '){                 // encontrado o espaco
            nome[x + 1] = toupper (nome[x+1]);  // convertendo a letra apos o espaco
            }
		}
    nome[0] = toupper (nome[0]);
	printf("\n%s\n", nome);
	system("pause");
}
