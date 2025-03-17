#include <stdio.h>
#include "heap.h"

int main() {
    int op, prioridade, dia, mes, ano;
    char nome[21];
    Heap* heap = criarHeap();
    while (scanf("%d", &op) && op != 3) {
        if (op == 1) {
            scanf("%s%d%d%d%d", nome, &prioridade, &dia, &mes, &ano);
            inserirChamada(heap, criarChamada(nome, prioridade, dia, mes, ano));
        } else if (op == 2)
            imprimeChamada(atenderChamada(heap));
        else
            break;
    }
    while(consultarSeTemProximaChamada(heap))
        imprimeChamada(atenderChamada(heap));
    return 0;
}
