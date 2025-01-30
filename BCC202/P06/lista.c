#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 10

struct lista {
    int elements[MAX_TAM];
    int lenght;
    int first;
    int last;
};

Lista* cria () {
    Lista *lista = (Lista*)malloc(sizeof(Lista));

    lista->lenght=0;
    lista->first=0;
    lista->last=0;

    return lista;
}

Lista* libera (Lista *lista) {
    free(lista);
    return NULL;
}

void imprime (Lista *lista) {
    int i = lista->first;
    while(i!=lista->last+1){
        printf("%d ",lista->elements[i]);
        i = (i + 1) % MAX_TAM;
    }
    printf("\n");

}

bool pertence (Lista *lista, int chave) {
    int i = lista->first;
    while(i!=lista->last){
        if(chave==lista->elements[i]){
            return 1;
        }
        i = (i + 1) % MAX_TAM;
    }
    return 0;
}

bool insereOrdenado (Lista *lista, int chave) {
    if(lista->lenght==0){
        lista->elements[lista->first] = chave;
        lista->lenght++;
        return 1;
    }

    if(lista->lenght+1 > MAX_TAM) return 0;

    int i = lista->first;
    int aux = -1;
    while(i!=lista->last+1){
        if(chave<lista->elements[i]){
            aux = lista->elements[i];
            lista->elements[i] = chave;
            chave = aux;
        }
        i = (i + 1) % MAX_TAM;
    }

    lista->elements[i] = chave;
    lista->last = (lista->last + 1 + MAX_TAM) % MAX_TAM;
    lista->lenght++;

    return aux;
}

bool retiraEspecifico(Lista *lista, int chave) {
    if (lista->lenght == 0) {
        return 1;
    }

    int i = lista->first;
    int aux = 0;

    while (i != (lista->last + 1) % MAX_TAM) {
        if (lista->elements[i] == chave && aux == 0) {
            aux = 1;
        }

        if (aux) {
            int nextIndex = (i + 1) % MAX_TAM;
            lista->elements[i] = lista->elements[nextIndex];
        }

        i = (i + 1) % MAX_TAM;
    }

    if (!aux) {
        return 0;
    }

    lista->last = (lista->last - 1 + MAX_TAM) % MAX_TAM;
    lista->lenght--;

    return 1;
}

bool retiraInicio (Lista *lista) {
    if(lista->lenght==0){
        return 1;
    }
    lista->first++;
    lista->lenght--;
    return 1;
}

int posicaoInicialLista(Lista *lista) {
    return lista->first;
}