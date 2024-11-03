/*

    Thayllon Ryan Bragança de Almeida
    Matricula - 24.1.9902

    Questão 2
*/

#include <stdio.h>


void ordena3valores(int a, int b, int c, int* menor, int* meio, int* maior){

    if(a < b && a < c){
        *menor = a;
    }else if(a > b && a > c){
        *maior = a;
    }else{
        *meio = a;
    }

    if(b < a && b < c){
        *menor = b;
    }else if(b > a && b > c){
        *maior = b;
    }else{
        *meio = b;
    }

    if(c < b && c < a){
        *menor = c;
    }else if(c > b && c > a){
        *maior = c;
    }else{
        *meio = c;
    }


}

int main(){
    int a,b,c;
    int menor,meio,maior;

    printf("Digite três valores: ");
    scanf("%d %d %d", &a, &b, &c);

    ordena3valores(a, b, c, &menor, &meio, &maior);
    
    printf("\nOs valores ordenados são: %d %d %d\n", menor, meio, maior);


    return 0;
}

