/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    thayllon.almeida@aluno.ufop.edu.br 

    Questão - 03
*/


#include <stdio.h>

int quadrado_por_soma(int);

int main(){

    float n1 = 0.0, n2 = 0.0;
    float m = 0.0;
    printf("Digite as notas do aluno: "); 
    scanf("%f %f", &n1, &n2);
    if(n1 < 0 || n2 < 0){
        return 0;
    }
    while(n1 >=0 && n2 >= 0){
        m = (float)(n1+n2)/2;
        printf("\nA média das notas é %.1f\n", m);

        printf("\nDigite as notas do aluno: "); 
        scanf("%f %f", &n1, &n2);
    }
    return 0;

}
