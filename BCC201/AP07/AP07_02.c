/*
    Thayllon Bragança
    24.1.9902
    Atividade 02
*/

#include <stdio.h>



int primo(int);

int main(){

    printf("Digite um número: ");
    int n=0;
    scanf("%d", &n);

    int t = primo(n);

    if(t){
        printf("\n%d é um número primo!\n", n);
    }else{
        printf("\n%d não é um número primo!\n", n);
    }
    return 0;
}

int primo(int n){
    for(int i=1; i<= n; i++){
        if(n == 1 || (n%i==0 && (i!=1 && i!=n))){
            return 0;
        }
    }
    return 1;
}
