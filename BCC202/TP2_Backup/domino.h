#ifndef DOMINO_H
#define DOMINO_H

typedef struct{
    int left;
    int right;
    int sorted;
}Item;

typedef struct domino Domino;
typedef struct node Node;

Domino* dominoCria();
Domino* dominoDestroi(Domino *domino);
int dominoAdicionaPeca(Domino *domino, Item item);
void dominoImprime(Domino *domino);
int dominoEhPossivelOrganizar(Domino *domino, Domino *dominoControl, Node* node1);
int organizePiece(Domino*domino);
#endif