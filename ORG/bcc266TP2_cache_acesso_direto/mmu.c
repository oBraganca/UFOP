#include "mmu.h"
#include <stdlib.h>

BlocoMemoria* MMU_buscarNasMemorias(Endereco *e, RAM* ram, BlocoMemoria* cache1, BlocoMemoria* cache2) {
    int posicaoCache1 = e->endBloco % (sizeof(*cache1) / sizeof(*cache2));
    int posicaoCache2 = e->endBloco % (sizeof(*cache2) / sizeof(*cache2));
    int custo = 0;

    if (cache1[posicaoCache1].endBloco == e->endBloco) {
        custo = 10;
        cache1[posicaoCache1].custo = custo;
        cache1[posicaoCache1].cacheHit = 1;
        return &cache1[posicaoCache1];
    } else {
        if (cache2[posicaoCache2].endBloco == e->endBloco) {
            custo = 110;
            cache2[posicaoCache2].cacheHit = 2;
            return MMU_movCache2Cache1(posicaoCache1, posicaoCache2, cache1, cache2, custo);
        } else {
            custo = 1110;
            return MMU_movRamCache2(posicaoCache1, posicaoCache2, cache1, cache2, ram, e, custo);
        }
    }
}

BlocoMemoria* MMU_movCache2Cache1(int posicaoCache1, int posicaoCache2, BlocoMemoria* cache1, BlocoMemoria* cache2, int custo) {
    BlocoMemoria aux = cache1[posicaoCache1];
    cache1[posicaoCache1] = cache2[posicaoCache2];
    cache2[posicaoCache2] = aux;

    cache1[posicaoCache1].custo = custo;

    return &cache1[posicaoCache1];
}

BlocoMemoria* MMU_movRamCache2(int posicaoCache1, int posicaoCache2, BlocoMemoria* cache1, BlocoMemoria* cache2, RAM* ram, Endereco *e, int custo) {
    if (!cache2[posicaoCache2].atualizado) {
        cache2[posicaoCache2] = RAM_getDado(ram,e->endBloco);
        cache2[posicaoCache2].cacheHit = 3;
        return MMU_movCache2Cache1(posicaoCache1, posicaoCache2, cache1, cache2, custo);
    } else {
        cache2[posicaoCache2].atualizado = 0;
        cache2[posicaoCache2].cacheHit = 0;
        cache2[posicaoCache2].custo = 0;
        RAM_setDado(ram, cache2[posicaoCache2].endBloco, &cache2[posicaoCache2]);

        cache2[posicaoCache2] = RAM_getDado(ram, e->endBloco);
        cache2[posicaoCache2].cacheHit = 3;

        return MMU_movCache2Cache1(posicaoCache1, posicaoCache2, cache1, cache2, custo);
    }
}