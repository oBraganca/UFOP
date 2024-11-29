#include <stdio.h>

void readMatrix(double matrix[12][12]);
double sumMatrix(double matrix[12][12]);

int main()
{
    double s = 0.0, M[12][12];
    char T;

    scanf("%c", &T);
    
    readMatrix(M);

    int c = 1;
    do{
        switch(T){
            case 'S':
                s = sumMatrix(M);
                printf("%.1lf\n", s);
                c = 0;
            break;
            case 'M':
                s = sumMatrix(M);
                printf("%.1lf\n", s/30);
                c = 0;
            break;
            default: 
                printf("Valor invalido");
            break;
        }

    }while(c);


    // Impressão dos resultados



    return 0;
}

void readMatrix(double matrix[12][12]) {

    for(int i =0; i<12; i++){
        for(int j=0; j<12; j++){
           scanf("%lf", &matrix[i][j]); 
        }
    }

}

double sumMatrix(double matrix[12][12]) {
    double resultado = 0;
    int aux = 5;
    int aux2 = 5;

    for(int i =7; i<12; i++){
        for(int j = aux; j <= 11-aux; j++){
            resultado+=matrix[i][j];
        }
        aux--;
    }

    return resultado;
}