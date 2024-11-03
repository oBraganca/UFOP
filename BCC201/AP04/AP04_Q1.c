/*

    Thayllon Ryan Bragança de Almeida
    Matricula - 24.1.9902

    Questão 1
*/

#include <stdio.h>
#include <math.h>


float calculaArea(float s){
    float a;
    a = 3*pow(s,2)*sqrt((25.0+10.0*sqrt(5.0)));


    return a;
}

int main(){
    float a,s;

    printf("Digite o lado do dodecaedro regular: ");
    scanf("%f", &s);

    a = calculaArea(s);
    
    printf("\nA area e: %.2f", a);


    return 0;
}

