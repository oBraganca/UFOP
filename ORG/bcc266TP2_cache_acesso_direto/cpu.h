#ifndef CPU_H
#define CPU_H

#include "blocoMemoria.h"
#include "instrucao.h"
#include "ram.h"

typedef struct {
    BlocoMemoria* registrador1;
    BlocoMemoria* registrador2;
    BlocoMemoria* registrador3;
    int PC;
    Instrucao* programa;
    int opcode;
    int custo;
    int missC1;
    int hitC1;
    int missC2;
    int hitC2;
    Cache* L1;
    Cache* L2;
    Cache* L3;
} CPU;

void CPU_setPrograma(CPU* cpu, Instrucao* programaAux);
Cache* CPU_iniciarCache(int tamanho);
void CPU_iniciar(CPU* cpu, RAM* ram, int lengthL1, int lengthL2, int lengthL3);

#endif // CPU_H