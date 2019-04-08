#include <stdio.h>
#include <stdlib.h>

float media(float, float, float);

int main()
{
    struct aluno{
        char RA[9], nomeAluno[30];
        float p1, p2, p3;
        int faltas;
    };

    struct aluno aluno1;

    printf("Informe seu RA:");
    gets(aluno1.RA);
    printf("Informe seu nome:");
    gets(aluno1.nomeAluno);
    printf("Informe numero de faltas:");
    scanf("%d", &aluno1.faltas);
    printf("Informe a nota do p1:");
    scanf("%f", &aluno1.p1);
    printf("Informe a nota do p2:");
    scanf("%f", &aluno1.p2);
    printf("Informe a nota do p3:");
    scanf("%f", &aluno1.p3);
    printf("\nnome:%s \nRA:%s\tNumero faltas:%d \nnota1 :%.2f \tnota2 :%.2f \tnota3 :%.2f", aluno1.nomeAluno, aluno1.RA, aluno1.faltas, aluno1.p1, aluno1.p2, aluno1.p3);
    printf("\nmedia: %.2f", media(aluno1.p1, aluno1.p2, aluno1.p3));
    if (media(aluno1.p1, aluno1.p2, aluno1.p3) >= 60){
        printf("\n\npassou!!\n");
    }
    else
        printf("\n\nreprovou!!\n");
}

float media (float nota, float nota2, float nota3){
    return (nota + nota2 + nota3)/3;
}
