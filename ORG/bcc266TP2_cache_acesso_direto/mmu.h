#ifndef MMU_H
#define MMU_H

#include "blocoMemoria.h"
#include "ram.h"
#include "endereco.h"

BlocoMemoria* MMU_buscarNasMemorias(Endereco *e, RAM* ram, BlocoMemoria* cache1, BlocoMemoria* cache2);
BlocoMemoria* MMU_movCache2Cache1(int posicaoCache1, int posicaoCache2, BlocoMemoria* cache1, BlocoMemoria* cache2, int custo);
BlocoMemoria* MMU_movRamCache2(int posicaoCache1, int posicaoCache2, BlocoMemoria* cache1, BlocoMemoria* cache2, RAM* ram, Endereco *e, int custo);

#endif // MMU_H