#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
    char nome[21];
    int idade;
    ESCALADO escalado;
};

struct time {
    char nomeLider[21], nomeConfeiteiro[21], nomeEntregador[21], nomeEmbrulhador[21];
    int idadeLider, idadeConfeiteiro, idadeEntregador, idadeEmbrulhador;
};

void lerQuantidade(int *qtd){
    scanf("%d\n", qtd);
}

// Manter como especificado
Duende *alocaDuendes(int qtd){
    return (Duende*)malloc(qtd*sizeof(Duende));
}

// Manter como especificado
Time *alocaTimes(int qtd){
    return (Time*)malloc(qtd*sizeof(Time));
}

// Manter como especificado
Duende* desalocaDuendes(Duende *duendes){
    free (duendes);
    return NULL;
}

// Manter como especificado
Time* desalocaTimes(Time *times){
    free(times);
    return NULL;
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtd){
    for(int i =0; i<qtd; i++){
        scanf("%s%d", duendes[i].nome, &duendes[i].idade);
        duendes[i].escalado=NAO;
    }
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;

    for(i =0; i<4; i++){
        for(int j=0; j<qtdTime; j++){
            index = proximoMaisVelho(duendes, qtdDuendes);
            if(i == 0){
                times[j].idadeLider = duendes[index].idade;
                strcpy(times[j].nomeLider,duendes[index].nome);
            }else if(i == 1){
                times[j].idadeConfeiteiro = duendes[index].idade;
                strcpy(times[j].nomeConfeiteiro,duendes[index].nome);
            }else if(i == 2){
                times[j].idadeEntregador = duendes[index].idade;
                strcpy(times[j].nomeEntregador,duendes[index].nome);

            }else{
                times[j].idadeEmbrulhador = duendes[index].idade;
                strcpy(times[j].nomeEmbrulhador,duendes[index].nome);
            }
            duendes[index].escalado=SIM;
        }
    }


}

int proximoMaisVelho(Duende *D, int qtd) {
    int m= -1;
    for (int i = 0; i < qtd; i++) {
        if (!D[i].escalado) {
            if (m == -1 || D[i].idade > D[m].idade) {
                m = i;
            }
        }
    }

    return m;
}


// Manter como especificado
void printTimes(Time *times, int qtd){
    for (int i=0; i<qtd; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}