/*
 * Thayllon Bragança
 * 24.1.9902
 * Questão 02
 */

#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q);

// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
int** criaMatriz(int m, int n);

// libera o espaço utilizado por uma matriz
void liberaMatriz(int** A, int m);

void printMatriz(int** A, int m, int n);

int main(){

    int **A, **B, **R;

    printf("Digite os tamanhos da matriz A: ");
    int ma=0,na=0;
    scanf("%d%d", &ma, &na);


    A = criaMatriz(ma, na);


    printf("\nDigite os dados da matriz A: ");
    for(int i =0; i<ma; i++){
        for(int j =0; j<na; j++){
            scanf("%d", (*(A+i)+j));
        }
    }

    if(A == NULL){
        printf("\nNão foi possível criar a matriz, tente novamente\n");
        return 0;
    }



    printf("\nDigite os tamanhos da matriz B: ");
    int mb=0,nb=0;
    scanf("%d%d", &mb, &nb);

    B = criaMatriz(mb, nb);


    printf("\nDigite os dados da matriz B: ");
    for(int i =0; i<mb; i++){
        for(int j =0; j<nb; j++){
            scanf("%d", (*(B+i)+j));
        }
    }

    if(B == NULL){
        printf("\nNão foi possível criar a matriz, tente novamente\n");
        liberaMatriz(A, ma);
        return 0;
    }


    int r = multiplicaMatrizes(&R, A, ma, na, B, mb, nb);

    if(r < 0){

        printf("\nNão é possível multiplicar as matrizes A e B.\n");
        liberaMatriz(A, ma);
        liberaMatriz(B, mb);
        return 0;
    }else if(!r){
        printf("\nNão é possível criar matriz, tente novamente.\n");
        liberaMatriz(A, ma);
        liberaMatriz(B, mb);
    }else{

        printf("\nResultado de A x B: \n");
        printMatriz(R, ma, nb);

        liberaMatriz(A, ma);
        liberaMatriz(B, mb);
        liberaMatriz(R, ma);
    }

    return 0;
}



// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
int** criaMatriz(int m, int n){

    int **A = NULL;
    A = (int**)malloc(m*sizeof(int*));
    for(int i =0; i<m; i++){
        *(A+i) = (int*)malloc(n*sizeof(int));
    }

    return A;
}

// Recebe uma matriz e seus índices e retorna a matriz transposta
int** transposta(int **A, int m, int n){
    int **B=NULL;
    B = criaMatriz(n, m);

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            *(*(B+i)+j) = *(*(A+j)+i);
        }
    }

    return B;
}

void printMatriz(int **A, int m, int n){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d", *(*(A + i) + j));
            if (j < n - 1) {
                printf(" ");  // Espaço entre os elementos da linha
            }
        }
        printf("\n");  // Quebra de linha após imprimir cada linha da matriz
    }
}

// libera o espaço utilizado por uma matriz
void liberaMatriz(int** A, int m){

    for(int i =0; i<m; i++){
        free(*(A+i));
    }

    free(A);
}

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q){

    if (m != p) {
        return -1; // As dimensões são incompatíveis para multiplicação
    }

    *R = (int**)malloc(n * sizeof(int*));
    if (*R == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        (*R)[i] = (int*)malloc(q * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            (*R)[i][j] = 0;
            for (int k = 0; k < m; k++) {
                (*R)[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return 1;
}
