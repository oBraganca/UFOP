#ifndef BLOCONMEMORIA_H
#define BLOCONMEMORIA_H

typedef struct {
    int palavras[4];
    int endBloco;
    int atualizado;
    int custo;
    int cacheHit;
} BlocoMemoria;

#endif // BLOCONMEMORIA_H