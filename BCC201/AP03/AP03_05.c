/*
    Aula Pratica 03 - Questão 1
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/

#include <stdio.h>
#include <math.h>

int main(){
    printf("### CONVERSOR DE UNIDADES ###\n");

    printf("\n1) Angulo\n");
    printf("2) Temperatura\n");

    printf("\nDigite uma opcao: " );
    int o;
    scanf("%d", &o);
    int o2;
    switch(o){
    
        case 1:
            printf("\nQual a unidade de origem?\n");

            printf("\n1) Graus\n");
            printf("2) Radianos\n");

            printf("\nSelecione uma opcao: ");
            scanf("%d", &o2);
    
            float u; // Unit
            float uo; // Unit output
            switch(o2){
                case 1:
                    printf("\nDigite o valor em Graus: ");
                    scanf("%f", &u);
                    uo = u*(M_PI/180.00);
                    printf("Valor em Radianos: %.2f\n", uo);
                    break;

                case 2:
                    printf("\nDigite o valor em Radianos: ");
                    scanf("%f", &u);
                    uo = u*(180.00/M_PI);
                    printf("Valor em Graus: %.2f\n",uo);
                    break;
                default:
                    printf("\nOpcao invalida!");
                    break;
            }
            break;

        case 2:
            printf("\nQual a unidade de origem?\n");

            printf("\n1) Celsius\n");
            printf("2) Fahrenheit\n");
            printf("3) Kelvin\n");
            
            printf("\nSelecione uma opcao: ");
            scanf("%d", &o2);

            float cl, fa, ke;

            switch(o2){
                case 1:
                    printf("\nDigite o valor em Celsius: ");
                    scanf("%f", &cl);
                    fa = (cl*(9.0/5.0))+32;
                    ke = cl+273.15;
                    printf("Valor em Fahrenheit: %.2f\n", fa);
                    printf("Valor em Kelvin: %.2f\n", ke);
                    break;

                case 2:
                    printf("\nDigite o valor em Fahrenheit: ");
                    scanf("%f", &fa);
                    cl = (fa-32)*(5.0/9.0);
                    ke = cl + 273.15;
                    printf("Valor em Celsius: %.2f\n", cl);
                    printf("Valor em Kelvin: %.2f\n", ke);
                    break;

                case 3:
                    printf("\nDigite o valor em Kelvin: ");
                    scanf("%f", &ke);
                    cl = ke-273.15;
                    fa = (cl * (9.0/5.0)) + 32;
                    printf("Valor em Celsius: %.2f\n", cl);
                    printf("Valor em Fahrenheit: %.2f\n", fa);
                    break;
                default:
                    printf("\nOpcao invalida!");
                    break;
            }
            break;
    
        default:
            printf("\nOpcao invalida!");
    
    }
    return 0;
}
