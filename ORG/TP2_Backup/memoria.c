#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct memoria{
	int endBloco;
	int palavras[4];
	int nAcessos;
	int atualizado; //0 é falso e 1 é verdadeiro
	
};

struct taxas{
	int Miss_c1, Hit_c1;
	int Miss_c2, Hit_c2;
	int Miss_c3, Hit_c3;
	int Hit_ram;
	int custo;
};

//varios blocos
Memoria** alocarMemoria(int tamanho){
	Memoria** memoria = malloc (tamanho * sizeof (Memoria*));

	for(int i = 0; i < tamanho; i++){
		memoria[i] = malloc (sizeof (Memoria));;
		memoria[i]->endBloco = -1;
		for(int j = 0; j < TAM_BLOCO; j++) {
			memoria[i]->palavras[j] = 0;
		}
		memoria[i]->nAcessos = 0;
		memoria[i]->atualizado = 0;
	}

	return memoria;
}

//apenas um bloco
Memoria* alocarVetor(){
	Memoria* memoria = malloc (1 * sizeof (Memoria));

	memoria[0].endBloco = -1;
	for(int i = 0; i < TAM_BLOCO; i++)
		memoria[0].palavras[i] = 0;
	memoria[0].nAcessos = 0;
	memoria[0].atualizado = 0;

	return memoria;
}

Taxas* criarTaxas(){
	Taxas* taxas = malloc (sizeof (Taxas));

	taxas->Miss_c1 = 0;
	taxas->Hit_c1 = 0;
	taxas->Miss_c2 = 0;
	taxas->Hit_c2 = 0;
	taxas->Miss_c3 = 0;
	taxas->Hit_c3 = 0;
	taxas->Hit_ram = 0;
	taxas->custo = 0;

	return taxas;
}

void preencherRam(Memoria** ram){
	srand(time(NULL));
	for(int i = 0; i < TAM_RAM; i++){
		for(int j = 0; j < TAM_BLOCO; j++)
			ram[i]->palavras[j] = rand() % 10;
	}
}

int buscarCache(Endereco* e, Memoria** cache, int tam_cache){ 
	//verifica a existencia do endereco para cada bloco dentro de uma cache
	for(int i = 0; i < tam_cache; i++) {
		if(cache[i]->endBloco == getEndBloco(e)){
			setAcesso(cache[i], 1);
			return i;
		}
	}
	return -1;
}

void insereCache(int valor, Memoria** memoria, Endereco* e){

	for(int i = 0; i < TAM_C1; i++){
		if(memoria[i]->endBloco == getEndBloco(e)){
			memoria[i]->palavras[getEndPalavra(e)] = valor;
			memoria[i]->nAcessos = 0;
			memoria[i]->atualizado = 1;
			break;
		}
	}
}

void trocarCache(int endBloco, Memoria** cOrigem, int tam_cOrigem, Memoria** cDestino, int tam_cDestino){
	int indice = 0; 
	int menorAcesso = cDestino[0]->nAcessos;
	
	for(int i = 0; i < tam_cDestino; i++){
		if(cDestino[i]->endBloco == -1){
			indice = i;
			break;
		} 
		else if(cDestino[i]->nAcessos < menorAcesso){
			menorAcesso = cDestino[i]->nAcessos;
			indice = i;
		} 
	}

	for(int i = 0; i < tam_cOrigem; i++){
		if(cOrigem[i]->endBloco == endBloco){
			Memoria* aux;
			aux = cDestino[indice];
			cDestino[indice] = cOrigem[i];
			cOrigem[i] = aux;
			cDestino[indice]->nAcessos = 0;
			cDestino[indice]->atualizado = 0;
			break;
		}
	}
}

void trocarRam(int endBloco, Memoria** ram, int tam_ram, Memoria** cDestino, int tam_cDestino){
	int indice = 0;
	int menorAcesso = cDestino[0]->nAcessos;

	for(int i = 0; i < tam_cDestino; i++){
		if(cDestino[i]->endBloco == -1){
			indice = i;
			break;
		} 
		else if((cDestino[i]->nAcessos) < menorAcesso){
			menorAcesso = cDestino[i]->nAcessos;
			indice = i;
		} 
		
	}
	if(cDestino[indice]->atualizado == 1){
		Memoria* aux;
		aux = cDestino[indice];
		cDestino[indice] = ram[endBloco];
		ram[endBloco] = aux;
		setEndBlocoM(cDestino[indice], endBloco);
		for(int k = 0; k < TAM_BLOCO; k++){
			setPalavra(cDestino[indice], k, getPalavra(ram[endBloco], k));
		}
		setAcesso(cDestino[indice], 0);
	} else {
		setEndBlocoM(cDestino[indice], endBloco);
		for(int k = 0; k < TAM_BLOCO; k++){
			setPalavra(cDestino[indice], k, getPalavra(ram[endBloco], k));
		}
		setAcesso(cDestino[indice], 0);
	}
}

Memoria* MMU(Memoria** c1, Memoria** c2, Memoria** c3, Memoria** ram, Endereco* e, Taxas* taxas){
	if(buscarCache(e, c1, TAM_C1) != -1){
		setHitC1(taxas, taxas->Hit_c1);
		setCusto(taxas, 10);
	} else if(buscarCache(e, c2, TAM_C2) != -1){
		setMissC1(taxas, taxas->Miss_c1);
		setHitC2(taxas, taxas->Hit_c2);
		setCusto(taxas, 100);
		trocarCache(getEndBloco(e), c2, TAM_C2, c1, TAM_C1);
	} else if(buscarCache(e, c3, TAM_C3) != -1){
		setMissC1(taxas, taxas->Miss_c1);
		setMissC2(taxas, taxas->Miss_c2);
		setHitC3(taxas, taxas->Hit_c3);
		setCusto(taxas, 1000);
		trocarCache(getEndBloco(e), c3, TAM_C3, c2, TAM_C2);
		trocarCache(getEndBloco(e), c2, TAM_C2, c1, TAM_C1);
	} else {
		setMissC1(taxas, taxas->Miss_c1);
		setMissC2(taxas, taxas->Miss_c2);
		setMissC3(taxas, taxas->Miss_c3);
		setHitRam (taxas, taxas->Hit_ram);
		setCusto(taxas, 10000);
		trocarRam(getEndBloco(e), ram, TAM_RAM, c3, TAM_C3);
		trocarCache(getEndBloco(e), c3, TAM_C3, c2, TAM_C2);
		trocarCache(getEndBloco(e), c2, TAM_C2, c1, TAM_C1);
	}
	return c1[buscarCache(e, c1, TAM_C1)];
}

void limpaMemoria(Memoria** memoria, int tamanho){
	for(int i = 0; i < tamanho; i++){
		memoria[i]->endBloco = -1;
		for(int j = 0; j < TAM_BLOCO; j++)
			memoria[i]->palavras[j] = 0;
		memoria[i]->nAcessos = 0;
	}
}

void liberarMemoria(Memoria** memoria, int tamanho){
	for(int i = 0; i < tamanho; i++){
		free (memoria[i]);
	}
	free (memoria);
}

void liberarVetor(Memoria* memoria){
	free (memoria);
}


// GET E SET
int getEndBlocoM (Memoria* memoria){
	return memoria->endBloco;
}

int getPalavra(Memoria* memoria, int indicePalavra){
	return memoria->palavras[indicePalavra];
}

int getAcesso(Memoria* memoria){
	return memoria->nAcessos;
}

int getAtualizado(Memoria* memoria){
	return memoria->atualizado;
}

void setEndBlocoM (Memoria* memoria, int endBloco){
	memoria->endBloco = endBloco;
}

void setPalavra(Memoria* memoria, int indicePalavra, int palavra){
	memoria->palavras[indicePalavra] = palavra;
}

void setAcesso(Memoria* memoria, int nAcessos){
	memoria->nAcessos += nAcessos;
}

void setAtualizado(Memoria* memoria, int atualizado){
	memoria->atualizado = atualizado;
}

int getHitC1(Taxas* taxas){
	return taxas->Hit_c1;
}

int getMissC1(Taxas* taxas){
	return taxas->Miss_c1;
}

int getHitC2(Taxas* taxas){
	return taxas->Hit_c2;
}

int getMissC2(Taxas* taxas){
	return taxas->Miss_c2;
}

int getHitC3(Taxas* taxas){
	return taxas->Hit_c3;
}

int getMissC3(Taxas* taxas){
	return taxas->Miss_c3;
}

int getHitRam (Taxas* taxas) {
	return taxas->Hit_ram;
} 

int getCusto(Taxas* taxas){
	return taxas->custo;
}

void setHitC1(Taxas* taxas, int Hit_c1){
	taxas->Hit_c1++;
}

void setMissC1(Taxas* taxas, int Miss_c1){
	taxas->Miss_c1++;
}

void setHitC2(Taxas* taxas, int Hit_c2){
	taxas->Hit_c2++;
}

void setMissC2(Taxas* taxas, int Miss_c2){
	taxas->Miss_c2++;
}

void setHitC3(Taxas* taxas, int Hit_c3){
	taxas->Hit_c3++;
}

void setMissC3(Taxas* taxas, int Miss_c3){
	taxas->Miss_c3++;
}

void setHitRam (Taxas* taxas, int Hit_ram) {
	taxas->Hit_ram++;
} 

void setCusto(Taxas* taxas, int custo){
	taxas->custo += custo;
}
