/*
    Aula Pratica 05 - Questão 1
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/

#include <stdio.h>
#include <math.h>

float calcIMC(float, float);

int main(){

    printf("Entre com o peso: ");
    float p = 0.0;
    scanf("%f", &p);

    printf("\nEntre com a altura: ");
    float a = 0.0;
    scanf("%f", &a);

    float i = calcIMC(p, a);

    if(i < 18.5){
        printf("\nAbaixo do peso");
    }else if(18.5 <= i && i < 25){
        printf("\nPeso normal");
    }else if(25 <= i && i < 30){
        printf("\nAcima do peso");
    }else{
        printf("\nObeso");

    }

    return 0;
}

float calcIMC(float p, float a){
    float i = 0.0;

    i = p/pow(a, 2);

    return i;
}