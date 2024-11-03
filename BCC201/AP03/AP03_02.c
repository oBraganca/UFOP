/*
    Aula Pratica 03 - Questão 1
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/

#include <stdio.h>

#include <stdio.h>
#include <string.h>

int main() {
    int m;
    float n;
    char c[20];  // Defina um tamanho adequado para o array

    printf("Digite a matricula: ");
    scanf("%d", &m);

    printf("\nDigite a nota: ");
    scanf("%f", &n);

    if (n >= 9) {
        strcpy(c, "Conceito A");
    } else if (n >= 8 && n < 9) {
        strcpy(c, "Conceito B");
    } else if (n >= 6 && n < 8) {
        strcpy(c, "Conceito C");
    } else if (n >= 3 && n < 6) {
        strcpy(c, "Conceito D");
    } else {
        strcpy(c, "Conceito E");
    }

    printf("\nMatricula: %d\n", m);
    printf("%s\n", c);

    return 0;
}

