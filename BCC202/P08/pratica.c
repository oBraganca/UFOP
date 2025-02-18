#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        char c = getchar(); // Consumir a quebra de linha após ler p
        c = getchar(); // Consumir a quebra de linha após ler p

        Pessoa *pessoas = alocaVetor(p);
        if (pessoas == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            return 1;
        }

        for (int j = 0; j < p; j++) {
            char linha[100]; // Buffer temporário para leitura da linha completa
            fgets(linha, sizeof(linha), stdin);

            // Extrai nome e idade
            int idade;
            char nome[100];
            sscanf(linha, "%[^0-9] %d", nome, &idade);

            // Removendo espaços em branco extras no final do nome
            int len = strlen(nome);
            while (len > 0 && (nome[len - 1] == ' ' || nome[len - 1] == '\t')) {
                nome[len - 1] = '\0';
                len--;
            }

            strcpy(pessoas[j].nome, nome);
            pessoas[j].idade = idade;
        }

        MergeSort(pessoas, 0, p - 1);

        printf("Teste %d:\n", i + 1);
        for (int j = 0; j < p; j++) {
            printf("%s %d\n", pessoas[j].nome, pessoas[j].idade);
        }
        printf("\n");

        desalocaVetor(&pessoas);
    }

    return 0;
}
