#ifndef DOMINO_H
#define DOMINO_H

#define RIGHT_INTERVAL_PIECE 6
#define LEFT_INTERVAL_PIECE 0
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
int dominoEhPossivelOrganizar(Domino *domino, int*);
int dominoPlay(Domino*, Domino*, Node *);
int organizePiece(Domino*domino, int*);
#endif