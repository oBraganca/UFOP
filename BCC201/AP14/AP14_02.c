/*
 * Thayllon Bragança
 * 24.1.9902
 * Questão 02
 */

#include <stdio.h>
#include <stdlib.h>

// Recebe uma matriz e seus índices e retorna a matriz transposta
double** transposta(double **A, int m, int n);

// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
double** criaMatriz(int m, int n);

// libera o espaço utilizado por uma matriz
void liberaMatriz(double** A, int m);


void printMatriz(double** A, int m, int n);

int main(){
    printf("Digite o valor de m e n: ");
    int m=0,n=0;
    scanf("%d%d", &m, &n);

    double **A;
    A = criaMatriz(m, n);

    if(A == NULL){
        printf("\nNão foi possível criar a matriz, tente novamente\n");
        return 0;
    }
    printf("\nDigite a matriz: ");
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            scanf("%lf", (*(A+i)+j));
        }
    }

    double **B = transposta(A, m, n);

    printf("\nTransposta:\n");
    printMatriz(B, n, m);

    liberaMatriz(A, m);
    liberaMatriz(B, n);

    return 0;
}


// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
double** criaMatriz(int m, int n){

    double **A = NULL;
    A = (double**)malloc(m*sizeof(double*));
    for(int i =0; i<m; i++){
        *(A+i) = (double*)malloc(n*sizeof(double));
    }

    return A;
}

// Recebe uma matriz e seus índices e retorna a matriz transposta
double** transposta(double **A, int m, int n){
    double **B=NULL;
    B = criaMatriz(n, m);

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            *(*(B+i)+j) = *(*(A+j)+i);
        }
    }

    return B;
}

void printMatriz(double **A, int m, int n){
    for(int i =0; i<m; i++){
        for(int j =0; j<n-1; j++){
            printf("%.0lf ", *(*(A+i)+j));
        }
        printf("%.0lf\n",*(*(A+i)+n-1));
    }
}

// libera o espaço utilizado por uma matriz
void liberaMatriz(double** A, int m){

    for(int i =0; i<m; i++){
        free(*(A+i));
    }

    free(A);
}
