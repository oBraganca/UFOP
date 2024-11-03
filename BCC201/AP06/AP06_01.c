/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    thayllon.almeida@aluno.ufop.edu.br 

    Questão - 01
*/


#include <stdio.h>

void multiplyBy(int);

int main(){
    printf("Digite o valor de n: ");
    int n = 0;
    scanf("%d", &n);

    multiplyBy(n);

    printf("\n");
    return 0;

}

void multiplyBy(int n){
    int i = 1;
    printf("\nOs divisores de %d são: ", n);
    while (i<=n){
        if(n%i == 0){
            printf("%d ", i);
        }
        i ++;
    }
}