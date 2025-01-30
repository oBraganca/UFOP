#include <stdio.h>
#include "duende.h"

/*
 *
 * Complexidade:
    - escalarTimes:
        O tempo de complexidade é dada pela seguinte equação (considerando as constants em if):
        Sabendo que e dada por 4*qntDuendes/4

        f(n) = n

        Por tanto,

        n <= O(n)
        n <= cn
        c >= 1 para todo c > 0 ^ n>=m para qualquer m >= 1



    - proximoMaisVelho
        O tempo de complexidade é dada pela seguinte equação (considerando as constants em if):
        2*n, sendo n a quantidade de duendes.

        2n <= O(n)
        2n <= cn
        c >= 2 para todo c > 0 ^ n>=m para qualquer m >= 1

 * */

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 4;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes);
    printTimes(times, qtdTimes);
    desalocaDuendes(duendes);
    desalocaTimes(times);

    return 0; //nao remova
}
