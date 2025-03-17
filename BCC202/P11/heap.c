#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool temMaisPrioridade(Chamada* c1, Chamada* c2) {
    if (c1->prioridade > c2->prioridade)
        return true;
    else if (c1->prioridade < c2->prioridade)
        return false;
    else {
        // Prioridade igual: desempata pela data de nascimento (paciente mais velho tem maior prioridade)
        if (c1->nascimento.ano < c2->nascimento.ano)
            return true;
        else if (c1->nascimento.ano > c2->nascimento.ano)
            return false;
        else { // mesmo ano
            if (c1->nascimento.mes < c2->nascimento.mes)
                return true;
            else if (c1->nascimento.mes > c2->nascimento.mes)
                return false;
            else { // mesmo mês
                if (c1->nascimento.dia < c2->nascimento.dia)
                    return true;
                else
                    return false;
            }
        }
    }
}

/** Refaz o heap a partir da raiz (sift down) */
void refaz(Heap *heap) {
    int i = 0;
    int tam = heap->tam;
    Chamada x = heap->chamadas[i];
    int filho;
    while (2 * i + 1 < tam) { // enquanto houver filho à esquerda
        filho = 2 * i + 1; // filho esquerdo
        // Se existir filho direito e este tiver mais prioridade que o esquerdo, escolhe-o
        if (filho + 1 < tam && temMaisPrioridade(&heap->chamadas[filho + 1], &heap->chamadas[filho])) {
            filho++;
        }
        // Se o filho escolhido tem mais prioridade que o elemento x, sobe o filho
        if (temMaisPrioridade(&heap->chamadas[filho], &x)) {
            heap->chamadas[i] = heap->chamadas[filho];
            i = filho;
        } else {
            break;
        }
    }
    heap->chamadas[i] = x;
}

/** Insere uma chamada na posição index (sift up) */
void heapInsere(Heap *heap, Chamada chamada, int index) {
    int i = index;
    // "Bubbling up": enquanto o elemento tiver mais prioridade que seu pai, sobe-o
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (temMaisPrioridade(&chamada, &heap->chamadas[parent])) {
            heap->chamadas[i] = heap->chamadas[parent];
            i = parent;
        } else {
            break;
        }
    }
    heap->chamadas[i] = chamada;
}

/** Cria e retorna uma chamada com as informações fornecidas */
Chamada criarChamada(char *nome, int prioridade, int dia, int mes, int ano) {
    Chamada nova;
    strcpy(nova.nome, nome);
    nova.prioridade = prioridade;
    nova.nascimento.dia = dia;
    nova.nascimento.mes = mes;
    nova.nascimento.ano = ano;
    return nova;
}

/** Imprime uma chamada (já implementado) */
void imprimeChamada(Chamada chamada) {
    printf("%02d | %02d/%02d/%04d | %s\n", chamada.prioridade, chamada.nascimento.dia,
           chamada.nascimento.mes, chamada.nascimento.ano, chamada.nome);
}

/** Cria e retorna um heap vazio */
Heap* criarHeap() {
    Heap *heap = (Heap*) malloc(sizeof(Heap));
    if (heap != NULL) {
        heap->tam = 0;
    }
    return heap;
}

/** Destroi o heap alocado e retorna NULL */
Heap* destroiHeap(Heap *heap) {
    if (heap != NULL) {
        free(heap);
    }
    return NULL;
}

/** Insere uma chamada no heap
 * Insere na primeira posição livre e realiza o ajuste (sift up) chamando heapInsere.
 */
void inserirChamada(Heap *heap, Chamada chamada) {
    heapInsere(heap, chamada, heap->tam);
    heap->tam++;
}

/** Remove a chamada de maior prioridade (na raiz) e ajusta o heap (sift down) */
Chamada atenderChamada(Heap *heap) {
    if (heap->tam <= 0) {
        // Caso o heap esteja vazio, retorna uma chamada "vazia" (opcional, conforme especificação)
        Chamada vazia;
        strcpy(vazia.nome, "");
        vazia.prioridade = -1;
        vazia.nascimento.dia = 0;
        vazia.nascimento.mes = 0;
        vazia.nascimento.ano = 0;
        return vazia;
    }
    Chamada removida = heap->chamadas[0];
    heap->tam--;
    // Coloca o último elemento na raiz e refaz o heap para manter a propriedade
    heap->chamadas[0] = heap->chamadas[heap->tam];
    refaz(heap);
    return removida;
}

/** Verifica se ainda há chamadas no heap */
bool consultarSeTemProximaChamada(Heap *heap) {
    return (heap->tam > 0);
}
