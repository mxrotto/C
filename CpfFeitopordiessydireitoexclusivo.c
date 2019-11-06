#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define dirtyCPFs 14	//tamanho do cpf de entrada, com pontos e traco
#define size 11			//Tamanho do cpf sem pontos e traco



/*------------------------------------------------------
			getRealValue():int
	Retotna o valor numerico correspondete ao do caracter
ex:O caracter '1' eh representado como 49 na tabela unicode,
logo 49 - 48 eh igual a 1 em inteiro, assim com os outros 
numeros.
------------------------------------------------------------*/
int inline getRealValue(char unicode) { return (unicode - 48);}


/*------------------------------------------------------
			*inputPurifying():char
	Funcao que "limpa" o cpf de entrada, tira pontos e traco, 
vetifica o tamanho da string e tambem faz o papel de validar
o cpf. A funcao tem seu nome com astericos pois retorna um 
ponteiro, que seria o conjuto de caracteres com o cpf limpo
(retornar um ponteiro significa retornar um endereco de 
memoria, logo qualquer variavel local que eu retorne deixa de
existir no fim da funcao, assim como seu endereco, retornando
um array de char com o modificador static faz com que eu 
retorne so o conjuto de caracteres, nao o endereco em si
necessariamente (acho eu)).
------------------------------------------------------------*/
char *inputPurifying(char dirtyCPF[]) {
	static char response[size];				// String de retorno
	char clean[size];						// Receptor do conjunto de caracteres numericos
	int i, j;								// contadores
	if(strlen(dirtyCPF) != dirtyCPFs)		// se o tamanho do cpf c/ pontuacao eh diferete do tamanho comum de cpf c/ pontuacao.
		return NULL;						// retorna null, pois o cpf tem um numero diferentes de caracteres comparado ao padrao, ja pode ser considerado invalido.
	for(i = 0, j = 0;i < dirtyCPFs;i++){	// distribuicao de caracteres numericos
		if(getRealValue(dirtyCPF[i]) > -1 && getRealValue(dirtyCPF[i]) < 10) // se o caracter representa mesmo um numero
			clean[j++] = dirtyCPF[i];		// acrecento o caracter numerico ao cpf limpo e logo dps incremento j
		clean[j] = '\0';					// delimitador de fim de sequencia de caracteres 
	}
	if(j != size)							// se j for diferente de size(11) pode reprssentar que existam mais ou menos caracters numericos no cpf de entrada, logo ele eh invalido
		return NULL;
	strcpy(response, clean);				//Copia do cpf OK para a string de retorno
	return response;
}


/*------------------------------------------------------
			vetifCpf():bool
	Verifica os dois digitos finais do cpf, retorna imeditamente
FALSE se qualquer um dos dois nao bater com o calculo resultante,
no final returna TRUE, pois aparentemente o cpf condiz com a
verificacao.	.
------------------------------------------------------------*/
bool verifCpf(char cpf[]){
	/* 
		contadores e variaveis auxiliares, sector representa o indice do
	do numero verificador a ser validado, sum a soma e multiplicacao e sobra da divisao,
	verif um auxilar no decremento decorente a multiplicacao
	*/
	int i, j, sector = 9, sum = 0, verif = 10; 			// sector no primeiro numero verificado e dps segundo, verif na divisao decremetada de 10, depois 11
	for(i = 0;i < 2;i++, verif++, sector++, sum = 0) {	// correndo duas vezes o cpf, verificando dois numeros 
		for(j = 0;j < sector;j++)
			sum += (getRealValue(cpf[j]) * (verif - j));// tendo o resultado do numero multiplicando pelo decremento
		// 			\/ operador ternario testando a condicao se a 11 menos sobra da divisao por 11 eh maior que 9
		sum = (size - (sum % size) > 9)? 0:(size - (sum % size)); // se for maior que 9 retorna 0, caso contrario retorna 11 - a sobra da divisao
		if(!(sum == getRealValue(cpf[sector])))		// se o numero resultante for diferente do numero verificador de entrada
			return false;		// 	o cpf nao eh valido
	}							// o incremento do verif e do sector acontece no for
	return true;
}

int main(){
	char cpf[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '9'};
	verifCpf(cpf);
	printf("%s", inputPurifying("123.123.123-12"));
}
