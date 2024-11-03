/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    Questão 01

*/

#include <stdio.h>
#include <string.h>
#define TAM 25

typedef struct{
    char m[TAM];
    double c;
}Carro;

Carro insertCar(int);
void economycCar(Carro *);
void cosumByKmCar(Carro *, int);

int main(){
    Carro c[5];
    for(int i =0; i<5; i++){
        c[i] = insertCar(i);
        printf("\n");
    }

    economycCar(c);
    printf("\nConsumo em 1000 km\n\n");
    cosumByKmCar(c, 1000);

    return 0;
}


Carro insertCar(int n){
    Carro c;

    printf("Carro %i\n", n);
    printf("Modelo: ");
    scanf("%s", c.m);
    printf("\nConsumo (km/l): ");
    scanf("%lf", &c.c);

    return c;
}

void economycCar(Carro *c){
    int e=0;
    for(int i = 1; i<5; i++){
        if((c+i)->c > (c+e)->c){
            e = i;
        }
    }
    printf("Mais econômico: %s\n",(c+e)->m);
}

void cosumByKmCar(Carro *c, int km){
    for(int i =0; i<5; i++){
        printf("%s %.2lf\n", (c+i)->m, km/(c+i)->c);
    }
}
