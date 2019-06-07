#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct tree{				//Arvore
    char info;
    struct tree *Rchild;
    struct tree *Lchild;
};

typedef struct tree Tree;

Tree *criaRaiz(){					
    return NULL;
}

void espacamento(int nivel){
    int i;
    for(i = 0; i < nivel-1; i++) {
        printf("\t");
    }
}

Tree *criaArvore(Tree *elem, char info){
    if(elem == NULL){
        elem = (Tree *) malloc(sizeof(Tree));
        elem->info = info;
        elem->Rchild = elem->Lchild = NULL;
    } else if(info < elem->info){
        elem->Rchild = criaArvore(elem->Rchild, info);
    } else {
        elem->Lchild = criaArvore(elem->Lchild, info);
    }
    return elem;
}

void imprimir(Tree *r, int nivel){
    if(r != NULL){
        espacamento(nivel);
        nivel++;
        printf(" \\%c\\.. ", r->info);
        printf("(nivel: %d)\n", nivel-2);
        imprimir(r->Rchild, nivel);
        imprimir(r->Lchild, nivel);
    }
}

void buscar(Tree *r, char valor, int *aux){
    if(r != NULL){
        buscar(r->Rchild, valor, aux);
        buscar(r->Lchild, valor, aux);
        if(r->info == valor){
            (*aux) = 1;
        }
    }
}



void freeTree(Tree *r){
    if(r != NULL){
        freeTree(r->Rchild);
        freeTree(r->Lchild);
		free(r);
    }
}

void insertIntoTree(Tree *root){
	int i;
	char keys[] = {'D' ,'B' ,'A' ,'C' ,'F' ,'E', 'H', 'L', 'G', 'F', 'K', 'D', 63, 'W', 'Z','\0'};
	if(root == NULL){
    	while(keys[i] != '\0'){
    		root = criaArvore(root, keys[i]);
    		i++;
    	}
    printf("%-17cArvore criada com sucesso!\n", ' ');
    } 
    else {            
    	printf("%-22cArvore ja criada!\n", ' ');   
    }	
}



void head(){
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%-18cArvore Binaria\n", ' ');
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
}

void checkBuscar(Tree *root){
	int *spot = (int *) malloc(sizeof(int));
	char letra;
	head();
    printf("%-24c[ Buscar ]\n", ' ');             
    printf("- Informe o valor: ");
    scanf("%c", &letra);
    fflush(stdin);
    buscar(root, letra, spot);             
    if((*spot) == 1){
    	printf(" Valor Encontrado: { %c }\n", letra);
    } else {   
    	printf(" Valor nao encontrado { %c }\n", letra);
    }
    *spot = 0;	
}

void checkImprimir(Tree *root){
	if(root != NULL){
		head();                
		imprimir(root, 1);                    
	}else {
		printf("%-21cArvore nao criada!\n", ' ');
	}	
	system("pause");
}

void sair(Tree *root){
	char opc;
	printf("Deseja sair? [s] para sim::");
	scanf("%c", &opc);
	if(opc == 's' || opc == 'S'){
		freeTree(root);
		exit(EXIT_SUCCESS);		
	}	
}

void menu(){
	head();
	printf("\n%-8c{1}Criar arvore\n", ' ');
	printf("%-8c{2}Imprimir arvore\n", ' ');
	printf("%-8c{3}Buscar na arvore\n", ' ');
	printf("%-8c{4}Sair\n", ' ');
}

int main(){
	char opc;
	Tree *root = criaRaiz();
		while(!EXIT_SUCCESS){
		system("@cls||clear");
		menu();
		printf("\nEscolha::");
		scanf("%c", &opc);
		getchar();
		if(opc == '1')
			insertIntoTree(root);
		if(opc == '2')
			checkImprimir(root);
		if(opc == '3')
			checkBuscar(root);
		if(opc == '4')
			sair(root);
	}	
}



/*
int menu(){
    char op;
    printf("%-10cARVORES BINARIAS - Trabalho 2 (parte 3)\n", ' ');
    
    printf("%c[1] Criar Arvore ", ' ');
    printf("|");
    printf("%c[2] Imprimir ", ' ');
    printf("|");
    printf("%c[3] Buscar ", ' ');
    printf("|");
    printf("%c[4] Sair\n", ' ');
    
    printf("%-26cOpcao: ", ' ');
    scanf("%c", &op);
    fflush(stdin);
    return op;
}


int main() {
    int i = 0, ;
    char valor;
    // Inserção de mais elementos para teste de níveis.
    Tree *root = criaRaiz();
    // Menu
    while(1){
        switch (menu()) {
            case '1':
                if(root == NULL){
                    while(keys[i] != '\0'){
                        root = criaArvore(root, keys[i]);
                        i++;
                    }
                    printf("%-17cArvore criada com sucesso!\n", ' ');
                } else {
                    
                    printf("%-22cArvore ja criada!\n", ' ');   
                }

                break;
            case '2':
                
                if(root != NULL){
                    printf("%-20c[ Arvore Binaria ]\n", ' ');
                    
                    imprimir(root, 1);
                    
                } else {
                    printf("%-21cArvore nao criada!\n", ' ');
                    
                }
                break;
            case '3':          
                
                printf("%-24c[ Buscar ]\n", ' ');
                
                printf("- Informe o valor: ");
                scanf("%c", &valor);
                fflush(stdin);
                buscar(root, valor, aux);
                
                if((*aux) == 1){
                    printf(" Valor Encontrado: { %c }\n", valor);
                } else {   
                    printf(" Valor nao encontrado { %c }\n", valor);
                }
                *aux = 0;
                
                break;
            case '4':
                
                printf("%-24cSaindo...\n", ' ');
                
                exit(0);
            default:
                printf("%-23cOpcao Invalida\n", ' ');
                
                break;
        }
    }

    return 0;
}
*/


