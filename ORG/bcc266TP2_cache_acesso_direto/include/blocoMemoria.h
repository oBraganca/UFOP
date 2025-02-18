#ifndef BLOCONMEMORIA_H
#define BLOCONMEMORIA_H

#include <time.h>  // Para usar a função time()

typedef struct {
    int palavras[4];
    int endBloco;
    int atualizado;
    int custo;
    int cacheHit;
    time_t ultimoAcesso;  // Adicionando o tempo do último acesso
} BlocoMemoria;

typedef struct {
    BlocoMemoria * lines;
}MemorySet;

typedef struct{
    MemorySet * memorySet;
}Cache;

#endif // BLOCONMEMORIA_H