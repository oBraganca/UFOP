#ifndef NONOGRAMA_H
#define NONOGRAMA_H
#include <stdbool.h>

typedef struct{
    int tam;
    int *tamInst;
    int **instrucao;
    int **tabuleiro;
    int numSolucoes;
}Nonogram;



Nonogram* NonogramAllocate(int n);

void NonogramFree(Nonogram *);

void NonogramRead(Nonogram *);

void NonogramPlay(Nonogram *, int, int);

void NonogramPrint(Nonogram *);

bool NonogramVerify(Nonogram *);

bool NonogramVerify2(Nonogram *);

bool NonogramPartialVerify(Nonogram *a, int x, int y);

#endif