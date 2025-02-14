#ifndef MEMORIA_H
#define MEMORIA_H
#include "instrucao.h"


#define TAM_BLOCO 4
#define TAM_C1 16
#define TAM_C2 32
#define TAM_C3 64
#define TAM_RAM 500

typedef struct memoria Memoria;
typedef struct taxas Taxas; 

//FUNÇOES PRINCIPAIS
Memoria** alocarMemoria(int tamanho);
Memoria* alocarVetor();
Taxas* criarTaxas();

//funcoes referentes a RAM
void preencherRam(Memoria** ram);
void trocarRam(int endBloco, Memoria** ram, int tam_ram, Memoria** cacheDestino, int tam_Destino);

//funcoes referentes a cache
int buscarCache(Endereco* e, Memoria** cache, int tam_cache);
void insereCache(int valor, Memoria** memoria, Endereco* e);
void trocarCache(int endBloco, Memoria** cacheOrigem, int tam_Origem, Memoria** cacheDestino, int tam_Destino);

Memoria* MMU(Memoria** c1, Memoria** c2, Memoria** c3, Memoria** ram, Endereco* e, Taxas* taxas);

void limpaMemoria(Memoria** memoria, int tamanho);
void liberarMemoria(Memoria** memoria, int tamanho);
void liberarVetor(Memoria* memoria);


//GET E SET
int getEndBlocoM(Memoria* memoria);
int getPalavra(Memoria* memoria, int indicePalavra);
int getAcesso(Memoria* memoria);
int getAtualizado(Memoria* memoria);

void setEndBlocoM(Memoria* memoria, int endBloco);
void setPalavra(Memoria* memoria, int indicePalavra, int palavra);
void setAcesso(Memoria* memoria, int nAcessos);
void setAtualizado(Memoria* memoria, int atualizado);

int getHitC1(Taxas* taxas);
int getMissC1(Taxas* taxas);
int getHitC2(Taxas* taxas);
int getMissC2(Taxas* taxas);
int getHitC3(Taxas* taxas);
int getMissC3(Taxas* taxas);
int getHitRam (Taxas* taxas);
int getCusto(Taxas* taxas);

void setHitC1(Taxas* taxas, int Hit_c1);
void setMissC1(Taxas* taxas, int Miss_c1);
void setHitC2(Taxas* taxas, int Hit_c2);
void setMissC2(Taxas* taxas, int Miss_c2);
void setHitC3(Taxas* taxas, int Hit_c3);
void setMissC3(Taxas* taxas, int Miss_c3);
void setHitRam (Taxas* taxas, int Hit_ram);
void setCusto(Taxas* taxas, int custo);

#endif
