#include <stdio.h>
#include "lista.h"

int main() {
    int opcao, valor;
    Lista* lista = cria();
    while (scanf("%d", &opcao) && opcao != -1) {
        switch (opcao) {
            case 1: // Insere ordenado elemento de forma ordenada
                if (scanf("%d", &valor) && !insereOrdenado(lista, valor))
                    printf("Nao inseriu valor %d\n", valor);
                break;
            case 2: // Retirar elemento especifico
                if (scanf("%d", &valor) && !retiraEspecifico(lista, valor))
                    printf("Nao retirou valor %d\n", valor);
                break;
            case 3: // Remover elemento do inicio
                if (!retiraInicio(lista))
                    printf("Nao retirou\n");
                break;
            case 4: // Verifica se elemento pertence a lista
                if (scanf("%d", &valor) && !pertence(lista, valor))
                    printf("Nao Pertence\n");
                else
                    printf("Pertence\n");
                break;
            case 5: // Imprimir lista
                imprime(lista);
                break;
            case 6: // Imprime posicao inicial da lista circular
                printf("Posicao inicial %d\n", posicaoInicialLista(lista));
                break;
        }
    }
    lista = libera(lista);
    return 0;
}