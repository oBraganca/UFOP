#ifndef BLOCONMEMORIA_H
#define BLOCONMEMORIA_H

typedef struct {
    int palavras[4];
    int endBloco;
    int atualizado;
    int custo;
    int cacheHit;
} BlocoMemoria;

typedef struct {
    BlocoMemoria * lines;
}MemorySet;

typedef struct{
    MemorySet * memorySet;
}Cache;

#endif // BLOCONMEMORIA_H