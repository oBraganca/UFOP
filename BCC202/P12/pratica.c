#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int main() {
    Hash hash;
    Chave chave;
    int n;

    int p, m, s;
    scanf("%d",&n);
    // PREENCHER AQUI

    while (n-- > 0) {

        scanf("%d",&m);
        scanf("%d",&p);

        inicia(&hash, m, p);
        for(int i = 0; i < hash.p; i++) {
          scanf("%d",&hash.pesos[i]);
        }

        scanf("%d",&s);

        int l = -1;
        for(int i = 0; i < s; i++) {
            scanf("%s",chave);
            l = insere(&hash, chave);
        }

        printf("%d\n",l);
    }

    return 0;
}