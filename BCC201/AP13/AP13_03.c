/*
 Thayllon Ryan Bragança de Almeida
 24.1.9902
 Questão 03
 */
#include <stdio.h>
#include <stdlib.h>


// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
float** criaMatriz(int m, int n);

// libera o espaço utilizado por uma matriz
void liberaMatriz(float** A, int m);

float * calc_m(float **A, int m, int n);

float m_al(float **A, int m, int n);

int main(){
    printf("Digite o número de delegações: ");
    int d=0;
    scanf("%d", &d);

    printf("\nDigite o número de atletas: ");
    int a=0;
    scanf("%d", &a);

    float **ma = criaMatriz(d, a);
    printf("\nDigite as alturas: ");

    for(int i = 0; i<d; i++){
        printf("Delegação %d:", i+1);
        for(int j=0; j<a; j++){
            printf("\nAtleta %d: ",j+1);
            scanf("%f", (*(ma+i)+j));
        }
        printf("\n");
    }

    printf("Média das Alturas\n");
    float *v = calc_m(ma, d, a);

    for(int i=0; i<d; i++){
        printf("Delegação %d: %.2f\n",i+1, *(v+i));
    }

    float maior = m_al(ma,d,a);
    printf("\nMaior altura: %.2lf\n", maior);

    liberaMatriz(ma, d);

    free(v);

    return 0;
}


float m_al(float **A, int m, int n){
    float ma = A[0][0];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(*(*(A+i)+j) > ma){
                ma = *(*(A+i)+j);
            }
        }
    }

    return ma;
}

float * calc_m(float **A, int m, int n){
    float *v = malloc(m*sizeof(float));
    float al=0.0;
    for(int i=0; i<m; i++){
        al = 0.0;
        for(int j=0; j<n; j++){
            al += *(*(A+i)+j);
        }
        *(v+i) = al/(float)n;
    }

    return v;
}

float ** criaMatriz(int m, int n){
    float **matriz;
    matriz = malloc(m*sizeof(float*));
    for(int i=0; i<m; i++){
        *(matriz+i) = malloc(n*sizeof(float));
    }

    return matriz;
}

void liberaMatriz(float ** A, int m){

    for(int i=0; i<m; i++){
        free(*(A+i));
    }
    free(A);

}
