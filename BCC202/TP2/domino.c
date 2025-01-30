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
    Node *head;
    Node *tail;
};



Domino* dominoCria(){
    Domino *domino = (Domino*)malloc(sizeof(Domino));
    domino->lenght = 0;
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
    /*
    while (aux){
        Node *node = aux->next;
        free(aux);
        aux = node;
    }*/
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
    }else{
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
int dominoEhPossivelOrganizar(Domino *domino, Node* node){
    return 0;
}
