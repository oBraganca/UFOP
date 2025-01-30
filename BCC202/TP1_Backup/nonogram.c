#include "nonogram.h"
#include <stdlib.h>
#include <stdio.h>

Nonogram* NonogramAllocate(int n){
    Nonogram *a = malloc(sizeof(Nonogram));

    a->tabuleiro = malloc(n*sizeof(int*));
    for(int i = 0; i<n; i++){
        a->tabuleiro[i] = calloc(n, sizeof(int));
    }

    a->tamInst = malloc(2 * n * sizeof(int));

    a->instrucao = malloc(2 * n * sizeof(int*));

    a->tam = n;

    a->numSolucoes = 0;

    return a;
}

void NonogramFree(Nonogram *a){

    for(int i = 0; i<a->tam; i++){
        free(a->tabuleiro[i]);
    }
    free(a->tabuleiro);

    for(int i = 0; i< 2*a->tam; i++)
        free(a->instrucao[i]);
    free(a->instrucao);

    free(a->tamInst);

    free(a);
}

void NonogramRead(Nonogram *a){

    for(int i = 0; i< 2*a->tam; i++){

        scanf("%d",&a->tamInst[i]);
        a->instrucao[i] = malloc(a->tamInst[i] * sizeof(int));

        for(int j = 0; j< a->tamInst[i]; j++){

            scanf("%d", &a->instrucao[i][j]);
        }
    }

}
int checkIsCompletedLine(Nonogram *a, int lin, int col) {
    int totalInLine = 0;
    for (int i = 0; i < a->tamInst[a->tam + lin]; i++) {
        totalInLine += a->instrucao[a->tam+ lin][i];
    }

    int count = 0;
    for (int i = 0; i <= col; i++) {
        if (a->tabuleiro[lin][i] == 1) { // 1
            count++;
        }
    }

    return count == totalInLine;
}

bool NonogramVerify(Nonogram *a) {
    // Verifica se as somas e a sequência de blocos estão corretas
    for (int i = 0; i < a->tam; i++) {
        // Verificação de linha
        int currentBlock = 0, blockCount = 0, instIndex = a->tam + i;
        for (int j = 0; j < a->tam; j++) {
            if (a->tabuleiro[i][j] == 1) {
                currentBlock++;
            } else if (currentBlock > 0) {
                if (blockCount >= a->tamInst[instIndex] || currentBlock != a->instrucao[instIndex][blockCount]) {
                    return false;
                }
                blockCount++;
                currentBlock = 0;
            }
        }
        if (currentBlock > 0) {
            if (blockCount >= a->tamInst[instIndex] || currentBlock != a->instrucao[instIndex][blockCount]) {
                return false;
            }
            blockCount++;
        }
        if (blockCount != a->tamInst[instIndex]) return false;

        // Verificação de coluna
        currentBlock = 0, blockCount = 0, instIndex = i;
        for (int j = 0; j < a->tam; j++) {
            if (a->tabuleiro[j][i] == 1) {
                currentBlock++;
            } else if (currentBlock > 0) {
                if (blockCount >= a->tamInst[instIndex] || currentBlock != a->instrucao[instIndex][blockCount]) {
                    return false;
                }
                blockCount++;
                currentBlock = 0;
            }
        }
        if (currentBlock > 0) {
            if (blockCount >= a->tamInst[instIndex] || currentBlock != a->instrucao[instIndex][blockCount]) {
                return false;
            }
            blockCount++;
        }
        if (blockCount != a->tamInst[instIndex]) return false;
    }

    return true;
}

void NonogramPlay(Nonogram *a, int x, int y) {

    if (x == a->tam) {
        a->numSolucoes++;
        NonogramPrint(a);
        return;
    }

    if (y == a->tam) {
        if(!checkIsCompletedLine(a, x, y))
            return;

        NonogramPlay(a, x + 1, 0);

        return;
    }

    // Tenta com o valor 1
    a->tabuleiro[x][y] = 1;

    /*
    if(x == 0 && y == 7){
        printf("%d", NonogramPartialVerify(a, x, y));
        exit(0);
    }

     */

    if (NonogramPartialVerify(a, x, y)) {  // Verificação antecipada
        NonogramPlay(a, x, y + 1);

    }

    // Tenta com o valor 0
    a->tabuleiro[x][y] = 0;

    NonogramPlay(a, x, y + 1);

    return;
}



void NonogramPrint(Nonogram *a) {
    printf("SOLUTION %d:\n",a->numSolucoes);
    for (int i = 0; i < a->tam; i++) {
        for (int j = 0; j < a->tam; j++) {
            if (a->tabuleiro[i][j] == 0) {
                printf(". ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


bool NonogramPartialVerify(Nonogram *a, int x, int y) {
    // Verificar a linha x
    int currentBlock = 0, blockCount = 0;
    for (int j = 0; j <= y; j++) {  // Apenas até a coluna preenchida
        if (a->tabuleiro[x][j] == 1) {
            currentBlock++;
        } else if (currentBlock > 0) {

            blockCount++;
            currentBlock = 0;

            if (blockCount >= a->tamInst[a->tam + x] || currentBlock > a->instrucao[a->tam + x][blockCount]) {
                return false;  // Bloco atual excede o esperado ou muitos blocos
            }
        }
    }

    // Caso o bloco atual ainda esteja em andamento
    if (currentBlock > 0 && blockCount < a->tamInst[a->tam + x] && currentBlock > a->instrucao[a->tam + x][blockCount]) {
        return false;
    }

    // Verificar a coluna y
    currentBlock = 0, blockCount = 0;
    for (int i = 0; i <= x; i++) {  // Apenas até a linha preenchida
        if (a->tabuleiro[i][y] == 1) {
            currentBlock++;
        } else if (currentBlock > 0) {

            blockCount++;
            currentBlock = 0;
            if (blockCount >= a->tamInst[y] || currentBlock > a->instrucao[y][blockCount]) {
                return false;  // Bloco atual excede o esperado ou muitos blocos
            }
        }
    }

    // Caso o bloco atual ainda esteja em andamento
    if (currentBlock > 0 && blockCount < a->tamInst[y] && currentBlock > a->instrucao[y][blockCount]) {
        return false;
    }

    return true;
}
