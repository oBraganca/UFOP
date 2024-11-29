#include "carro.h"
#include "stdio.h"

int main() {
    int n, ano, lugares;
    char c, nome[21];
    scanf("%d\n", &n);
    scanf("%c", &c);
    if (c == 'C')
        scanf("%d %d", &ano, &lugares);
    else
        scanf("%s", nome);
    Carro* carros = CarroAloca(n);
    le(carros, n);
    if (c == 'C')
        printf("%d\n", conta(carros, n, ano, lugares));
    else
        imprime(carros, n, nome);
    CarroDesaloca(&carros, n);
    return 0;
}