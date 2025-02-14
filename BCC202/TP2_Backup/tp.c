#include "domino.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, left, right, i=1;
    while (scanf("%d", &n) && n != 0) {

        int *arr = (int*)calloc(RIGHT_INTERVAL_PIECE+1, sizeof(int));
        Domino *domino = dominoCria();
        for(int i=0; i<n; i++){
            scanf("%d%d",&left, &right);
            dominoAdicionaPeca(domino, (Item){left, right, 0});
            arr[left]++;
            arr[right]++;
        }

        printf("Test %d:\n", i);
        organizePiece(domino, arr);
        free(arr);

        domino = dominoDestroi(domino);
        i++;
    }

    return 0;
}
