/*
    Aula Pratica 03 - Questão 1
    Numero de Matricula: 24.1.9902
    
    Thayllon Ryan Bragnaça de Almeida
*/

#include <stdio.h>

int main(){

    char f;
    int i, t;
    printf("Digite o sexo: ");
    scanf("%c", &f);

    printf ("\nDigite a idade: ");
    scanf("%d", &i);

    printf("\nDigite o tempo de contribuição para o INSS: ");
    scanf("%d", &t);

    int p=0;
    switch(f){
        case 'F':
            p = i+t;
            if((i >= 60 && t >= 30)||(p>=90)){
                printf("\nVoce pode se aposentar com salario integral\n");
            }else{
                printf("\nVoce nao pode se aposentar com salario integral\n");
            }
            break;
        
         case 'M':
            p = i+t;
            if((i >= 65 && t >= 35)||(p>=100)){
                printf("\nVoce pode se aposentar com salario integral\n");
            }else{   
                printf("\nVoce nao pode se aposentar com salario integral\n");
            }  
            break;

    }

    return 0;
}
