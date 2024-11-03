/*
    Thayllon Ryan Bragança de Almeida
    Matricula: 24.1.9902
    Exercicio 03
 */

#include <stdio.h>


int main(){
    int x=0, y=0;
    //int c=0
    do{

        printf("\n");
        printf("Digite os valores de x e y:");
        scanf("%d %d", &x, &y);
        if((x>y)){
            printf("\nx deve ser menor do que y.\n");
            continue;
        }else if(x%2!=0 && y%2==0){
            printf("\nApenas números pares são aceitos\n");
            continue;
        }else if((x<0||y<0)){
            printf("\nApenas números pares são aceitos\n");
            continue;
        }else{
            break;
        }
    }while(1);

    int aux;
    int n = (y - x) / 2;

    printf("\n");

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }

        for (int j = 0; j < x + 2 * i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}