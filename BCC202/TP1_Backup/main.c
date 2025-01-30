#include <stdio.h>
#include "nonogram.h"

int main(){
    int n;
    scanf("%d",&n);
    Nonogram *nonograma = NonogramAllocate(n);

    NonogramRead(nonograma);
    NonogramPlay(nonograma,0,0);
    if(nonograma->numSolucoes){
        printf("Total of solutions: %d\n",nonograma->numSolucoes);
    }
    else{
        printf("No solution was found!\n");
    }
    NonogramFree(nonograma);

    return 0;

}