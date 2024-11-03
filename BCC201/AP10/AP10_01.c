/*
	Thayllon Ryan Bragança de Almeida
	24.1.9902
	Questão 01
*/

#include <stdio.h>

#define TAM 3

int main(){

	int a[TAM][TAM];
	
	printf("Digite os elementos da matriz: ");
	
	for(int i =0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			scanf("%d", *(a+i)+j);	
		}
	}
	int m = *(*(a)), mn =*(*(a));
	
	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			if(m < *(*(a+i)+j)){
				m = *(*(a+i)+j);
			}
			
			if( *(*(a+i)+j) < mn){
				mn =*(*(a+i)+j);
			}
		}
	}
	
	
	printf("\nMaior elemento: %d\n", m);
	printf("Menor elemento: %d\n", mn);
	
		
	


	return 0;
}
