#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define QTD_INS 10000
#define TAM_FOR 3
#define TAM_MEM 1000
#define PROB_FOR 95

void GeradorInstrucoes() {
    int aleatorio;
    char separador = ':';
    srand(time(NULL));
    char** ins = (char**)malloc(QTD_INS * sizeof(char*));

    int N = 2;
    int instruc[] = { 6, 6, 6, 6, 6, 6, 6, 6 };

    char** repeticao = (char**)malloc(TAM_FOR * sizeof(char*));
    for (int i = 0; i < TAM_FOR; i++) {
        aleatorio = rand() % N;
        char* s = (char*)malloc(50 * sizeof(char));
        sprintf(s, "%d", aleatorio);
        for (int j = 0; j < instruc[aleatorio]; j++) {
            char temp[10];
            sprintf(temp, "%c%d", separador, rand() % TAM_MEM);
            strcat(s, temp);
        }
        repeticao[i] = s;
    }

    for (int i = 0; i < QTD_INS;) {
        aleatorio = rand() % 100 + 1;
        if (aleatorio <= PROB_FOR && i + TAM_FOR < QTD_INS) {
            for (int j = 0; j < TAM_FOR; j++) {
                ins[i++] = repeticao[j];
            }
        } else {
            aleatorio = rand() % N;
            char* s = (char*)malloc(50 * sizeof(char));
            sprintf(s, "%d", aleatorio);
            for (int j = 0; j < instruc[aleatorio]; j++) {
                char temp[10];
                sprintf(temp, "%c%d", separador, rand() % TAM_MEM);
                strcat(s, temp);
            }
            ins[i++] = s;
        }
    }

    FILE* file = fopen("programa.txt", "w");
    for (int i = 0; i < QTD_INS; i++) {
        fprintf(file, "%s\n", ins[i]);
        free(ins[i]);
    }
    fclose(file);
    free(ins);
    free(repeticao);
}
