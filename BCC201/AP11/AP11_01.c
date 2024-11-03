/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    Questão 01

*/

#include <stdio.h>

typedef struct {
    double real;
    double imaginario;
} Complexo;

Complexo somaComplexo(Complexo, Complexo);
Complexo subComplexo(Complexo, Complexo);
Complexo multComplexo(Complexo, Complexo);



int main(){

    printf("Calculadora de números complexos!\n");

    printf("Digite os valores de a e b (x = a + bi): ");
    Complexo x;
    scanf("%lf %lf", &x.real, &x.imaginario);

    printf("\nDigite os valores de c e d (y = c + di): ");
    Complexo y;
    scanf("%lf %lf", &y.real, &y.imaginario);


    getchar();
    printf("\nDigite a operação (+, - ou *): ");
    char op;
    scanf("%c", &op);
    Complexo r;
    switch(op){


        case '+':
            r = somaComplexo(x, y);
            printf("\nResultado: %.1lf + %.1lfi\n", r.real, r.imaginario);
            break;
        case '-':
            r = subComplexo(x, y);
            printf("\nResultado: %.1lf - %.1lfi\n", r.real, r.imaginario);
            break;
        case '*':
            r = multComplexo(x, y);
            printf("\nResultado: %.1lf + %.1lfi\n", r.real, r.imaginario);
            break;
    }




    return 0;
}



Complexo somaComplexo(Complexo x, Complexo y){
    Complexo r;

    r.real = x.real+y.real;
    r.imaginario = x.imaginario+y.imaginario;


    return r;
}

Complexo subComplexo(Complexo x, Complexo y){
    Complexo r;

    r.real = x.real-y.real;
    r.imaginario = x.imaginario-y.imaginario;


    return r;
}

Complexo multComplexo(Complexo x, Complexo y){
    Complexo r;

    //ac−bd+(ad+bc)i

    r.real = (x.real*y.real)-(x.imaginario*y.imaginario);
    r.imaginario = ((x.real*y.imaginario)+(x.imaginario*y.real));


    return r;
}
