/*
    Aula Pratica 05 - Questão 6
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/
#include <stdio.h>


void converterDistancias(float , float *, float *, float *);

int main(){

    printf("Digite o valor em Metros: ");
    float m=0.0;
    scanf("%f", &m);

    float j= 0.0, p=0.0, pl= 0.0;

    converterDistancias(m, &j, &p, &pl);


    printf("\nJardas: %.3f",j);
    printf("\nPés: %.3f",p);
    printf("\nPolegadas: %.3f",pl);


    return 0;
}


void converterDistancias(float metros, float *jardas, float *pes, float *polegadas){

    *jardas = metros*1.094;
    *pes = metros*3.281;
    *polegadas = metros*39.3701;
}