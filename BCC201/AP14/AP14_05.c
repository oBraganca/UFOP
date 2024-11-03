/*
 * Thayllon Bragança
 * 24.1.9902
 * Questão 05
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nm[50];
    float nt;
    int f;
} Aluno;


int main(){

    printf("Digite o nome do arquivo: ");
    char nm[50], buffer;
    scanf("%s", nm);


    FILE *f = fopen(nm, "r");

    if(f == NULL){
        printf("Não foi possivel abrir o arquivo");
        return 0;
    }

    int n=0;
    fscanf(f,"%d%c",&n,&buffer);

    Aluno *alunos = (Aluno*)malloc(n*sizeof(Aluno));


    float nts=0.0, freq = 0.0, apr=0.0;
    for(int i = 0; i<n; i++){
        fscanf(f, "%s %f %d%c",alunos[i].nm, &alunos[i].nt, &alunos[i].f, &buffer);
        nts+=alunos[i].nt;
        freq+=alunos[i].f;
    }

    freq/=(float)n;
    nts/=(float)n;
    float qtnp=0;
    for(int i = 0; i<n; i++){
        if(alunos[i].nt >= nts){
            qtnp++;
        }
    }
    qtnp/=(float)n;
    qtnp*=100;

    printf("Nota média: %.1f\n", nts);
    printf("Frequência média: %.0f%\n", freq);
    printf("Percentual de aprovação: %.0f%\n", qtnp);
    printf("Nome dos alunos com nota acima da nota média:\n");
    for(int i = 0; i<n; i++){
        if(alunos[i].nt > nts){
            printf("%s\n", alunos[i].nm);
        }
    }

    fclose(f);
    free(alunos);


    return 0;
}
