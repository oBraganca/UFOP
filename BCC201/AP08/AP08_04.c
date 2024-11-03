/*
    Thayllon Ryan Bragança de Almeida
    Matricula: 24.1.9902
    Exercicio 03
 */


#include <stdio.h>


int main(){
    char arr[10], arrV[10], arrC[10];
    int cV=0, cC=0;
    char c;
    
    for(int i = 0; i<10; i++){
        printf("Digite o %d caracter: ", i+1);
        scanf("%c",&c);
        getchar();
        arr[i] = c;

        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                arrV[cV] = c;
                cV++;
                break;
            default:
                arrC[cC] = c;
                cC++;
                break;

        }

    }


    printf("%d vogais:", cV);
    for(int i =0; i<cV; i++){
        printf(" %c", arrV[i]);
    }

    printf("\n%d consoantes:", cC);
    for(int i =0; i<cC; i++){
        printf(" %c", arrC[i]);
    }
    printf("\n");

    return 0;
}