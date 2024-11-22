#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz {
    double **values;
    int n;
};

Matriz* alocar(int n) {
    
    
    Matriz* M = (Matriz*)malloc(n*sizeof(Matriz));
    

    M->values = (double**)malloc(n*sizeof(double**));
    for(int i =0; i<n; i++){
        *(M->values+i) = (double*)malloc(n*sizeof(double));
    }

    M->n = n;

    return M;
}

Matriz* desalocar(Matriz *matriz) {

    for(int i =0; i<matriz->n; i++){
        free(*(matriz->values+i));
    }


    free(matriz->values);
    free(matriz);

    return NULL;
}

void le(Matriz *matriz) {
        for(int i =0; i<matriz->n; i++){
        for(int j=0; j<matriz->n; j++){
           scanf("%lf", &matriz->values[i][j]); 
        }
    }
}

double somaParte(Matriz *matriz, int *cont) {

    double resultado = 0;
    int aux = 5;
    int aux2 = 0;
    if(matriz->n%2 == 0){
        aux2 = (matriz->n/2)+1;
        aux = (matriz->n/2)-1;
    }else{
        aux2 = (matriz->n/2);
        aux2 = (matriz->n/2)-1;
    }



    for(int i =aux2; i<matriz->n; i++){
        for(int j = aux; j <= matriz->n-1-aux; j++){
            resultado+=matriz->values[i][j];
            (*cont)++;
        }
        aux--;
    }

    return resultado;
}