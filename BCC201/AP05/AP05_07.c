/*
    Aula Pratica 05 - Questão 7
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/
#include <stdio.h>

void converteHora(long , int *, int *, int *);

int main(){

    printf("Digite o total de segundos: ");
    int st;
    scanf("%d", &st);
    int h, m, s;
    converteHora(st, &h, &m, &s);

    printf("Hora convertida: %02d:%02d:%02d", h, m, s);

    return 0;
}

void converteHora(long totalSegundos, int *hora, int *min, int *seg){

    int aux = 0;
    *hora = totalSegundos/3600;
    totalSegundos = totalSegundos%3600;
    *min = totalSegundos/60;
    totalSegundos = totalSegundos%60;
    *seg = totalSegundos;

}