#include "../include/mmu.h"
#include <stdlib.h>
#include <stdio.h>
static int contadorLRU = 0; // Contador global para rastrear o último acesso
static int lruIndex = 0;
// Função para atualizar o tempo de acesso de um bloco
void atualizarUltimoAcesso(Cache *cache, int conjunto, int linha) {
    cache->memorySet[conjunto].lines[linha].ultimoAcesso = contadorLRU++;
}

//Funcao para encontrar o conjunto usado a menos tempo
int encontrarLRU(Cache *cache, int conjunto) {
    int menorTempo = cache->memorySet[conjunto].lines[0].ultimoAcesso;

    for (int i = 1; i < 2; i++) { // Como são 2 vias, percorremos apenas as 2 linhas
        if (cache->memorySet[conjunto].lines[i].ultimoAcesso < menorTempo) {
            menorTempo = cache->memorySet[conjunto].lines[i].ultimoAcesso;
            lruIndex = i;
        }
    }
    return lruIndex;
}

BlocoMemoria* MMU_buscarNasMemorias(Endereco *e, RAM* ram, Cache* L1, Cache* L2, Cache* L3) {
    int numConjuntosL1 = L1->numConjuntos;
    int numConjuntosL2 = L2->numConjuntos;
    int numConjuntosL3 = L3->numConjuntos;
    //printf("\n%d %d %dNUmero de conjuntos\n",numConjuntosL1,numConjuntosL2,numConjuntosL3);
    int posicaoCache1 = e->endBloco % numConjuntosL1;
    int posicaoCache2 = e->endBloco % numConjuntosL2;
    int posicaoCache3 = e->endBloco % numConjuntosL3;
    int custo = 0;
    //printf("\n%d %d %d PosicaoCaches\n",posicaoCache1,posicaoCache2,posicaoCache3);

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
    BlocoMemoria* bloco = MMU_movRamCache3(posicaoCache3, L3, ram, e, custo);
    MMU_movCache3Cache2(posicaoCache2, posicaoCache3, L2, L3, custo); // Move de L3 para L2
    MMU_movCache2Cache1(posicaoCache1, posicaoCache2, L1, L2, custo); // Move de L2 para L1
    return bloco;
}


BlocoMemoria* MMU_movCache2Cache1(int posicaoCache1, int posicaoCache2, Cache* L1, Cache* L2, int custo) {
    // Encontra uma posição livre na Cache L1
    for (int i = 0; i < 2; i++) {
        if (!L1->memorySet[posicaoCache1].lines[i].valido) { // Verifica se a linha está vazia
            L1->memorySet[posicaoCache1].lines[i] = L2->memorySet[posicaoCache2].lines[0];
            L1->memorySet[posicaoCache1].lines[i].valido = 1; // Marca como válida
            L1->memorySet[posicaoCache1].lines[i].custo = custo;
            L1->memorySet[posicaoCache1].lines[i].cacheHit = 2;
            atualizarUltimoAcesso(L1, posicaoCache1, i);
            return &L1->memorySet[posicaoCache1].lines[i];
        }
    }

    // Substitui o LRU do conjunto correto
    lruIndex = encontrarLRU(L1, posicaoCache1);
    L1->memorySet[posicaoCache1].lines[lruIndex] = L2->memorySet[posicaoCache2].lines[0];
    L1->memorySet[posicaoCache1].lines[lruIndex].custo = custo;
    L1->memorySet[posicaoCache1].lines[lruIndex].cacheHit = 2; // Encontrado na L2
    atualizarUltimoAcesso(L1, posicaoCache1, lruIndex);

    return &L1->memorySet[posicaoCache1].lines[lruIndex];
}

BlocoMemoria* MMU_movCache3Cache2(int posicaoCache2, int posicaoCache3, Cache* L2, Cache* L3, int custo) {
    // Encontra posição livre na Cache L2
    for (int i = 0; i < 2; i++) {
        if (L2->memorySet[posicaoCache2].lines[i].endBloco == -1) {
            L2->memorySet[posicaoCache2].lines[i] = L3->memorySet[posicaoCache3].lines[0];
            L2->memorySet[posicaoCache2].lines[i].custo = custo;
            L2->memorySet[posicaoCache2].lines[i].cacheHit = 3; // Encontrado na L3
            return &L2->memorySet[posicaoCache2].lines[i];
        }
    }

    // Substitui LRU na L2
    lruIndex = encontrarLRU(L2, posicaoCache2);
    BlocoMemoria blocoAux = L2->memorySet[posicaoCache2].lines[lruIndex];
    L2->memorySet[posicaoCache2].lines[lruIndex] = L3->memorySet[posicaoCache3].lines[0];
    L2->memorySet[posicaoCache2].lines[lruIndex].custo = custo;
    L2->memorySet[posicaoCache2].lines[lruIndex].cacheHit = 3; // Encontrado na L3
    atualizarUltimoAcesso(L2, posicaoCache2, lruIndex);

    return &L2->memorySet[posicaoCache2].lines[lruIndex];
}
BlocoMemoria* MMU_movRamCache3(int posicaoCache3, Cache* L3, RAM* ram, Endereco *e, int custo) {
    // Tenta encontrar posição livre na L3
    for (int i = 0; i < 2; i++) {
        if (L3->memorySet[posicaoCache3].lines[i].endBloco == -1) {
            L3->memorySet[posicaoCache3].lines[i] = RAM_getDado(ram, e->endBloco);
            L3->memorySet[posicaoCache3].lines[i].cacheHit = 4;
            atualizarUltimoAcesso(L3, posicaoCache3, i);
            return &L3->memorySet[posicaoCache3].lines[i];
        }
    }

    // Substitui LRU na L3
    lruIndex = encontrarLRU(L3, posicaoCache3);
    //printf("\n%d LRUINDEX\n", lruIndex);
    // Move o bloco substituído da L3 para a RAM (se atualizado)
    if (L3->memorySet[posicaoCache3].lines[lruIndex].atualizado) {
        RAM_setDado(ram, L3->memorySet[posicaoCache3].lines[lruIndex].endBloco,
                    &L3->memorySet[posicaoCache3].lines[lruIndex]);
    }

    // Insere novo bloco da RAM na L3
    L3->memorySet[posicaoCache3].lines[lruIndex] = RAM_getDado(ram, e->endBloco);
    L3->memorySet[posicaoCache3].lines[lruIndex].cacheHit = 4;
    atualizarUltimoAcesso(L3, posicaoCache3, lruIndex);

    return &L3->memorySet[posicaoCache3].lines[lruIndex];
}

BlocoMemoria* MMU_movCache2ParaCache3(int posicaoCache3, int posicaoCache2, Cache* L3, Cache* L2, int custo) {
    // Encontra posição livre na L3
    for (int i = 0; i < 2; i++) {
        if (L3->memorySet[posicaoCache3].lines[i].endBloco == -1) {
            L3->memorySet[posicaoCache3].lines[i] = L2->memorySet[posicaoCache2].lines[0];
            L3->memorySet[posicaoCache3].lines[i].custo = custo;
            atualizarUltimoAcesso(L3, posicaoCache3, i);
            return &L3->memorySet[posicaoCache3].lines[i];
        }
    }

    // Substitui LRU na L3
    lruIndex = encontrarLRU(L3, posicaoCache3);
    //printf("\n%d LRUINDEX\n", lruIndex);
    L3->memorySet[posicaoCache3].lines[lruIndex] = L2->memorySet[posicaoCache2].lines[0];
    atualizarUltimoAcesso(L3, posicaoCache3, lruIndex);

    return &L3->memorySet[posicaoCache3].lines[lruIndex];
}

BlocoMemoria* MMU_movCache1ParaCache2(int posicaoCache2, int posicaoCache1, Cache* L2, Cache* L1, int custo, Cache* L3){
    // Encontra posição livre na L2
    for (int i = 0; i < 2; i++) {
        if (L2->memorySet[posicaoCache2].lines[i].endBloco == -1) {
            L2->memorySet[posicaoCache2].lines[i] = L1->memorySet[posicaoCache1].lines[0];
            L2->memorySet[posicaoCache2].lines[i].custo = custo;
            atualizarUltimoAcesso(L2, posicaoCache2, i);
            return &L2->memorySet[posicaoCache2].lines[i];
        }
    }

    // Substitui LRU na L2
    lruIndex = encontrarLRU(L2, posicaoCache2);
    //printf("\n%d LRUINDEX\n", lruIndex);
    //BlocoMemoria aux = L2->memorySet[posicaoCache2].lines[lruIndex];
    L2->memorySet[posicaoCache2].lines[lruIndex] = L1->memorySet[posicaoCache1].lines[0];
    atualizarUltimoAcesso(L2, posicaoCache2, lruIndex);

    int endBloco = L1->memorySet[posicaoCache1].lines[0].endBloco;
    int posicaoCache3 = endBloco % L3->numConjuntos;
    // Move o bloco substituído da L2 para L3
    MMU_movCache2ParaCache3(posicaoCache3, posicaoCache2, L3, L2, custo); // Implementada abaixo

    return &L2->memorySet[posicaoCache2].lines[lruIndex];
}

