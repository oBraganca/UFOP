#include "domino.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, left, right, i=1;
    while (scanf("%d", &n) && n != 0) {

        Domino *domino = dominoCria();
        for(int i=0; i<n; i++){
            scanf("%d%d",&left, &right);
            dominoAdicionaPeca(domino, (Item){left, right, 0});
        }

        printf("Test %d\n", i);
        organizePiece(domino);

        domino = dominoDestroi(domino);
        i++;
    }

    return 0;
}
