/*
	Thayllon Ryan Bragança de Almeida
	24.1.9902
	Questão 02
*/

#include <stdio.h>

#define TAM 4

void imprimeM(int(*)[]);
void imprimeOddM(int (*)[]);

int main(){
	int m[TAM][TAM];
	
	int n=0;
	
	printf("Digite os valores da matriz:\n");
	for(int i =0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			scanf("%d", (*(m+i)+j));
			
			if(*(*(m+i)+j)<0){
				j--;
			}
		}
	}
	
	imprimeM(m);
	printf("\n");
	printf("Posições de valores pares:\n\n");
	imprimeOddM(m);
	
	
	return 0;
}

void imprimeM(int (*m)[TAM]){
	for(int i =0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			printf("%d ", *(*(m+i)+j));
		}
		printf("\n");
	}
}

void imprimeOddM(int (*m)[TAM]){
	for(int i =0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			if(*(*(m+i)+j) %2==0)
				printf("%d %d\n", i, j);
		}
	}
}

