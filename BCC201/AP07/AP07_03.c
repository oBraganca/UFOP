/*
    Thayllon Bragança
    24.1.9902
    Atividade 03
*/

#include <stdio.h>

float calcMA(int, int);

int main(){


    int n=0;
    int s=0;
    int c=0;
    do{

        printf("Digite um valor: ");
        n=0;
        scanf("%d", &n);
        s += n;

        if(n!=0){
            c++;
        }

    }while(n != 0);

    if(s != 0){
        float ma = calcMA(s,c);
        
        printf("MA = %.2f\n", ma);

    }else{
        printf("Não foi possível calcular MA!\n");
    }


    return 0;
}

float calcMA(int s, int c){
    float ma;

    ma = s*(1.0/c);

    return ma;
}

