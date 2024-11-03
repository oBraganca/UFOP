/*
 Thayllon Ryan Bragança de Almeida
 24.1.9902
 Questão 02
 */
#include <stdio.h>
#include <stdlib.h>


// Recebe uma matriz, duas dimensões m e n, e um valor e retorna 1 caso encontre o valor na matriz, e 0 caso contrário
int procura_valor(int **A, int m, int n, int valor);

// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
int** criaMatriz(int m, int n);

// libera o espaço utilizado por uma matriz
void liberaMatriz(int** A, int m);

int main(){
    int n=0, m=0;

    printf("Digite o valor de m e n: ");
    scanf("%d%d",&m,&n);

    int **ma = criaMatriz(m, n);
    printf("\nDigite a matriz: ");
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", (*(ma+i)+j));
        }
    }

    printf("\nDigite o valor a ser procurado: ");
    int nu=0;


    scanf("%d",&nu);

    int pr = procura_valor(ma, m, n, nu);
    if(pr){
        printf("\nValor encontrado!\n");
    }else{
        printf("\nValor não encontrado!\n");
    }

    liberaMatriz(ma, m);


    return 0;
}

int procura_valor(int **A, int m, int n, int valor){
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            if(*(*(A+i)+j) == valor){
                return 1;
            }
        }
    }
    return 0;
}

int ** criaMatriz(int m, int n){
    int **matriz=NULL;
    matriz = malloc(m*sizeof(int*));
    for(int i=0; i<m; i++){
        *(matriz+i) = malloc(n*sizeof(int));
    }

    return matriz;
}

void liberaMatriz(int ** A, int m){

    for(int i=0; i<m; i++){
        free(*(A+i));
    }
    free(A);

}
