#include "domino.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Nome: node
Descricao: Struct que representa um nó da lista duplamente encadeada. Cada nó contém uma peça de dominó (Item),
           ponteiros para o próximo e anterior nós, e um campo booleano para indicar se a peça já foi usada.
*/
struct node
{
    Item item;
    Node *next;
    Node *prev;
    bool used; // Adicionamos um campo para marcar se a peça já foi usada
};

/*
Nome: domino
Descricao: Struct que representa o jogo de dominó. Contém o comprimento total da lista de peças, o comprimento
           da lista ordenada, e ponteiros para o início (head) e fim (tail) da lista.
*/
struct domino
{
    int length;
    int lengthSorted;
    Node *head;
    Node *tail;
};

/*
Nome: dominoCria
Descricao: Função para criar e inicializar uma nova estrutura de dominó.
Entrada: Nenhuma.
Saida: Ponteiro para a estrutura de dominó criada.
*/
Domino *dominoCria()
{
    Domino *domino = (Domino *)malloc(sizeof(Domino));
    domino->lengthSorted = domino->length = 0;
    domino->head = domino->tail = NULL;
    return domino;
}

/*
Nome: dominoDestroi
Descricao: Função para liberar a memória alocada para a estrutura de dominó e seus nós.
Entrada: Ponteiro para a estrutura de dominó.
Saida: Ponteiro nulo.
*/
Domino *dominoDestroi(Domino *domino)
{
    if (domino->length == 0)
    {
        return NULL;
    }

    Node *aux = domino->head;
    while (aux != NULL)
    {
        Node *node = aux->next;
        free(aux);
        aux = node;
    }

    free(domino);

    return NULL;
}

/*
Nome: dominoImprime
Descricao: Função para imprimir as peças de dominó na lista.
Entrada: Ponteiro para a estrutura de dominó.
Saida: Nenhuma.
*/
void dominoImprime(Domino *domino)
{
    Node *aux = domino->head;
    while (aux != NULL)
    {
        printf("%d%d", aux->item.left, aux->item.right);
        if (aux->next != NULL)
        {
            printf("|");
        }
        aux = aux->next;
    }
    printf("\n");
}

/*
Nome: dominoAdicionaPeca
Descricao: Função para adicionar uma nova peça de dominó ao final da lista.
Entrada: Ponteiro para a estrutura de dominó e a peça a ser adicionada.
Saida: 1 se a peça foi adicionada com sucesso, 0 caso contrário.
*/
int dominoAdicionaPeca(Domino *domino, Item item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 0;
    }
    newNode->item = item;
    newNode->used = false; // Inicialmente, a peça não está usada
    newNode->next = NULL;  // Próximo nó é NULL (não circular)

    if (domino->head == NULL)
    { // Lista vazia
        domino->head = newNode;
        domino->tail = newNode;
        newNode->prev = NULL; // Anterior é NULL (não circular)
    }
    else
    {
        newNode->prev = domino->tail;
        domino->tail->next = newNode;
        domino->tail = newNode;
    }
    domino->length++;

    return 1;
}

/*
Nome: dominoAdicionaPecaInicio
Descricao: Função para adicionar uma nova peça de dominó no início da lista.
Entrada: Ponteiro para a estrutura de dominó e a peça a ser adicionada.
Saida: Nenhuma.
*/
int dominoAdicionaPecaInicio(Domino *domino, Item item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 0; // Falha na alocação de memória
    }
    newNode->item = item;
    newNode->used = false; // Inicialmente, a peça não está usada
    newNode->prev = NULL;  // Anterior é NULL (não circular)

    if (domino->length == 0)
    { // Lista vazia
        domino->head = newNode;
        domino->tail = newNode;
        newNode->next = NULL; // Próximo nó é NULL (não circular)
    }
    else
    { // Lista não vazia
        newNode->next = domino->head;
        domino->head->prev = newNode;
        domino->head = newNode;
    }
    domino->length++;
    return 1;
}

/*
Nome: arePiecesConnected
Descricao: Função para verificar se todas as peças de dominó na lista estão conectadas corretamente.
Entrada: Ponteiro para a estrutura de dominó.
Saida: 1 se as peças estão conectadas corretamente, 0 caso contrário.
*/
int arePiecesConnected(Domino *domino)
{
    if (!domino || !domino->head)
        return 0; // Lista vazia não pode estar conectada

    Node *aux = domino->head;
    while (aux->next != NULL)
    { // Verifica até o penúltimo nó
        if (aux->item.right != aux->next->item.left)
            return 0;
        aux = aux->next;
    }

    return 1; // Todas as peças estão conectadas corretamente
}

/*
Nome: dominoEhPossivelOrganizar
Descricao: Função para verificar se é possível organizar as peças de dominó de forma que formem uma cadeia válida.
Entrada: Ponteiro para a estrutura de dominó e um vetor de contagem de peças.
Saida: 1 se é possível organizar, 0 caso contrário.
*/
int dominoEhPossivelOrganizar(Domino *domino, int *arr)
{
    int odd = 0;
    for (int i = LEFT_INTERVAL_PIECE; i < RIGHT_INTERVAL_PIECE; i++)
    {
        if (arr[i] % 2 != 0)
        {
            odd++;
        }
    }
    return odd <= 2;
}

/*
Nome: dominoPlay
Descricao: Função recursiva que tenta organizar as peças de dominó em uma cadeia válida, utilizando backtracking.
Entrada: Ponteiro para a estrutura de dominó, ponteiro para a estrutura de controle e ponteiro para o nó inicial.
Saida: 1 se a organização foi bem-sucedida, 0 caso contrário.
*/
int dominoPlay(Domino *domino, Domino *dominoControl, Node *node1)
{
    if (dominoControl->length == domino->length && arePiecesConnected(domino))
    {
        return 1;
    }

    Node *aux = node1;
    while (aux != NULL)
    {
        if (!aux->used)
        { // Verifica se a peça já foi usada
            Item item = aux->item;
            if (domino->tail->item.right == item.left)
            {
                dominoAdicionaPeca(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoPlay(domino, dominoControl, dominoControl->head))
                    return 1;
                // Backtracking: remove a peça e marca como não usada
                domino->tail = domino->tail->prev;
                domino->length--;
                aux->used = false;
            }
            else if (domino->tail->item.right == item.right)
            {
                int auxInt = item.right;
                item.right = item.left;
                item.left = auxInt;
                dominoAdicionaPeca(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoPlay(domino, dominoControl, dominoControl->head))
                    return 1;
                // Backtracking: remove a peça e marca como não usada
                domino->tail = domino->tail->prev;
                domino->length--;
                aux->used = false;
            }
            else if (domino->head->item.left == item.right)
            {
                dominoAdicionaPecaInicio(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoPlay(domino, dominoControl, dominoControl->head))
                    return 1;
                // Backtracking: remove a peça e marca como não usada
                domino->head = domino->head->next;
                domino->length--;
                aux->used = false;
            }
            else if (domino->head->item.left == item.left)
            {
                int auxInt = item.right;
                item.right = item.left;
                item.left = auxInt;
                dominoAdicionaPecaInicio(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoPlay(domino, dominoControl, dominoControl->head))
                    return 1;
                // Backtracking: remove a peça e marca como não usada
                domino->head = domino->head->next;
                domino->length--;
                aux->used = false;
            }
        }
        aux = aux->next;
    }
    return 0;
}

/*
Nome: organizePiece
Descricao: Função para tentar organizar as peças de dominó em uma cadeia válida e imprimir o resultado.
Entrada: Ponteiro para a estrutura de dominó e um vetor de contagem de peças.
Saida: 1 se a organização foi bem-sucedida, 0 caso contrário.
*/
int organizePiece(Domino *domino, int *arr)
{
    if (!domino || domino->head == NULL || domino->length == 0)
        return 0;
    int isPossibleOrganize = dominoEhPossivelOrganizar(domino, arr);

    Domino *dominoAux = dominoCria();
    if (!dominoAux)
        return 0;

    dominoAdicionaPeca(dominoAux, domino->head->item);
    domino->head->used = true; // Marca a peça inicial como usada
    if (isPossibleOrganize && dominoPlay(dominoAux, domino, domino->head))
    {
        printf("YES\n");
        dominoImprime(dominoAux);
        printf("\n");
        return 1;
    }
    else
    {
        printf("NO\n\n");
    }

    dominoDestroi(dominoAux);
    return 0;
}
