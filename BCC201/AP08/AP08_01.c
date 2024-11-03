/*
    Thayllon Ryan Bragança de Almeida
    Matricula: 24.1.9902
    Exercicio 01
 */



#include <stdio.h>

int sqrtFigure(int, char);

int main(){

    printf("Letra: ");
    char l;
    scanf("%c", &l);
    getchar();

    int n=0;
    printf("\n");
    do{
        printf("N: ");
        scanf("%d", &n);
        printf("\n");
    }while(n <=0 );

    sqrtFigure(n, l);


    return 0;
}

int sqrtFigure(int n, char c){
    for(int j=0; j <n; j++){
        for(int i =0; i <n; i++){
            if(j==0 || j==n-1 || (i==0 || i==n-1)){
                printf("%c",c);
            }else{
                printf(" ");
            }
        }        
        printf("\n");
    }

    /*
    
          0 1 2 3 4
        0 k k k K k 0
        1 k       k 1
        2 k       k 2
        3 K       k 3
        4 k k k k k 4
    */

}