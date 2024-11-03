/*
    Aula Pratica 05 - Questão 2
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/
#include <stdio.h>

void calcSalary(float, int, float*, float*);


int main(){

    printf("Entre com o salário: ");
    float s;
    scanf("%f", &s);

    printf("\nEntre com o código do cargo: ");
    int c;
    scanf("%d", &c);

    float n = 0.0, d = 0.0;

    calcSalary(s, c, &n, &d);
    
    printf("\nAntigo: R$ %.2f", s);
    printf("\nNovo: R$ %.2f", n);
    printf("\nDiferença: R$ %.2f", d);
    

    return 0;
}


void calcSalary(float s, int c, float *n, float *d){

    switch(c){
        case 100:
            *n = s + (s * 0.03);
            *d = *n - s;
            break;

        case 101:
            *n = s + (s * 0.05);
            *d = *n - s;
            break;

        case 102:
            *n = s + (s * 0.075);
            *d = *n - s;
            break;

        case 201:
            *n = s + (s * 0.10);
            *d = *n - s;
            break;
        default:
            *n = s + (s * 0.15);
            *d = *n - s;
            break;
    }

}