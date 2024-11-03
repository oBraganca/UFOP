/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902

    Questão 01

*/


#include <stdio.h>

#define TAM_DAYS 30

int main(){

    float d[TAM_DAYS];

    printf("Entre com as temperaturas: ");

    float t=0.0;
    for(int i =0; i <= TAM_DAYS-1; i++){
        scanf("%f", &d[i]);
        t+=d[i];
    }


    float m = t/TAM_DAYS;

    int u=0,l=0;

    for(int i =0; i<=TAM_DAYS-1; i++){

        if(d[i]<m){
            l++;
        }else if(d[i]>m){
            u++;
        }

    }

    printf("\nAcima: %d", u);
    printf("\nAbaixo: %d\n",l);

    return 0;
}