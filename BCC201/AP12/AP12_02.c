/*
 Thayllon Ryan Bragança de Almeida
 24.1.9902
 Questão 02

 */

#include <stdio.h>
#include <math.h>

typedef struct {
   char i;
   float x;
   float y;
}Point;

float calcDist(Point, Point);

int main(){

    printf("Digite o nome do arquivo: ");
    char n[30], l;
    int qp=0;
    scanf("%s", n);
    FILE*f = fopen(n, "r");

    fscanf(f, "%d%c", &qp, &l);

    Point p, vp[3];
    for(int i =0; i<3; i++){
        fscanf(f, "%c%f%f%c", &p.i, &p.x, &p.y, &l);
        vp[i] = p;
    }



    for(int i = 1; i<3; i++){
        printf("\nDistância entre %c e %c: %.2f\n", vp[0].i, vp[i].i, calcDist(vp[0], vp[i]));
    }




    return 0;
}

float calcDist(Point a, Point b){
    return sqrt(pow(b.x-a.x, 2)+pow(b.y-a.y, 2));
}
