#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
int* alocaVetor(int n){
    return (int*)malloc(n*sizeof(int));
}

// Manter como especificado
int* desalocaVetor(int* v){
    free(v);
    return NULL;
}

// Manter como especificado
void ordenacao(int* v, int n, int* movimentos){
    for(int i =0; i<n; i++){
        int s=0;
        for(int j=0; j<n-i-1; j++){
            if(v[j]>v[j+1]){
                int a = v[j];
                v[j] = v[j+1];
                v[j+1] = a;
                *movimentos+=1;
                s=1;
            }
        }

        if(!s) break;
    }
}
