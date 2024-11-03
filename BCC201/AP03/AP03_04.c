/*
    Aula Pratica 03 - Questão 1
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/

#include <stdio.h>

int main (){
    printf("Digite o preço do produto: ");
    float v;
    scanf("%f", &v);


    printf("\nDigite a condição de pagamento: ");
    int c;
    scanf("%d", &c);

    float f;
    switch(c){
    
        case 1:
            f = v - (v*0.10);
            printf("\nO valor final do seu produto sera: R$ %.2f\n", f);
            break;

        case 2:
            f = v - (v*0.05);
            printf("\nO valor final do seu produto sera: R$ %.2f\n", f);
            break;

        case 3:
            f = v;            
            printf("\nO valor final do seu produto sera: R$ %.2f\n", f); 
            break;

        case 4:
            f = v + (v*0.10);                       
            printf("\nO valor final do seu produto sera: R$ %.2f\n", f); 
            break;

        default:
            printf("\nCondicao de pagamento invalida\n");
            break;
    }

    return 0;
}

