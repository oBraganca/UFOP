#include <stdio.h>
#include "recursao.h"

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("MDC = %d\n", mdc(mdc(x,y), z));
    printf("MMC = %d", mmc(mmc(x, y), z));
    return 0;
}