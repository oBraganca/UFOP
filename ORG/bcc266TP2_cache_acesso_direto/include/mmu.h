#ifndef MMU_H
#define MMU_H

#include "blocoMemoria.h"
#include "ram.h"
#include "endereco.h"

BlocoMemoria* MMU_buscarNasMemorias(Endereco *e, RAM* ram, Cache * cache1, Cache* cache2, Cache* cache3);
BlocoMemoria* MMU_movCache2Cache1(int posicaoCache1, int posicaoCache2, Cache* cache1, Cache* cache2, int custo);
BlocoMemoria* MMU_movRamCache2(int posicaoCache1, int posicaoCache2, Cache* cache1, Cache* cache2, RAM* ram, Endereco *e, int custo);
BlocoMemoria* MMU_movRamCache3(int posicaoCache3, int posicaoCache2, int posicaoCache1, Cache* L1, Cache* L2, Cache* L3, RAM* ram, Endereco *e, int custo) ;
BlocoMemoria* MMU_movCache3Cache2(int posicaoCache2, int posicaoCache3, Cache* L2, Cache* L3, int custo);
void atualizarUltimoAcesso(Cache *cache, int linha);
int encontrarLRU(Cache *cache);

#endif // MMU_H