#include <stdio.h>
#include "matriz.h"

int main()
{
    double s = 0.0;
    char T;
    int n, cont;
    scanf("%c%d", &T, &n);
    
    Matriz *M = alocar(n);

    le(M);

    int c = 1;
    do{
        switch(T){
            case 'S':
                s = somaParte(M, &cont);
                printf("%.1lf\n", s);
                c = 0;
            break;
            case 'M':
                s = somaParte(M, &cont);
                printf("%.1lf\n", s/cont);
                c = 0;
            break;
            default: 
                printf("Valor invalido");
            break;
        }

    }while(c);

    M = desalocar(M);

    return 0;
}

