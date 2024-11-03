/*
    Thayllon Ryan Bragança de Almeida
    24.1.9902

    Questão 04

*/


#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define TAM 60

int main(){
    char s[TAM];
    printf("Digite o nome completo: ");

    fgets(s, TAM, stdin);

    
    int c=0, c1=0;
    int tam = strlen(s);
    
    int j = tam-1;
    
    if(s[j] == '\n'){
        j--;
    }

    for(int i=j; s[i] != ' '; i--){
        c1++;
    }

    

    // j+1 para ignorar o espaço no antes do sobrenome
    for(int i = (j+1)-c1; i<= j ;i++){
        printf("%c", s[i]);
    }
    printf(", ");
    for(int z=0; z <j-c1; z++){
        printf("%c", s[z]);
        if(s[z]!='\n' && s[z] != ' '){
            c++;
        }
    }

    printf("\n");

    printf("\nTotal de letras: %d\n", c+c1);
    printf("Total de letras do último sobrenome: %d\n", c1);

    return 0;
}