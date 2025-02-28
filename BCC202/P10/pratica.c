#include <stdio.h>
#include <stdlib.h>

#include "busca.h"

int main() {


    int qnt=0;
    scanf("%d", &qnt);
    for (int i =0; i<qnt;i++) {
        int n=0, x=0;
        scanf("%d", &x);
        scanf("%d", &n);
        int *arr = aloca(n);
        le(arr, n);
        int kl = buscaSequencial(arr, n, x);
        int kb = buscaBinaria(arr, n, x);
        printf("%d %d\n", kl, kb);
        desaloca(&arr);
    }

    // criar variaveis
    // ler quantidade de casos
    // enquanto houver casos
    // ler o numero a ser buscado e a quantidade de numeros
    // alocar o vetor e realizar as buscas
    return 0;
}