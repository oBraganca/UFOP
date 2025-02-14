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
    BlocoMemoria* cache1;
    BlocoMemoria* cache2;
} CPU;

void CPU_setPrograma(CPU* cpu, Instrucao* programaAux);
BlocoMemoria* CPU_iniciarCache(int tamanho);
void CPU_iniciar(CPU* cpu, RAM* ram, int tamanhoCache1, int tamanhoCache2);

#endif // CPU_H