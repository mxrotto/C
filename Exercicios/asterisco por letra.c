#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Tam 40

char *subst(char []);

int main(){
    char input[Tam], input2[Tam];
    printf("Informe a frase:");
    gets(input);
    printf("%s", subst(input));
}

char *subst(char palavra[Tam]){
    int x, y, z, tmp, tmplt=0;
    char letter;
    z = strlen(palavra);
    for(x = 0; x <= z;x++){
    tmp = 0;
        for(y = 0; y <= z;y++){
            if (palavra[y] == palavra[x] && palavra[y] != ' '){
            tmp++;
                if (tmp > tmplt){
                tmplt++;
                letter = palavra[x];
                }
            }
        }
    }
    for(x = 0; x <= z;x++){
        if (palavra[x] == letter){
        palavra[x] = '*';
        }
    }
    return palavra;
}
