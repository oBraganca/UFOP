#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>

struct pacote {
    char name[51];
    int code;
    float weight;
};

void swap(Pacote*, Pacote*);
int partition(Pacote*, int, int);
void quick(Pacote*, int, int);

// Manter como especificado
Pacote *alocaVetor(int n) {
    return (Pacote*) malloc(sizeof(Pacote)*n);
}

// Manter como especificado
void desalocaVetor(Pacote** pacotes) {
    free(*pacotes);
}

// Manter como especificado
void lePacotes(Pacote* pacotes, int n) {
    for(int i=0; i<n; i++){
        scanf("%s%d%f", pacotes[i].name, &pacotes[i].code, &pacotes[i].weight);
    }
}

// Manter como especificado
void ordenarPacotes(Pacote* pacotes, int n) {
    quick(pacotes, 0, n-1);
}

// Manter como especificado
void imprimirPacotes(Pacote* pacotes, int n) {
    for(int i =0; i<n; i++){
        printf("%s %d %.1f\n", pacotes[i].name, pacotes[i].code, pacotes[i].weight);
    }
}

// Manter como especificado
void swap(Pacote* a, Pacote* b) {
    Pacote t = *a;
    *a = *b;
    *b = t;
}

// Manter como especificado
int partition(Pacote* pacotes, int p, int r) {
    Pacote pivot = pacotes[r];
    int i = p-1;

    for(int j=p; j<r; j++){
        if(pacotes[j].weight < pivot.weight){
            i++;
            swap(pacotes+i, pacotes+j);
        }else if(pacotes[j].weight == pivot.weight){
            if(pacotes[j].code < pivot.code){
                i++;
                swap(pacotes+i, pacotes+j);
            }
        }
    }

    swap(pacotes+(i+1), pacotes+r);
    return i+1;
}

// Manter como especificado
void quick(Pacote* pacotes, int p, int r) {
    if(p < r){
        int pi = partition(pacotes, p, r);
        quick(pacotes, p, pi - 1);
        quick(pacotes, pi + 1, r);
    }
}
