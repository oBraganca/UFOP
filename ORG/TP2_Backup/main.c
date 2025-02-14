#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void processador(Instrucao** inst, Memoria** Cache1, Memoria** Cache2, Memoria** Cache3, Memoria** RAM, Taxas* taxas);

int main(){
	
	Instrucao** inst = alocaInstrucao(TAM_INST_GERADOR);
	lerInstrucao(inst);
	Taxas* taxas = criarTaxas();
	
	Memoria** RAM = alocarMemoria(TAM_RAM);
	Memoria** cacheUm = alocarMemoria(TAM_C1);
	Memoria** cacheDois = alocarMemoria(TAM_C2);
	Memoria** cacheTres = alocarMemoria(TAM_C3);
	
	preencherRam(RAM);
	processador(inst, cacheUm, cacheDois, cacheTres, RAM, taxas);
	
	limpaMemoria(cacheUm, TAM_C1);
	limpaMemoria(cacheDois, TAM_C2);
	limpaMemoria(cacheTres, TAM_C3);

	printf("\n\tCACHE HIT CACHE 1: %d", getHitC1(taxas));
	printf("\t\tCACHE MISS CACHE 1: %d\n", getMissC1(taxas));
	printf("\tCACHE HIT CACHE 2: %d", getHitC2(taxas));
	printf("\t\tCACHE MISS CACHE 2: %d\n", getMissC2(taxas));
	printf("\tCACHE HIT CACHE 3: %d", getHitC3(taxas));
	printf("\t\tCACHE MISS CACHE 3: %d\n", getMissC3(taxas));
	printf ("\tCACHE HIT RAM: %d\n", getHitRam (taxas));
	printf("\n\t-CUSTO TOTAL: %d", getCusto(taxas));
	printf("\t-TOTAL DE HIT: %d", getHitC1(taxas) + getHitC2(taxas) + getHitC3(taxas) + getHitRam (taxas));
	printf("\t-TOTAL DE MISS: %d\n", getMissC1(taxas) + getMissC2(taxas) + getMissC3(taxas));
	
	liberarMemoria(cacheUm, TAM_C1);
	liberarMemoria(cacheDois, TAM_C2);
	liberarMemoria(cacheTres, TAM_C3);
	liberarMemoria(RAM, TAM_RAM);
	return 0;
}

void processador(Instrucao** inst, Memoria** Cache1, Memoria** Cache2, Memoria** Cache3, Memoria** RAM, Taxas* taxas){
	int conteudoUm, conteudoDois, conteudoTres = 0, indice = 0;
	Memoria* dadoMemoriaEnd1 = alocarVetor();
	Memoria* dadoMemoriaEnd2 = alocarVetor();
	Memoria* dadoMemoriaEnd3 = alocarVetor();
	while(getOpcode(inst[indice]) != -1){
		switch(getOpcode(inst[indice])){
			case 0:
				dadoMemoriaEnd1 = MMU(Cache1, Cache2, Cache3, RAM, getAdd1(inst[indice]), taxas);
				dadoMemoriaEnd2 = MMU(Cache1, Cache2, Cache3, RAM, getAdd2(inst[indice]), taxas);
				dadoMemoriaEnd3 = MMU(Cache1, Cache2, Cache3, RAM, getAdd3(inst[indice]), taxas);
				
				conteudoUm = getPalavra(dadoMemoriaEnd1, getEndPalavra(getAdd1(inst[indice])));
				conteudoDois = getPalavra(dadoMemoriaEnd2, getEndPalavra(getAdd2(inst[indice])));
				conteudoTres = getPalavra(dadoMemoriaEnd3, getEndPalavra(getAdd3(inst[indice])));
				
				conteudoTres = conteudoUm + conteudoDois;

				insereCache(conteudoTres, Cache1, getAdd3(inst[indice]));

				//printf("\n\tSOMA: %d + %d = %d", conteudoUm, conteudoDois, operacao);
				break;
			case 1:
				dadoMemoriaEnd1 = MMU(Cache1, Cache2, Cache3, RAM, getAdd1(inst[indice]), taxas);
				dadoMemoriaEnd2 = MMU(Cache1, Cache2, Cache3, RAM, getAdd2(inst[indice]), taxas);
				dadoMemoriaEnd3 = MMU(Cache1, Cache2, Cache3, RAM, getAdd3(inst[indice]), taxas);
				
				conteudoUm = getPalavra(dadoMemoriaEnd1, getEndPalavra(getAdd1(inst[indice])));
				conteudoDois = getPalavra(dadoMemoriaEnd2, getEndPalavra(getAdd2(inst[indice])));
				
				conteudoTres = conteudoUm - conteudoDois;
				

				insereCache(conteudoTres, Cache1, getAdd3(inst[indice])/*, tempoInicial*/);

				//printf("\n\tSUB: %d - %d = %d", conteudoUm, conteudoDois, operacao);
				break;

			default: 
				break;
		}
		indice++;
	}
	liberarVetor(dadoMemoriaEnd1);
	liberarVetor(dadoMemoriaEnd2);
}
