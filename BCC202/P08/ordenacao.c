#include "ordenacao.h"
#include <stdlib.h>
#include <string.h>

// Manter como especificado
Pessoa *alocaVetor(int n) {
    return (Pessoa*)malloc(sizeof(Pessoa)*n);
}

// Manter como especificado
void desalocaVetor(Pessoa **vetor) {
    free(*vetor);
    *vetor = NULL;
}

// implemente sua funcao do mergesort, que deve invocar a funcao merge
void MergeSort(Pessoa *vetor, int esquerda, int direita)
{
    if(esquerda<direita){
        int meio = esquerda+(direita-direita)/2;
        MergeSort(vetor, esquerda, meio);
        MergeSort(vetor, meio+1, direita);
        merge(vetor, esquerda, meio, direita);
    }

}

// implemente sua funcao do mergesort, que deve invocar a funcao merge
void merge(Pessoa *vetor, int esquerda, int meio, int direita)
{

    int i, j, k, n1=meio-esquerda+1, n2 = direita-esquerda;

    Pessoa *l = alocaVetor(n1);
    Pessoa *r = alocaVetor(n2);


    for (i = 0; i < n1; i++)
        l[i] = vetor[esquerda + i];
    for (j = 0; j < n2; j++)
        r[j] = vetor[meio + 1 + j];

    i=0, j=0, k=esquerda;

    while (i < n1 && j < n2) {
        int comparing = strcmp(l[i].nome, r[j].nome);
        if (comparing < 0) {
            vetor[k] = l[i];
            i++;
        }else if(comparing == 0 && l->idade <= r->idade){
            vetor[k] = l[i];
            i++;
        } else if(comparing==0 && l->idade > r->idade){
            vetor[k] = r[j];
            j++;
        }else{
            vetor[k] = r[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        vetor[k] = l[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        vetor[k] = r[j];
        j++;
        k++;
    }
}

