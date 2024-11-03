/*
    Aula Pratica 05 - Questão 5
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/
#include <stdio.h>

void converterCelsius(float, float *, float *);


int main (){


    printf("Digite o valor em Celsius: ");
    float c=0.0;
    scanf("%f", &c);

    float f= 0.0, k=0.0;

    converterCelsius(c, &f, &k);

    printf("\nFahrenheit: %.2f",f);
    printf("\nKelvin: %.2f",k);

    return 0;
}


void converterCelsius(float celsius, float *fahrenheit, float *kelvin){
    *fahrenheit = celsius*9/5+32;
    *kelvin = celsius+273.15;
}