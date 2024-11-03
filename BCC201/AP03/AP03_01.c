/*
    Aula Pratica 03 - Questão 1
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/

#include <stdio.h>

int main() {
    int n1, n2;

    printf("Digite dois valores: ");
    scanf("%d %d", &n1, &n2);

    if (n1 < n2) {
        printf("%d maior e %d menor\n", n2, n1);
    } else {
        printf("%d maior e %d menor\n", n1, n2);
    }

    return 0;
}

