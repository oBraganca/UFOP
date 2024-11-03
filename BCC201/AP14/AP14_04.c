#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nm[50];
    float nt;
    int f;
} Aluno;

int main() {
    int cond = 1, count = 0;
    Aluno *alunos = NULL;

    printf("Digite 1 para entrar um aluno ou 0 para encerrar: ");
    scanf("%d", &cond);
    if (!cond) {
        return 0;
    }

    FILE *f = fopen("alunos.txt", "w");
    if (f == NULL) {
        printf("Não foi possível criar o arquivo\n");
        return 0;
    }

    fprintf(f, "%d\n", 0);

    do {
        Aluno *temp = (Aluno *) realloc(alunos, (count + 1) * sizeof(Aluno));
        if (temp == NULL) {
            printf("Erro ao alocar memória\n");
            free(alunos);
            fclose(f);
            return 0;
        }
        alunos = temp;

        scanf("%s %f %d", (alunos + count)->nm, &(alunos + count)->nt, &(alunos + count)->f);

        if (count == 0) {
            fprintf(f, "%s %.1f %d\n", (alunos + count)->nm, (alunos + count)->nt, (alunos + count)->f);
        } else {
            fprintf(f, "%s %.1f %d\n", (alunos + count)->nm, (alunos + count)->nt, (alunos + count)->f);
        }

        count++;

        printf("\nDigite 1 para entrar um aluno ou 0 para encerrar: ");
        scanf("%d", &cond);
    } while (cond);

    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d\n", count);

    free(alunos);
    fclose(f);

    return 0;
}
