/*
    Thayllon Ryan Bragança de Almeida
    Matricula: 24.1.9902
    Exercicio 02
 */



#include <stdio.h>
#include <stdlib.h>

#define TAM_ARR 100

int main(){
    
    int n=0;
    printf("Digite um número: ");
    scanf("%d", &n);
    srand(10);


    int arr[TAM_ARR];

    for(int i = 0; i< TAM_ARR; i++){
        arr[i] = rand()%200;
    }

    printf("\nMaiores: ");
    for(int i=0 ;i<TAM_ARR; i++){
        if(arr[i]>=n){
            printf("%d ", arr[i]);
        }
    }

    printf("\nMenores: ");
    for(int i=0 ;i < TAM_ARR; i++){
        if(arr[i]<n){
            printf("%d ", arr[i]);
        }
    }

    printf("\n");

    return 0;
}
