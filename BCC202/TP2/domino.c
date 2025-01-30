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

int canSorted(Node *node1, Node*node2){
    if(node1->item.right == node2->item.left){
        return 1;
    }else if(node1->item.left == node2->item.right){
        return -1;
    }else{
        return 0;
    }
}

int swapNode(Node *node1, Node*node2){
    if(node1->item.right == node2->item.left){

        return 1;
    }else if(node1->item.right == node2->item.right){
        return 1;
    }else if(node1->item.left == node2->item.right){
        return-1
    }else if(node1->item.left == node2->item.left){

    }else{
        return 0;
    }
}

int dominoEhPossivelOrganizar(Domino *domino, Node* node){
    if(domino->lenghtSorted==domino->lenght){
        return;
    }

    dominoEhPossivelOrganizar(domino, node->next);
}
