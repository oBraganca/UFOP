#include "ordenacao.h"
#include <stdio.h>

int main () {

	int* vetor;
	int i, n, movimentos=0;
	while(scanf("%d", &n), n) {
        movimentos=0;
        vetor = alocaVetor(n);
        int in;
        for(i=0; i<n;i++){
            scanf("%d", &in);
            vetor[i] = in;
        }
        ordenacao(vetor, n, &movimentos);
        movimentos%2 == 0 ? printf("Carlos\n") : printf("Marcelo\n");

        desalocaVetor(vetor);
	}

	return 0;
}
