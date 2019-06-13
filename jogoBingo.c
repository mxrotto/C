#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTDTAB 6
#define qtd_num 5


#pragma warning(disable:4996)							//Pode apagar, suppress de "erro" do visual studio

typedef struct {
	int colunas[qtd_num];
	int linhas[qtd_num];
	int diagonalPrincial;
	int diagonalSecundaria;
	int pontas;
	int cartelas[qtd_num][qtd_num];
} Cartela;

//inicializa cartelas com 0
void inicializaCartelas(Cartela *num_cartelas) {
	int i = 0, j = 0;
	for (i = 0; i < qtd_num
		; i++) {
		num_cartelas[i].diagonalPrincial = 0;
		num_cartelas[i].diagonalSecundaria = 0;
		num_cartelas[i].pontas = 0;
		for (j = 0; j < qtd_num; ++j) {
			num_cartelas[i].colunas[j] = 0;
			num_cartelas[i].linhas[j] = 0;
		}
	}
}

// Contabiliza as condicoes de vitoria
// retorna 1 se ganhou e 0 se nao
int somaCondicaoVitoria(Cartela *num_cartelas, int t, int i, int j) {
	// adiciona +1 na coluna sorteada
	if (++num_cartelas[t].colunas[i] == qtd_num)
		return 1;
	// adiciona +1 na linha sorteada
	if (++num_cartelas[t].linhas[j] == qtd_num)
		return 1;
	// verifica se esta na diagonalPrincial
	if (i == j)
		if (++num_cartelas[t].diagonalPrincial == qtd_num)
			return 1;
	// verifica se esta na diagonalSecundaria
	if (i + j == qtd_num - 1)
		if (++num_cartelas[t].diagonalSecundaria == qtd_num)
			return 1;
	// verifica se esta na ponta
	if ((i == 0 && ((j == 0) || (j == qtd_num - 1))) ||(i == qtd_num - 1 && ((j == 0) || (j == qtd_num - 1))))
		if (++num_cartelas[t].pontas == 4)
			return 1;
	return 0;
}

//verifica se o numero sorteado para a cartela ja nao existe
int VerificaRepitido(int cart[qtd_num][qtd_num], int num, int linha, int coluna) {
	int j;
	for (j = 0; j <= coluna; j++) {
		if (cart[j][linha] == num) {
			return 1;
		}
	}
	return 0;
}

//apenas usada para printar a tabela gerada
void PrintTabela(int cartelas[qtd_num][qtd_num]) {
	int i, j;
	//printf("\n\n");
	for (i = 0; i < qtd_num; i++) {
		printf("\n");
		for (j = 0; j < qtd_num; j++) {
			printf("[%02.d]", cartelas[i][j]);
		}
	}
}

//usado para printar todas as tabelas
void PrintaTodasCartelas(Cartela *num_cartelas) {
	int i;
	for (i = 0; i < QTDTAB; i++) {
		printf("\n\n");
		printf("\nTabela %d", i + 1);
		PrintTabela(num_cartelas[i].cartelas);
	}
}

//ordena linhas em ordem crescente 
void Ordena(int cartela[qtd_num][qtd_num]) {
	int i = 0, aux = 0, j = 0, k = 0;
	for (i = 0; i < qtd_num; i++) {
		for (j = 0; j < qtd_num; j++) {
			for (k = 0; k < qtd_num - 1; k++) {
				if (cartela[k][i] > cartela[k + 1][i]) {	//fazendo a verificacao se e repitido e substituindo posicoes
					aux = cartela[k][i];
					cartela[k][i] = cartela[k + 1][i];
					cartela[k + 1][i] = aux;
				}
			}
		}
	}
}

//compara se numero sorteado e repitido ou nao
/*int numJaFoiSorteado(int numSorteado, int *arrSorteados, int qtdSorteados) {
	int i;
	for (i = 0; i < qtdSorteados; i++) {				//percore ate a quantidades de numeros sorteados verificando se nao sao repitido
		if (numSorteado == arrSorteados[i]) {
			return 1;
		}
	}
	return 0;
}

//sorteia numeros
int sorteiaNum(int *qtdSorteados) {
	//int numSorteado, arrSorteados[qtd_num * 10], t, i, j;
	int numSorteado = 0, arrSorteados[qtd_num * 10];
	do {																			//chama a fupara verificar se epitido	
		numSorteado = (int) 1 + rand() % (qtd_num * 10);
	} while (numJaFoiSorteado(numSorteado, arrSorteados, *qtdSorteados) != 0);
	arrSorteados[*qtdSorteados] = numSorteado;
	(*qtdSorteados)++;																//contador de quantos sorteados
	printf("\n\nnumero: %d \n", numSorteado);
	return numSorteado;
}*/


int sorteiaNum(int *qtdSorteados, int usados[]) {
	int numero;
	int i;
	numero = 1 + rand() % (qtd_num * 10);
	usados[*qtdSorteados] = numero;
		for (i = 0; i < (*qtdSorteados); i++) {
			if (numero == usados[i]) {
				numero = sorteiaNum(qtdSorteados, usados);
				(*qtdSorteados)--;
			}
		}
	(*qtdSorteados)++;
	return numero;
}

// Se alguem ganhou, retorna 1
int marcaX(int numSorteado, Cartela *num_cartelas, int qtdVitoria) {
	int i, j, t;
	for (t = 0; t < QTDTAB; t++) {
		for (i = 0; i < qtd_num; i++) {
			for (j = 0; j < qtd_num; j++) {
				if (num_cartelas[t].cartelas[i][j] == numSorteado) {
					num_cartelas[t].cartelas[i][j] = 0;
					if (somaCondicaoVitoria(num_cartelas, t, i, j) == 1) {
						system("cls");
						printf("A cartela de numero %d ganhou o premio %d\n", t + 1, qtdVitoria);
						PrintTabela(num_cartelas[t].cartelas);
						system("pause");
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

//arquivo TXT
int ArqTXT(int cartela[qtd_num][qtd_num]) {
	int i, j;
	FILE *pont_arq;										//gerando o arquivo
	pont_arq = fopen("arquivo_tabelas.txt", "a");
	if (pont_arq == NULL) {								//testando se o arquivo foi realmente criado
		printf("Erro na abertura do arquivo!");
		return 1;
	}
	fprintf(pont_arq, "\n");
	for (i = 0; i < qtd_num; i++) {						//imprimindo vetor no arquivo
		fprintf(pont_arq, "\n");
		for (j = 0; j < qtd_num; j++) {
			fprintf(pont_arq, "%d\t", cartela[i][j]);
		}
	}
	fclose(pont_arq);
	return 0;
}

//loop principal do jogo, roda tabela, verifica vitora, repete attdVitorias ser 3
int loop(int qtdVitorias, int *qtd, int numsorteado[]) {										//Valor para armazenar a quantidade de valores salvos							//Referenciando o ponteiro "qtdSorteados" como o endereco de qtd
	int numero;
	if (qtdVitorias == 0) {
		printf("\n---fim de jogo---\n");
		return 0;
	}
	//int dezena, randNum, i, j, cartelaNum, numSorteado, cont = 0, t;
	int dezena, randNum, i, j,  cont = 0, t;
	Cartela num_cartelas[QTDTAB];						//struc para armazenar cartelas
	inicializaCartelas(num_cartelas);
	srand((unsigned int)time(NULL));					//Casting do retono time_t 					
	for (t = 0; t < QTDTAB; t++) {						//for da struct (preencher as tabelas)
		printf("\nTabela %d", t + 1);
		for (i = 0; i < qtd_num; i++) {
			dezena = i * 10;
			for (j = 0; j < qtd_num; j++) {	
				randNum = 1 + rand() % 10 + dezena;		//sorteia um numero aleatorio de 0 ate 10 e soma um + a dezena do for anterior
				if (VerificaRepitido(num_cartelas[t].cartelas, randNum, i, j) == 1) {	//chama verificacao se e repitido na cartela
					j--;
					continue;
				}
				num_cartelas[t].cartelas[j][i] = randNum;
			}
		}
		Ordena(num_cartelas[t].cartelas);
		ArqTXT(num_cartelas[t].cartelas);
		PrintTabela(num_cartelas[t].cartelas);
		printf("\n\n");
	}

	int ganhou = 0;
	while (ganhou != 1) {
		numero = sorteiaNum(qtd, numsorteado);
		printf("\n\nnumero: %d \n", numero);
		ganhou = marcaX(numero, num_cartelas, qtdVitorias);
		printf("\n");
		system("pause");
		system("cls");
		if (ganhou == 0)
			PrintaTodasCartelas(num_cartelas);
	}
	return loop(--qtdVitorias, qtd, numsorteado);
}

int main() {
	int qtdSorteado = 0, numSorteado[qtd_num * 10];
	loop(3, &qtdSorteado, numSorteado);
	return 0;
}
