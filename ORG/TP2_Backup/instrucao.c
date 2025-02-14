#include "instrucao.h"

struct instrucao{
	Endereco* add1;
	Endereco* add2;
	Endereco* add3;
	int opcode;
};

struct endereco{
	int endBloco;
	int endPalavra;
};

Endereco* getAdd1(Instrucao* instru){
	return instru->add1;
}

Endereco* getAdd2(Instrucao* instru){
	return instru->add2;
}

Endereco* getAdd3 (Instrucao* instru) {
	return instru->add3;
}

int getOpcode(Instrucao* instru){	
	return instru->opcode;
}

int getEndBloco(Endereco* e){
	return e->endBloco;
}

int getEndPalavra(Endereco* e){
	return e->endPalavra;
}

void setAdd1(Instrucao* instru, Endereco* add1){
	instru->add1 = add1;
}

void setAdd2(Instrucao* instru, Endereco* add2){
	instru->add2 = add2;
}

void setAdd3 (Instrucao* instru, Endereco* add3) {
	instru->add3 = add3;
} 

void setOpcode(Instrucao* instru, int opcode){
	instru->opcode = opcode;
}

void setEndBloco(Endereco* e, int endBloco){
	e->endBloco = endBloco;
}

void setEndPalavra(Endereco* e, int endPalavra){
	e->endPalavra = endPalavra;
}

Instrucao** alocaInstrucao(int tamanho){
	Instrucao** inst = malloc(tamanho * sizeof(Instrucao));
	
	for(int i = 0; i < tamanho; i++){
		inst[i] = malloc(sizeof (Instrucao));
		inst[i]->add1 = malloc(sizeof(Endereco));
		inst[i]->add2 = malloc(sizeof(Endereco));
		inst[i]->add3 = malloc (sizeof(Endereco));
	}
	
	return inst;
}

void lerInstrucao(Instrucao** inst){
	FILE* arquivo;
	arquivo = fopen("instrucoes.txt", "r");
	
	for(int i = 0; i < TAM_INST_GERADOR; i++){
		fscanf(arquivo, "%d",  &inst[i]->opcode);
		fscanf(arquivo, "%d",  &inst[i]->add1->endBloco);
		fscanf(arquivo, "%d",  &inst[i]->add1->endPalavra);
		fscanf(arquivo, "%d",  &inst[i]->add2->endBloco);
		fscanf(arquivo, "%d",  &inst[i]->add2->endPalavra);
		fscanf (arquivo, "%d", &inst[i]->add3->endBloco);
		fscanf (arquivo, "%d", &inst[i]->add3->endPalavra);
	}
	fclose(arquivo);
}

void liberarInstrucao(Instrucao** inst){
	for(int i = 0; i < TAM_INST_GERADOR; i++){
		free(inst[i]->add1);
		free(inst[i]->add2);
		free (inst[i]->add3);
		free(inst[i]);
	}
	free(inst);
}
