/*
    Thayllon Bragança
    24.1.9902
    Atividade 01
*/


#include <stdio.h>

long long fat(int);

int main(){

    printf("Digite o valor de n: ");
    int n=0;
    scanf("%d", &n);

    long long f = fat(n);

    printf("%d! = %lld\n",n, f);

    return 0;
}

long long fat(int n){
    long long f = 1;
    for (int i = n; i>=1; i--){
        f *= i;
    }
    return f;
}