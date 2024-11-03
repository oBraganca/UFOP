/*
 * Thayllon Bragança
 * 24.1.9902
 * Questão 01
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int size);

int main(){

    printf("Digite o valor de n: ");
    int n=0;
    scanf("%d", &n);

    int *v1 = (int*)malloc(n * sizeof(int));
    if(v1 == NULL){
        printf("\nNão foi possível criar o vetor, tente novamente\n");
        return 0;
    }

    float m = 0.0;

    printf("Digite os valores do vetor: ");
    for(int i = 0; i < n; i++){
        scanf("%d", v1 + i);
        m += *(v1 + i);
    }

    m /= n;
    int ma = 0, mn = 0;

    // Contagem de valores acima e abaixo da média
    for(int i = 0; i < n; i++){
        if(*(v1 + i) < m)
            mn++;
        else
            ma++;
    }

    // Alocação dos vetores
    int *vm = (int*)malloc(ma * sizeof(int));
    int *vmn = (int*)malloc(mn * sizeof(int));

    if(vm == NULL || vmn == NULL){
        printf("\nNão foi possível criar o vetor, tente novamente\n");
        return 0;
    }

    int ama = 0, amn = 0;

    // População dos vetores
    for(int i = 0; i < n; i++){
        if(*(v1 + i) < m){
            *(vmn + amn) = *(v1 + i);
            amn++;
        } else {
            *(vm + ama) = *(v1 + i);
            ama++;
        }
    }


    sort(vm, ma);
    sort(vmn, mn);

    printf("\nA média é: %.1f\n", m);

    printf("Vetor com os valores abaixo da média: [ ");
    for(int i = 0; i < mn; i++){
        printf("%d ", *(vmn + i));
    }
    printf("]\n");

    printf("Vetor com os valores iguais ou acima da média: [ ");
    for(int i = 0; i < ma; i++){
        printf("%d ", *(vm + i));
    }
    printf("]\n");

    free(v1);
    free(vm);
    free(vmn);

    return 0;
}

void sort(int* arr, int size) {
    int aux = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(*(arr+i) > *(arr+j)) {
                aux = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = aux;
            }
        }
    }
}
