// Desenvolvido por Angelino Gonsalves, como projeto do primeiro periodo de analise e desenvolvimento de sistemas UTFPR ponta grossa

#include<windows.h>
#include<stdio.h>
#include<conio.h>


#define i 30    // quantia de linhas
#define j 70   // quantia de colunas

char nome[30];
int veloc, op=2;

void coordenadasTela(int x,int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y}); // x=j (sao colunas) e y=i (sao as linhas)
}

void desenha_campo()    //desenha as paredes
{
    int z; // variavel auxiliar para desenhar

    for(z=0;z<=j;z++)   // desenha parede de cima horizontal
    {
        coordenadasTela(z,0);
        printf("S");
        Sleep(10);
    }
    for(z=1;z<i;z++)   // desenha parede da direita vertical
    {
        coordenadasTela(j,z);
        printf("S");
        Sleep(10);
    }
    for(z=j;z>=0;z--)   // desenha parede de baixo horizontal
    {
        coordenadasTela(z,i);
        printf("S");
        Sleep(10);
    }
    for(z=i-1;z>0;z--)   // desenha parede da esquerda vertical
    {
        coordenadasTela(0,z);
        printf("S");
        Sleep(10);
    }
}
void inicio(){
    coordenadasTela(35,5);
    printf("\\//\\//\\//\\//\\//\\//\\//\\//\\>> ");
    coordenadasTela(35,6);
    printf("  Bem vindo ao Jogo SNAKE\n");
    coordenadasTela(35,7);
    printf("<<\\//\\//\\//\\//\\//\\//\\//\\//\\");


}

void bem_vindo()
{
     int tecla, aux_dif=0;

    coordenadasTela(35,8);
    printf("Digite seu nome: ");
    fflush(stdin);
    gets(nome);
    coordenadasTela(35,10);
    printf("MENU");
    coordenadasTela(35,12);
    printf("Selecione uma das opcoes");
    coordenadasTela(15,14);
    printf("<ENTER> Iniciar\t<ESC> Instrucoes\t<ESPACO> Dificuldade ");

    do
    {
        tecla=getch();

        if(tecla == 27)
        {
            instrucoes();
            system("cls");
            coordenadasTela(15,5);
            printf("<ENTER> Iniciar \t\t <ESPACO> Dificuldade ");
            tecla=getch();
        }

        if(tecla == 32)
        {
            veloc=dificuldade();
            aux_dif=1;
            coordenadasTela(15,5);
            printf("Pressione ENTER para come%car", 135);
            tecla=getch();
        }
        if(aux_dif == 0) veloc=200;

        system("cls");
    }while (tecla != 13 && tecla != 27 && tecla != 32);

}

void instrucoes()
{
    system("https://drive.google.com/open?id=1ogxd7VeHrVioz8EFPu41JZzXBWlgp4DZcls");
    coordenadasTela(15,3);
    printf("Use as setas para controlar a cobrinha:");
    coordenadasTela(15,5);
    printf("Move para cima %c", 24);
    coordenadasTela(15,6);
    printf("Move para baixo %c", 25);
    coordenadasTela(15,7);
    printf("Move para direita %c", 26);
    coordenadasTela(15,8);
    printf("Move para esquerda %c", 27);
    coordenadasTela(15,11);
    printf("Coma os alimentos %c para evoluir", 1);
    coordenadasTela(15,14);
    printf("E evite os obstaculos %c ", 88);
    coordenadasTela(15,17);
    printf("Use a tecla Espa%co para pausar a qualquer momento ", 135);
    coordenadasTela(15,19);
    printf("Use a tecla ESC para finalizar a qualquer momento ");
    printf("\n\n\t");
    system("pause");
}

int dificuldade()
{
        int nivel_dif;
        do
        {
            system("cls");
            coordenadasTela(15,5);
            printf("Escolha o Nivel de Dificuldade: ");
            coordenadasTela(15,8);
            printf("<1> FACIL \t <2> MEDIA \t <3> DIFICIL ");
            scanf("%d", &op);
            nivel_dif=300/op;
        }while (op<1 || op>3);
        system("cls");
        return(nivel_dif);
}

void desenvolvimento()
{
    int d=2, x, t=1, pontos=0, level=1, k=10, resp;
    //d= dire��o/ x= auxiliar/ t= auxiliar/ level= nivel k= controle do nivel/ pontos= pontua��o/ veloc= controle sleep/ resp= resposta para continuar
    int cx[300]={1,2}, cy[300]={7,7}, ax, ay, ox, oy;
    // cx= tamanho da cobra na horizontal // cy= tamanho da cobra na vertical // ax e ay = local do alimento // ox e oy = local do obstculo
    int tecla=32;
    // tecla para receber o botao pressionado

    coordenadasTela(j+2, 5);     // mostra o nome da pessoa abaixo do quadro do jogo
    printf("%s", nome);

    srand(time(NULL)); // cria o alimento e o obstaculo em posicao aleatoria, inicializa
    ax=(rand()%(j-1))+1;
    ay=(rand()%(i-1))+1;
    ox=(rand()%(j-1))+1;
    oy=(rand()%(i-1))+1;

    while(tecla!=27)       // desenvolvimento do jogo
    {   while(tecla!=27 &&!(tecla=kbhit()))
        {   for(x=t;x>0;x--)
            {   cx[x]=cx[x-1];
                cy[x]=cy[x-1];
            }
            if(d==0)cx[0]--;    //esquerda
            if(d==1)cy[0]--;    //cima
            if(d==2)cx[0]++;    //direita
            if(d==3)cy[0]++;    //baixo
            coordenadasTela(cx[t],cy[t]);
            printf(" ");
            if(ax==cx[0]&&ay==cy[0])
            {
                t++;
                ax=(rand()%(j-1))+1;
                ay=(rand()%(i-1))+1;
                pontos++;
            }
            coordenadasTela(cx[0],cy[0]);
            printf("%c",207);
            coordenadasTela(ax,ay);
            printf("%c",4);
            coordenadasTela(ox,oy);
            printf("%c",88);
            if (pontos==k)
            {
                level++;
                k=k+10;
                veloc=veloc-veloc/10;
                ox=(rand()%(j-1))+1;
                oy=(rand()%(i-1))+1;
            }
            coordenadasTela(j+2, 7);
            printf("Pontua%c%co= %d", 135, 198, pontos);
            coordenadasTela(j+2, 9);
            printf("Level= %d", level);
            Sleep(veloc);
            coordenadasTela(j+2,11);
            printf("dificuldade: %d", op);
            coordenadasTela(j+2,12);
            printf("Sleep real: %d", veloc);
            for(x=1;x<t;x++){
                    if(cx[0]==cx[x]&&cy[0]==cy[x])tecla=27;
            }

            if(ox==cx[0] && oy==cy[0])
                tecla=27;
            if(cy[0]==0||cy[0]==i||cx[0]==0||cx[0]==j)
                tecla=27;
        }
        if(tecla!=27)
            tecla=getch();
        if(tecla==75)
            d=0;
        if(tecla==72)
            d=1;
        if(tecla==77)
            d=2;
        if(tecla==80)
            d=3;
        if(tecla==32)
        system("pause");
        if(cy[0]==0||cy[0]==i||cx[0]==0||cx[0]==j)
            tecla=27;
    }
    system("cls");

    printf("\a\a\a\n\n\t\t GAME OVER \n\n\t\tPontua%c%co = %d \n\n\n ",135, 198, pontos);
    system("pause");

    do
    {
        printf("\n\n\t\t Deseja come%car denovo? \n\t\t <1>SIM <2>N%cO \n", 135, 199);      // sele��o para recome�ar o jogo
        scanf("%d", &resp);
    }while (resp!=1 && resp!=2);
    system("cls");
    if (resp==1)        // se 1 pressinado, ele retorna ao main e come�a tudo de novo
    {
        main();
    }
    else
    {
        printf("\n\n\t\t FIM DE JOGO \n\n");       // se o 2 pressionado, ele finaliza o jogo
    }
}


void main()
{
    system("COLOR 0C");
    keybd_event(VK_MENU, 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    inicio();
    bem_vindo();            // tela inicial
    desenha_campo();        // desenha o quadro do campo
    desenvolvimento();      // desenvolvimento do jogo
}
