#include "domino.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    Item item;
    Node *next;
    Node *prev;
    bool used; // Adicionamos um campo para marcar se a peça já foi usada
};

struct domino {
    int length;
    int lengthSorted;
    Node *head;
    Node *tail;
};

Domino* dominoCria() {
    Domino *domino = (Domino*)malloc(sizeof(Domino));
    domino->lengthSorted = domino->length = 0;
    domino->head = domino->tail = NULL;
    return domino;
}

Domino* dominoDestroi(Domino *domino) {
    if (domino->length == 0) {
        return NULL;
    }

    Node *aux = domino->head;
    while (aux != NULL) {
        Node *node = aux->next;
        free(aux);
        aux = node;
    }

    free(domino);

    return NULL;
}

void dominoImprime(Domino *domino) {
    Node *aux = domino->head;
    while (aux != NULL) {
        printf("%d%d", aux->item.left, aux->item.right);
        if (aux->next != NULL) {
            printf("|");
        }
        aux = aux->next;
    }
    printf("\n");
}

int dominoAdicionaPeca(Domino *domino, Item item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0;
    }
    newNode->item = item;
    newNode->used = false; // Inicialmente, a peça não está usada
    newNode->next = NULL; // Próximo nó é NULL (não circular)

    if (domino->head == NULL) { // Lista vazia
        domino->head = newNode;
        domino->tail = newNode;
        newNode->prev = NULL; // Anterior é NULL (não circular)
    } else {
        newNode->prev = domino->tail;
        domino->tail->next = newNode;
        domino->tail = newNode;
    }
    domino->length++;

    return 1;
}

void dominoAdicionaPecaInicio(Domino* domino, Item item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return; // Memory allocation failed
    }
    newNode->item = item;
    newNode->used = false; // Inicialmente, a peça não está usada
    newNode->prev = NULL; // Anterior é NULL (não circular)

    if (domino->length == 0) { // Lista vazia
        domino->head = newNode;
        domino->tail = newNode;
        newNode->next = NULL; // Próximo nó é NULL (não circular)
    } else { // Lista não vazia
        newNode->next = domino->head;
        domino->head->prev = newNode;
        domino->head = newNode;
    }
    domino->length++;
}

int arePiecesConnected(Domino *domino) {
    if (!domino || !domino->head) return 0; // Lista vazia não pode estar conectada

    Node *aux = domino->head;
    while (aux->next != NULL) { // Verifica até o penúltimo nó
        if (aux->item.right != aux->next->item.left)
            return 0;
        aux = aux->next;
    }

    return 1; // Todas as peças estão conectadas corretamente
}

int dominoEhPossivelOrganizar(Domino *domino, Domino* dominoControl, Node *node1) {
    if (dominoControl->length == domino->length && arePiecesConnected(domino)) {
        return 1;
    }

    Node *aux = node1;
    while (aux != NULL) {
        if (!aux->used) { // Verifica se a peça já foi usada
            Item item = aux->item;
            if (domino->tail->item.right == item.left) {
                dominoAdicionaPeca(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoEhPossivelOrganizar(domino, dominoControl, dominoControl->head)) return 1;
                // Backtracking: remove a peça e marca como não usada
                domino->tail = domino->tail->prev;
                domino->length--;
                aux->used = false;
            } else if (domino->tail->item.right == item.right) {
                int auxInt = item.right;
                item.right = item.left;
                item.left = auxInt;
                dominoAdicionaPeca(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoEhPossivelOrganizar(domino, dominoControl, dominoControl->head)) return 1;
                // Backtracking: remove a peça e marca como não usada
                domino->tail = domino->tail->prev;
                domino->length--;
                aux->used = false;
            } else if (domino->head->item.left == item.right) {
                dominoAdicionaPecaInicio(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoEhPossivelOrganizar(domino, dominoControl, dominoControl->head)) return 1;
                // Backtracking: remove a peça e marca como não usada
                domino->head = domino->head->next;
                domino->length--;
                aux->used = false;
            } else if (domino->head->item.left == item.left) {
                int auxInt = item.right;
                item.right = item.left;
                item.left = auxInt;
                dominoAdicionaPecaInicio(domino, item);
                aux->used = true; // Marca a peça como usada
                if (dominoEhPossivelOrganizar(domino, dominoControl, dominoControl->head)) return 1;
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

int organizePiece(Domino *domino) {
    if (!domino || domino->head == NULL || domino->length == 0) return 0;

    Domino *dominoAux = dominoCria();
    if (!dominoAux) return 0;

    dominoAdicionaPeca(dominoAux, domino->head->item);

    domino->head->used = true; // Marca a peça inicial como usada
    if (dominoEhPossivelOrganizar(dominoAux, domino, domino->head)) {
        printf("YES\n");
        dominoImprime(dominoAux);
        printf("\n");
        dominoDestroi(dominoAux);
        return 1;
    } else {
        printf("NO\n\n");
    }

    dominoDestroi(dominoAux);
    return 0;
}