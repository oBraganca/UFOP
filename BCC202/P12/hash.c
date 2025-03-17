#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void inicia (Hash *hash, int m, int p) {
    hash->chaves = (Chave*) malloc(sizeof(Chave) * m);
    hash->pesos = (int*) malloc(sizeof(int) * p);
    hash->m = m;
    hash->p = p;

    for (int i=1;i<p+1;i++)
        hash->pesos[i-1] = i;

    for (int i=0;i<m;i++)
        strcpy(hash->chaves[i], "");
}

// Manter como especificado
void libera(Hash *hash) {
  free(hash->chaves);
  free(hash->pesos);
  free(hash);
}

int H(Hash* hash, Chave chave) {
    unsigned int soma = 0;
    for (int i=0;i<strlen(chave);i++)
      soma += (chave[i] * hash->pesos[i % hash->p]);
    return soma % hash->m;
}

// Manter como especificado
int insere (Hash *hash, Chave chave) {
    int j=0;

    int h = H(hash, chave);

    while (j<hash->m && strcmp(hash->chaves[(h+j) % hash->m], chave) && strcmp(hash->chaves[(h+j) % hash->m], "")) {
      j++;
    }

    if(!strcmp(hash->chaves[(h+j) % hash->m], chave)){
        return -1;
    }


    if(j<hash->m){
        strcpy(hash->chaves[(h+j) % hash->m], chave);
        return (h+j) % hash->m;
    }
    return 0;
}
