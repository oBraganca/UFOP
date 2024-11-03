/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    Questão 03
*/

#include <stdio.h>

#define L 15
#define T 4

typedef struct{
    char n[L];
    float f;
    float h;

}Elet;

Elet insertElet(int);
float calcTotalCom(Elet*, int);
void calcPercByElet(Elet*, int, float);

int main(){

    Elet le[T];
    for(int i =0; i<T; i++){
        *(le+i) = insertElet(i);
        printf("\n");
    }

    printf("\nNúmero de dias para cálculo: ");
    int n;
    scanf("%d", &n);


    float tc = calcTotalCom(le, n);
    printf("\nConsumo total: %.1f kW\n\n", tc);

    calcPercByElet(le, n, tc);
    printf("\n");
    return 0;
}

Elet insertElet(int i){

    Elet e;

    printf("Eletrodoméstico %d\n", i);
    printf("Nome: ");
    scanf("%s", e.n);
    printf("\nConsumo (kW/h): ");
    scanf("%f", &e.f);
    printf("\nTempo ativo em horas: ");
    scanf("%f", &e.h);

    return e;
}


float calcTotalCom(Elet *le, int n){
    float r=0.0;

    for(int i =0; i<T; i++){
        r+=((le+i)->f*(le+i)->h)*n;
    }

    return r;
}
void calcPercByElet(Elet *le, int n, float tc){
    float r;

    printf("Porcentagens:\n\n");
    if(tc == 0){
        tc = 1;
        n = 0;
    }
    for(int i =0; i<T; i++){
        r = ((((le+i)->f*(le+i)->h)*n)/tc)*100;
        printf("%s %.2f%\n", ((le+i))->n, r);

    }
}
