/*
	Thayllon Ryan Bragança de Almeida
	24.1.9902
	Questão 03
*/

#include <stdio.h>

#define TAM 10

void imprime(int (*)[], int, int, int);

int main(){

	int m=0,p=0,q=0,n=0, ax=1;
	do{
		printf("Entre com os valores de m, p, q, n: ");
		scanf("%d %d %d %d", &m, &p, &q, &n);
		
		if((m>10 || m < 0||p > 10 || p < 0 ||q>10 || q < 0||n>10 || n < 0) || p!=q){		
			printf("\nValores inválidos!\n");
			continue;
		}
		ax=0;
	}while(ax);
	
	int a[TAM][TAM], b[TAM][TAM];
	
	printf("Entre com os elementos da matriz: ");
	for(int i=0;i<m;i++){
		for(int j=0; j<p; j++){
			scanf("%d", (*(a+i)+j));
		}
	}
	printf("\n");
	printf("Entre com os elementos da matriz: ");
	for(int i=0;i<p;i++){
		for(int j=0; j<n; j++){
			scanf("%d", (*(b+i)+j));
		}
	}
	
	printf("\n");
	int c[TAM][TAM];
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			c[i][j] = 0;
			for(int k=0; k<p; k++){
				c[i][j] += a[i][k]*b[k][j];
			}	
		}
	}	
	
	printf("\n");
	
	imprime(c, m,n,p);
	
	return 0;
}


void imprime(int (*c)[TAM], int m, int n, int p){
	for(int i =0; i<m; i++){
		for(int j =0; j<n; j++){
			printf("%d ", *(*(c+i)+j));
		}
		printf("\n");
	}
}


