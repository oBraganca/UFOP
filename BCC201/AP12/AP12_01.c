/*
 Thayllon Ryan Bragança de Almeida
 24.1.9902
 Questão 01

 */


#include <stdio.h>

typedef struct {
   char i;
   float x;
   float y;
}Point;

Point addPoint(int);

int main(){
    FILE *f;
    char n[30];
    printf("Digite o número de pontos: ");
    int qp=0;
    scanf("%d", &qp);

    Point vp[5];

    for(int i =0; i<qp; i++){
        getchar();
        vp[i] = addPoint(i+1);
    }


    printf("Digite o nome do arquivo para salvamento: %s", n);
    scanf("%s",n);
    f = fopen(n, "a");

    fprintf(f, "%d\n", qp);

    for(int i =0; i<qp; i++){
        fprintf(f, "%c %.1f %.1f\n", vp[i].i, vp[i].x, vp[i].y);
    }

    fclose(f);



    return 0;
}

Point addPoint(int i){
    Point p;

    printf("\nPonto %d:\n", i);
    printf("Digite o identificador, a coord. x e coord. y: ");
    scanf("%c%f%f",&p.i, &p.x, &p.y);

    return p;
}
