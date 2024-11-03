/*

    Thayllon Ryan Bragança de Almeida
    Matricula - 24.1.9902

    Questão 4
*/

#include <stdio.h>
#include <math.h>

int calculaRaizes(float a, float b, float c, float *r1, float *r2){
    float d = pow(b,2)-4*a*c;
    
    if(d < 0){
        return 0;
    }


    *r1 = (-b+sqrt(d))/(2*a);
    *r2 = (-b-sqrt(d))/(2*a);
    
    return 1;
}


int main(){
    
    float a, b, c;
    float r1, r2;
    
    printf("Digite os valores de a, b , c:\n");
    scanf("%f %f %f", &a, &b, &c);

    int r = calculaRaizes(a, b, c, &r1, &r2);

    if(r == 0){
        printf("\nNão foi possível calcular as raízes!\n");
    }else{
        printf("\nx1 = %.2f", r1);
        printf("\nx2 = %.2f\n", r2);
    }



    return 0;
}

