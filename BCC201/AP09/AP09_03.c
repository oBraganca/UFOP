/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902

    Questão 03

*/


#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define TAM 50

int main(){
    char s[TAM], l1, l2;
    printf("Digite a frase: ");

    fgets(s, TAM, stdin);

    printf("Digite L1: ");
    scanf("%c", &l1);
    __fpurge(stdin);
    printf("Digite L2: ");
    scanf("%c", &l2);
    __fpurge(stdin);


    int i=0;
    while(s[i] != '\0'){
        if(s[i] == l1){
            s[i] = l2;
        }
        i++;
    }

    printf("%s", s);




    printf("\n");
    return 0;
}