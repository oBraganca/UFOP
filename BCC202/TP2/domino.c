#include "domino.h"
#include <stdio.h>
#include <stdlib.h>

struct node{
    Item item;
    Node *next;
    Node *prev;
};

struct domino {
    int lenght;
    int lenghtSorted;
    Node *head;
    Node *tail;
};



Domino* dominoCria(){
    Domino *domino = (Domino*)malloc(sizeof(Domino));
    domino->lenghtSorted = domino->lenght = 0;
    domino->head = domino->tail = NULL;
    return domino;
}

Domino* dominoDestroi(Domino *domino) {
    if(domino->lenght == 0){
        return NULL;
    }

    Node *aux = domino->head;

    do{
        Node *node = aux->next;
        free(aux);
        aux = node;
    }while(aux!=domino->tail);

    free(domino);

    return NULL;
}
int dominoAdicionaPeca(Domino *domino, Item item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return 0;
    }
    newNode->item = item;
    if(domino->head==domino->tail && domino->lenght == 0){
        domino->head = newNode;
        domino->tail = newNode;
        domino->tail->next=domino->head;
        domino->tail->prev=domino->head;
    }else{
        newNode->prev = domino->tail;
        domino->tail->next = newNode;
        domino->tail = newNode;
        domino->tail->next=domino->head;
    }
    domino->lenght++;

    return 1;
}
void dominoImprime(Domino *domino) {
    Node *aux = domino->head;
    do{
        printf("%d%d", aux->item.left, aux->item.right);
        if(aux->next!=domino->head){
            printf("|");
        }
        aux = aux->next;
    } while(aux!=domino->head);
    printf("\n");
}

int canSorted(Node *node1, Node*node2){
    if(node1->item.right == node2->item.left){
        return 1;
    }else if(node1->item.left == node2->item.right){
        return -1;
    }else{
        return 0;
    }
}


void moveNodeBehind(Domino* domino, Node* node1, Node* node2) {

    // Verificação básica para garantir que os ponteiros são válidos e node1 != node2
    printf("-------------\n");
    dominoImprime(domino);
    if (!domino || !node1 || !node2 || node1 == node2) return;

    // Caso especial: mover node2 para a posição de cabeça
    if (node1 == domino->head) {
        // Se node2 deve ir para a head, atualizar o head da lista
        if (node2 != domino->head) {
            // Remover node2 da sua posição atual
            if (node2->prev) node2->prev->next = node2->next;
            if (node2->next) node2->next->prev = node2->prev;

            // Ajustar head e tail se necessário
            if (node2 == domino->tail) domino->tail = node2->prev;

            // Inserir node2 na cabeça
            node2->next = domino->head;
            node2->prev = NULL;
            domino->head->prev = node2;
            domino->head = node2;
        }
    } else {
        // Remover node2 da sua posição atual
        if (node2->prev) node2->prev->next = node2->next;
        if (node2->next) node2->next->prev = node2->prev;

        // Ajustar head e tail se necessário
        if (node2 == domino->head) domino->head = node2->next;
        if (node2 == domino->tail) domino->tail = node2->prev;

        // Inserir node2 antes de node1
        node2->next = node1;
        node2->prev = node1->prev;

        if (node1->prev) node1->prev->next = node2;
        node1->prev = node2;

        // Se node1 era o head, atualizar a cabeça
        if (node1 == domino->head) domino->head = node2;
    }

    // Ajustar ponteiros para manter a circularidade da lista
    if (domino->head) domino->head->prev = domino->tail;
    if (domino->tail) domino->tail->next = domino->head;

    // Impressão para depuração
    printf("[%d%d-%d%d](%p - %p)\n", node1->item.left, node1->item.right, node2->item.left, node2->item.right, node1, node2);
    dominoImprime(domino);
    printf("-------------\n");
}


void insertAfterNode(Domino * domino, Node* node1, Node* node2) {
    Node*aux = node2->next;
    aux->prev=node2->prev;

    node2->prev->next = node2->next;

    aux = node1->next;
    node2->next=aux;
    node2->prev=node1;

    aux->prev=node2;

    node1->next=node2;

}

int swapNode(Domino *domino, Node *node1, Node*node2){
    if(node1->next==node2 && node1->item.right==node2->item.right){
        int auxInt = node2->item.right;
        node2->item.right = node2->item.left;
        node2->item.left = auxInt;
        return 1;
    }

    if(node1->next==node2 && node1->item.right==node2->item.left){
        return 1;
    }

    if (node1->item.right == node2->item.left) {
        insertAfterNode(domino, node1, node2);

        return 1;
    } else if (node1->item.right == node2->item.right) {
        int auxInt = node2->item.right;
        node2->item.right = node2->item.left;
        node2->item.left = auxInt;

        insertAfterNode(domino, node1, node2);

        return 1;
    } else if (node1->item.left == node2->item.right) {
        moveNodeBehind(domino, node1, node2);

        return -1;
    } else if (node1->item.left == node2->item.left) {
        int auxInt = node2->item.right;
        node2->item.right = node2->item.left;
        node2->item.left = auxInt;

        moveNodeBehind(domino, node1, node2);
        return -1;
    } else {
        return 0;
    }

}


int dominoEhPossivelOrganizar(Domino *domino, Node* node1, Node*node2){


    if(domino->lenghtSorted==domino->lenght-1){
        return 1;
    }

    if(node1 == node2 && domino->lenghtSorted==0){
        return 0;
    }

    if(node1 == node2){
        return dominoEhPossivelOrganizar(domino, node1->next, node2);
    }

    if(swapNode(domino, node1, node2) && !node2->item.sorted){

        node1->item.sorted = node2->item.sorted = 1;
        domino->lenghtSorted++;
        return dominoEhPossivelOrganizar(domino, node2, node2->next);
    }

    dominoEhPossivelOrganizar(domino, node1, node2->next);
}

int organizePiece(Domino*domino){
    return dominoEhPossivelOrganizar(domino, domino->head, domino->head->next);
}

