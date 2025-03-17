#ifndef HEAP_H

#include <stdbool.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    int prioridade;
    Data nascimento;
} Chamada;

typedef struct {
    Chamada chamadas[100]; // Vetor que armazena as chamadas
    int tam;       // Número de chamadas na fila
} Heap;

/** Mantenha como especificado
 * Cria e retorna um tipo chamada baseado nas informacoes separadas
 */
Chamada criarChamada(char *nome, int prioridade, int dia, int mes, int ano);

/** Mantenha como especificado
 * Imprime a chamada em um formato especificado
 */
void imprimeChamada(Chamada chamada);

/** Mantenha como especificado
 * Aloca e retorna um heap vazio
 */
Heap* criarHeap();

/** Mantenha como especificado
 * Destroi o heap alocado
 */
Heap* destroiHeap(Heap *heap);

/** Mantenha como especificado
 * Insere uma chamada no heap
 */
void inserirChamada(Heap *heap, Chamada chamada);

/** Mantenha como especificado
 * Remove a chamada com mais prioridade do heap
 */
Chamada atenderChamada(Heap *heap);

/** Mantenha como especificado
 * Verifica se ainda tem chamadas no heap
 */
bool consultarSeTemProximaChamada(Heap *heap);

#endif // !HEAP_H