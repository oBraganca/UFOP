/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902

    Questão 02

*/


#include <stdio.h>

#define TAM 15

int main(){
    int v[TAM];
    printf("Entre com os 15 valores: ");

    for(int i =0; i<TAM; i++){
        scanf("%d", &v[i]);
    }

    printf("\nEntre com o valor de n: ");
    int n=0;
    scanf("%d", &n);
    
    int aux = 0;
    for(int j=0; j<n%15; j++){
        aux = v[0];
        for(int i=0; i<TAM; i++){
            if(i == TAM-1){
                v[i] = aux;

            }else{
                v[i] = v[i+1];
            }
        }
    }

    for(int i = 0; i<TAM; i++){
        printf("%d ", v[i]);
    }
        

    printf("\n");
    return 0;
}