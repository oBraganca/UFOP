//
// Created by obraganca on 12/2/24.
//

#include <stdio.h>

int potencia(int x, int y){
    if(y==1){
        return x;
    }
    return x*potencia(x, y-1);
}

int main(){

    int x, y;

    scanf("%d%d", &x, &y);
    int p = potencia(x, y);

    printf("\nPotencia: %d", p);
    return 0;
}