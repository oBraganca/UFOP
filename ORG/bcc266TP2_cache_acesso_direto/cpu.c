#include "cpu.h"
#include "mmu.h"
#include "ram.h"
#include <stdio.h>
#include <stdlib.h>

void CPU_setPrograma(CPU* cpu, Instrucao* programaAux) {
    cpu->programa = programaAux;
}

BlocoMemoria* CPU_iniciarCache(int tamanho) {
    BlocoMemoria* umaCache = (BlocoMemoria*)malloc(tamanho * sizeof(BlocoMemoria));
    for (int i = 0; i < tamanho; i++) {
        umaCache[i] = (BlocoMemoria){ .palavras = {0, 0, 0, 0}, .endBloco = 0, .atualizado = 0, .custo = 0, .cacheHit = 0 };
    }
    return umaCache;
}

void CPU_iniciar(CPU* cpu, RAM* ram, int tamanhoCache1, int tamanhoCache2) {
    cpu->cache1 = CPU_iniciarCache(tamanhoCache1);
    cpu->cache2 = CPU_iniciarCache(tamanhoCache2);
    cpu->opcode = 0;
    cpu->PC = 0;

    while (cpu->opcode != -1) {
        Instrucao inst = cpu->programa[cpu->PC];
        cpu->opcode = inst.opcode;

        if (cpu->opcode != -1) {
            cpu->registrador1 = MMU_buscarNasMemorias(inst.add1, ram, cpu->cache1, cpu->cache2);
            cpu->registrador2 = MMU_buscarNasMemorias(inst.add2, ram, cpu->cache1, cpu->cache2);
            cpu->registrador3 = MMU_buscarNasMemorias(inst.add3, ram, cpu->cache1, cpu->cache2);

            switch (cpu->registrador1->cacheHit) {
                case 1: cpu->hitC1++; break;
                case 2: cpu->missC1++; cpu->hitC2++; break;
                case 3: cpu->missC1++; cpu->missC2++; break;
            }

            switch (cpu->registrador2->cacheHit) {
                case 1: cpu->hitC1++; break;
                case 2: cpu->missC1++; cpu->hitC2++; break;
                case 3: cpu->missC1++; cpu->missC2++; break;
            }

            switch (cpu->registrador3->cacheHit) {
                case 1: cpu->hitC1++; break;
                case 2: cpu->missC1++; cpu->hitC2++; break;
                case 3: cpu->missC1++; cpu->missC2++; break;
            }

            switch (cpu->opcode) {
                case -1:
                    printf("programa terminou!!\n");
                    RAM_imprimir(ram);
                    break;
                case 0:
                    cpu->registrador3->palavras[inst.add3->endPalavra] = cpu->registrador1->palavras[inst.add1->endPalavra] + cpu->registrador2->palavras[inst.add2->endPalavra];
                    cpu->registrador3->atualizado = 1;
                    cpu->custo += cpu->registrador1->custo + cpu->registrador2->custo + cpu->registrador3->custo;
                    printf("Inst sum -> RAM posicao %d com conteudo na cache 1 %d\n", inst.add3->endBloco, cpu->registrador3->palavras[inst.add3->endPalavra]);
                    printf("Custo ateh o momento.... %d\n", cpu->custo);
                    printf("Ateh o momento ... Hit C1: %d Miss C1: %d\n", cpu->hitC1, cpu->missC1);
                    printf("Ateh o momento ... Hit C2: %d Miss C2: %d\n", cpu->hitC2, cpu->missC2);
                    break;
                case 1:
                    cpu->registrador3->palavras[inst.add3->endPalavra] = cpu->registrador1->palavras[inst.add1->endPalavra] - cpu->registrador2->palavras[inst.add2->endPalavra];
                    cpu->registrador3->atualizado = 1;
                    cpu->custo += cpu->registrador1->custo + cpu->registrador2->custo + cpu->registrador3->custo;
                    printf("Inst sub -> RAM posicao %d com conteudo na cache 1 %d\n", inst.add3->endBloco, cpu->registrador3->palavras[inst.add3->endPalavra]);
                    printf("Custo ateh o momento.... %d\n", cpu->custo);
                    printf("Ateh o momento ... Hit C1: %d Miss C1: %d\n", cpu->hitC1, cpu->missC1);
                    printf("Ateh o momento ... Hit C2: %d Miss C2: %d\n", cpu->hitC2, cpu->missC2);
                    break;
            }

            cpu->PC++;
        }
    }
}