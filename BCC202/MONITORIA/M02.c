//
// Created by obraganca on 12/2/24.
//
#include <stdio.h>

int soma(int n){
    if (n==1){
        return 1;
    }
    return n+soma(n-1);
}
int main(){

    int x;


    scanf("%d", &x);
    int p = soma(x);


    printf("\nSoma: %d", p);

    return 0;
}