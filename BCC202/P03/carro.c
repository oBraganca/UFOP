#include "carro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CT 20
struct funcionario {
    char nm[CT];
    int m;
};


struct carro {
    int ch;
    char md[CT];
    int p;
    int y;
    Funcionario* func;
};

Funcionario* FuncionarioAloca() {
    Funcionario* f = (Funcionario*)malloc(sizeof(Funcionario));

    return f;
}

void FuncionarioDesaloca(Funcionario** func) {
    free(*func);
}

Carro* CarroAloca(int n) {
    Carro* c = (Carro*)malloc(n*sizeof(Carro));
    return c;
}

void CarroDesaloca(Carro** carros, int n) {
    for(int i =0; i<n; i++){
        free((*carros+i)->func);
    }
    free(*carros);
}

void le(Carro* carros, int n) {
    for(int i =0; i<n; i++){
        scanf("%d%s%d%d", &carros[i].ch, carros[i].md, &carros[i].p, &carros[i].y);
        (carros+i)->func = FuncionarioAloca();
        scanf("%s%d", carros[i].func->nm, &carros[i].func->m);

    }
}

int conta(Carro* carros, int n, const int ano, const int lugares) {
    if(n-1 < 0 ){
        return 0;
    }

    if(carros->y > ano && carros->p > lugares){
        return conta(carros+1, n-1, ano, lugares)+1;
    }

    return conta(carros+1, n-1, ano, lugares);
}

void imprime(Carro* carros, int n, const char* nome) {
    if(n-1 < 0 ){
        return;
    }

    if(!strcmp(carros->func->nm, nome)){
        imprime(carros+1, n-1, nome);
        printf("%s [%d|%d|%d]\n", carros->md, carros->y, carros->p, carros->ch);
    }else{
        imprime(carros+1, n-1, nome);
    }

}
