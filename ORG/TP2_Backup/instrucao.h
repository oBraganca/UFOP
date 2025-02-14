#ifndef INSTRUCAO_H
#define INSTRUCAO_H

#include  <stdio.h>
#include <stdlib.h>

#define TAM_INST_GERADOR 1000

typedef struct instrucao Instrucao;
typedef struct endereco Endereco;

Endereco* getAdd1(Instrucao* instru);
Endereco* getAdd2(Instrucao* instru);
Endereco* getAdd3 (Instrucao* instru);
int getOpcode(Instrucao* instru);
int getEndBloco(Endereco* e);
int getEndPalavra(Endereco* e);

void setAdd1(Instrucao* instru, Endereco* add1);
void setAdd2 (Instrucao* instru, Endereco* add2);
void setAdd3 (Instrucao* instru, Endereco* add3);
void setOpcode (Instrucao* instru, int opcode);
void setEndBloco (Endereco* e, int endBloco);
void setEndPalavra (Endereco* e, int endPalavra);

void lerInstrucao(Instrucao** inst);

Instrucao** alocaInstrucao(int tamanho);
void liberarInstrucao(Instrucao** inst);



#endif

