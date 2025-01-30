#include "recursao.h"
#include <stdio.h>

int mod(int x, int y) {
    if(x==y){
        return 0;
    }
    if(x<y){
        return x;
    }else{

        return mod(x-y, y);
    }
}

int mdc(int x, int y) {
    return y==0?x:mdc(y,mod(x,y));
}

int mmcRec(int x, int y, int z) {
    return mod(z,x)==0&&mod(z, y)==0? z : mmcRec(x, y, z+(x>y?x:y));
}

int mmc(int x, int y) {
    return mmcRec(x, y, x>y?x:y);
}
