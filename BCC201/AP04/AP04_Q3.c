/*

    Thayllon Ryan Bragança de Almeida
    Matricula - 24.1.9902

    Questão 3
*/

#include <stdio.h>

#define OZ_U 33.814
#define GA_U 0.264172


void converteLiquidos(float litros, float *oz, float *gallons){
    *oz = litros*OZ_U;
    *gallons = litros*GA_U;
}


int main(){
    float l;
    float o, g;

    printf("Digite o total em litros: ");
    scanf("%f", &l);

    converteLiquidos(l, &o, &g);
    
    printf("\nTotal em oz: %.2f", o);
    printf("\nTotal em gallons: %.2f\n", g);


    return 0;
}

