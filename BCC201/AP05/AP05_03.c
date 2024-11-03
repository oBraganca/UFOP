/*
    Aula Pratica 05 - Questão 3
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/
#include <stdio.h>

void swap(int , int , int , int *, int *, int*);


int main (){


    printf("Entre com os números:\n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int m, i, mm;
    swap(a, b, c, &m, &i, &mm);
    

    printf("\nMenor: %d", m);
    printf("\nIntermediário: %d", i);
    printf("\nMaior: %d", mm);
    
    return 0;
}

void swap(int a, int b, int c, int *m, int *i, int*mm){
    if(a < b && a < c){
        *m = a;

        if(b < c){
            *i = b;
            *mm = c;

        }else{
            *i = c;
            *mm = b;
        }
    }else if(b < a && b < c){
        *m = b;

        if(a < c){
            *i = a;
            *mm = c;

        }else{
            *i = c;
            *mm = a;
        }
    }else{
        *m = c;

        if(a < b){
            *i = a;
            *mm = b;

        }else{
            *i = b;
            *mm = a;
        }
    }
}