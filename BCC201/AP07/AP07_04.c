/*
    Thayllon Bragança
    24.1.9902
    Atividade 04
*/

#include <stdio.h>

float calcMA(int, int);

int main(){

    float n;
    float m,mn;
    float c=0.0;
    printf("Digite o consumo da 1 residência: ");
    n=0.0;
    scanf("%f", &n);

    c+=n;

    m = n;
    mn = m;
    printf("\n");

    int i; 
    for(i = 2; i<=15; i++){
        printf("Digite o consumo da %d residência: ",i);
        n=0.0;
        scanf("%f", &n);
        if(n<mn){
            mn=n;
        }else if(n > m){
            m = n;
        }

        c +=n;

        printf("\n");
    }

    printf("Consumo médio: %.2f Kwh\n",c/15);
    printf("Maior consumo: %.2f Kwm\n",m);
    printf("Menor consumo: %.2f Kwm\n",mn);

    return 0;
}

float calcMA(int s, int c){
    float ma;

    ma = s*(1.0/c);

    return ma;
}

