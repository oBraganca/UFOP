/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    thayllon.almeida@aluno.ufop.edu.br 

    Questão - 02
*/


#include <stdio.h>

int quadrado_por_soma(int);

int main(){

    

    printf("Digite um número: "); 
    int n = 0;
    scanf("%d", &n);

    int sqrt = quadrado_por_soma(n);

    printf("\nO quadrado de %d é %d\n", n, sqrt);
    return 0;

}


int quadrado_por_soma(int n){
    int sqrt=0;

    int count = 1;
    for(int i=0; i<n; i++){
        
        sqrt += count; 
        count +=2;
    }

    return sqrt;
}