#include "domino.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, left, right;
    while (scanf("%d", &n) && n != 0) {

        Domino *domino = dominoCria();
        for(int i=0; i<n; i++){
            scanf("%d%d",&left, &right);
            dominoAdicionaPeca(domino, (Item){left, right, 0});
        }

        dominoImprime(domino);
        domino = dominoDestroi(domino);
    }

    return 0;
}
