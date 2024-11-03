/*
    Aula Pratica 05 - Questão 4
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/
#include <stdio.h>

int calcTime(int, int, int, int);

int main(){

    printf("Entre com o horário de início: ");
    int h = 0, m = 0;
    scanf("%d %d", &h, &m);

    printf("Entre com o horário de término: ");
    int h2 = 0, m2 = 0;
    scanf("%d %d", &h2, &m2);

    int rm = calcTime(h, m, h2, m2);

    printf("Duração: %d minutos", rm);

    return 0;
}

int calcTime(int h, int m, int h2, int m2){
    int tm=0;
    
    h2 = (h2*60)+m2;
    h = (h*60)+m;

    if(h2 < h){
        h2+=60*24;
    }

    return h2 - h;


}   