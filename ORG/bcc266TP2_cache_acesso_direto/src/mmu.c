#include "../include/mmu.h"
#include <stdlib.h>

// Função para atualizar o tempo de acesso de um bloco
void atualizarUltimoAcesso(Cache *cache, int linha) {
    cache->memorySet->lines[linha].ultimoAcesso = time(NULL);
}

// Função para encontrar o bloco menos recentemente usado (LRU)
int encontrarLRU(Cache *cache) {
    int lruIndex = 0;
    time_t menorTempo = time(NULL);  // Inicializa com o tempo atual
    for (int i = 0; i < cache->memorySet->numLinhas; i++) {
        if (cache->memorySet->lines[i].ultimoAcesso < menorTempo) {
            menorTempo = cache->memorySet->lines[i].ultimoAcesso;
            lruIndex = i;
        }
    }
    return lruIndex;
}

BlocoMemoria* MMU_buscarNasMemorias(Endereco *e, RAM* ram, Cache* L1, Cache* L2, Cache* L3) {
    int numConjuntosL1 = sizeof(*L1->memorySet) / sizeof(L1->memorySet[0]);
    int numConjuntosL2 = sizeof(*L2->memorySet) / sizeof(L2->memorySet[0]);
    int numConjuntosL3 = sizeof(*L3->memorySet) / sizeof(L3->memorySet[0]);

    int posicaoCache1 = e->endBloco % numConjuntosL1;
    int posicaoCache2 = e->endBloco % numConjuntosL2;
    int posicaoCache3 = e->endBloco % numConjuntosL3;
    int custo = 0;

    // Verifica na Cache L1 (2 posições por conjunto)
    for (int i = 0; i < 2; i++) {
        if (L1->memorySet[posicaoCache1].lines[i].endBloco == e->endBloco) {
            custo = 10;
            L1->memorySet[posicaoCache1].lines[i].custo = custo;
            L1->memorySet[posicaoCache1].lines[i].cacheHit = 1;
            return &L1->memorySet[posicaoCache1].lines[i];
        }
    }

    // Verifica na Cache L2 (2 posições por conjunto)
    for (int i = 0; i < 2; i++) {
        if (L2->memorySet[posicaoCache2].lines[i].endBloco == e->endBloco) {
            custo = 110;
            L2->memorySet[posicaoCache2].lines[i].cacheHit = 2;
            return MMU_movCache2Cache1(posicaoCache1, posicaoCache2, L1, L2, custo);
        }
    }

    // Verifica na Cache L3 (2 posições por conjunto)
    for (int i = 0; i < 2; i++) {
        if (L3->memorySet[posicaoCache3].lines[i].endBloco == e->endBloco) {
            custo = 1110;
            L3->memorySet[posicaoCache3].lines[i].cacheHit = 3;
            return MMU_movCache3Cache2(posicaoCache2, posicaoCache3, L2, L3, custo);
        }
    }

    // Se não encontrou em nenhuma cache, busca na RAM e move para a Cache L3
    custo = 11110;
    return MMU_movRamCache3(posicaoCache3, posicaoCache2, posicaoCache1, L1, L2, L3, ram, e, custo);
}

BlocoMemoria* MMU_movCache2Cache1(int posicaoCache1, int posicaoCache2, Cache* L1, Cache* L2, int custo) {
    // Encontra uma posição livre na Cache L1 (2 posições por conjunto)
    for (int i = 0; i < 2; i++) {
        if (L1->memorySet[posicaoCache1].lines[i].endBloco == -1) { // Assume que -1 indica posição livre
            // Move o bloco da Cache L2 para a Cache L1
            L1->memorySet[posicaoCache1].lines[i] = L2->memorySet[posicaoCache2].lines[0];
            L1->memorySet[posicaoCache1].lines[i].custo = custo;
            return &L1->memorySet[posicaoCache1].lines[i];
        }
    }

    // Se não houver posição livre, substitui o primeiro bloco do conjunto
    BlocoMemoria aux = L1->memorySet[posicaoCache1].lines[0];
    L1->memorySet[posicaoCache1].lines[0] = L2->memorySet[posicaoCache2].lines[0];
    L2->memorySet[posicaoCache2].lines[0] = aux;

    L1->memorySet[posicaoCache1].lines[0].custo = custo;
    return &L1->memorySet[posicaoCache1].lines[0];
}

BlocoMemoria* MMU_movCache3Cache2(int posicaoCache2, int posicaoCache3, Cache* L2, Cache* L3, int custo) {
    // Encontra uma posição livre na Cache L2 (2 posições por conjunto)
    for (int i = 0; i < 2; i++) {
        if (L2->memorySet[posicaoCache2].lines[i].endBloco == -1) { // Assume que -1 indica posição livre
            // Move o bloco da Cache L3 para a Cache L2
            L2->memorySet[posicaoCache2].lines[i] = L3->memorySet[posicaoCache3].lines[0];
            L2->memorySet[posicaoCache2].lines[i].custo = custo;
            return &L2->memorySet[posicaoCache2].lines[i];
        }
    }

    // Se não houver posição livre, substitui o primeiro bloco do conjunto
    BlocoMemoria aux = L2->memorySet[posicaoCache2].lines[0];
    L2->memorySet[posicaoCache2].lines[0] = L3->memorySet[posicaoCache3].lines[0];
    L3->memorySet[posicaoCache3].lines[0] = aux;

    L2->memorySet[posicaoCache2].lines[0].custo = custo;
    return &L2->memorySet[posicaoCache2].lines[0];
}

BlocoMemoria* MMU_movRamCache3(int posicaoCache3, int posicaoCache2, int posicaoCache1, Cache* L1, Cache* L2, Cache* L3, RAM* ram, Endereco *e, int custo) {
    // Verifica se o bloco na Cache L3 está atualizado
    for (int i = 0; i < 2; i++) {
        if (!L3->memorySet[posicaoCache3].lines[i].atualizado) {
            // Busca o bloco na RAM e move para a Cache L3
            L3->memorySet[posicaoCache3].lines[i] = RAM_getDado(ram, e->endBloco);
            L3->memorySet[posicaoCache3].lines[i].cacheHit = 4; // Indica que o bloco veio da RAM para L3
            return MMU_movCache3Cache2(posicaoCache2, posicaoCache3, L2, L3, custo);
        }
    }

    // Se não houver posição livre, substitui o primeiro bloco do conjunto
    L3->memorySet[posicaoCache3].lines[0].atualizado = 0;
    L3->memorySet[posicaoCache3].lines[0].cacheHit = 0;
    L3->memorySet[posicaoCache3].lines[0].custo = 0;
    RAM_setDado(ram, L3->memorySet[posicaoCache3].lines[0].endBloco, &L3->memorySet[posicaoCache3].lines[0]);

    // Busca o novo bloco na RAM e move para a Cache L3
    L3->memorySet[posicaoCache3].lines[0] = RAM_getDado(ram, e->endBloco);
    L3->memorySet[posicaoCache3].lines[0].cacheHit = 4; // Indica que o bloco veio da RAM para L3

    return MMU_movCache3Cache2(posicaoCache2, posicaoCache3, L2, L3, custo);
}

BlocoMemoria* MMU_movRamCache2(int posicaoCache1, int posicaoCache2, Cache* cache1, Cache* cache2, RAM* ram, Endereco *e, int custo) {
    for (int i = 0; i < 2; i++) {
        if (!cache2->memorySet[posicaoCache2].lines[i].atualizado) {
            cache2->memorySet[posicaoCache2].lines[i] = RAM_getDado(ram, e->endBloco);
            cache2->memorySet[posicaoCache2].lines[i].cacheHit = 3;
            return MMU_movCache2Cache1(posicaoCache1, posicaoCache2, cache1, cache2, custo);
        }
    }

    // Se não houver posição livre, substitui o primeiro bloco do conjunto
    cache2->memorySet[posicaoCache2].lines[0].atualizado = 0;
    cache2->memorySet[posicaoCache2].lines[0].cacheHit = 0;
    cache2->memorySet[posicaoCache2].lines[0].custo = 0;
    RAM_setDado(ram, cache2->memorySet[posicaoCache2].lines[0].endBloco, &cache2->memorySet[posicaoCache2].lines[0]);

    cache2->memorySet[posicaoCache2].lines[0] = RAM_getDado(ram, e->endBloco);
    cache2->memorySet[posicaoCache2].lines[0].cacheHit = 3;

    return MMU_movCache2Cache1(posicaoCache1, posicaoCache2, cache1, cache2, custo);
}
