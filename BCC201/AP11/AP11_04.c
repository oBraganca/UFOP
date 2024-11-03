/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    Questão 04
*/

#include <stdio.h>

typedef struct {
    int n;
    int d;
} Racional;

int gcd(int a, int b);
void simplificar(Racional *r);
int equal(Racional*, Racional*);

int main(){
    Racional r1, r2;

    printf("Digite numerador e denominador de r1: ");
    scanf("%d %d", &r1.n, &r1.d);

    printf("Digite numerador e denominador de r2: ");
    scanf("%d %d", &r2.n, &r2.d);

    if(equal(&r1, &r2)){
        printf("\nr1 e r2 são iguais a (%d / %d)!", r1.n, r1.d);
    }else{
        printf("\nr1 e r2 são diferentes!");
    }

    printf("\n");

    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificar(Racional *r) {
    int divisor = gcd(r->n, r->d);
    r->n /= divisor;
    r->d /= divisor;
}

int equal(Racional *r1, Racional *r2) {
    simplificar(r1);
    simplificar(r2);

    if (r1->n == r2->n && r1->d == r2->d) {
        return 1;
    }
    return 0;
}
