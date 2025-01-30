#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct lista Lista;

Lista* cria();
Lista* libera (Lista *lista);
void imprime (Lista *lista);
bool pertence (Lista *lista, int chave);
bool insereOrdenado (Lista *lista, int chave);
bool retiraEspecifico (Lista *lista, int chave);
bool retiraInicio (Lista *lista);
int posicaoInicialLista(Lista *lista);

#endif // LISTA_H