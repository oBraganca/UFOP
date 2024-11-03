    /*
    Thayllon Ryan Bragança de Almeida
    24.1.9902
    Questão 01
    */
    #include <stdio.h>
    #include <stdlib.h>

    int main(){

        printf("Digite o valor de n: ");
        int n=0;
        scanf("%d", &n);

        int *v;

        int qtp=0, qti=0;

        v = malloc (n * sizeof (int));

        printf("\nDigite os valores do vetor: ");
        for(int i =0; i<n; i++){
            scanf("%d", v+i);
            if(*(v+i)%2 == 0){
                qtp++;
            }else{
                qti++;
            }
        }
        printf("\n");


        int *p = malloc(qtp*sizeof(int));
        int *im = malloc(qti*sizeof(int));

        int c=0;
        int j=0;
        int z=0;
        while(c < n){
            if(*(v+c)%2 == 0){
                *(p+j) = *(v+c);
                j++;
            }else{
                *(im+z) = *(v+c);
                z++;
            }
            c++;
        }

        if(qtp==0){
            printf("Vetor com os valores pares: Vazio\n");
        }else{
            printf("Vetor com os valores pares: [ ");

            for(int i =0; i<qtp-1; i++){
                printf("%d ", *(p+i));
            }
            printf("%d ]\n", *(p+qtp-1));
        }


        if(qti == 0){
            printf("Vetor com os valores ímpares: Vazio\n");
        }else{

            printf("Vetor com os valores ímpares: [ ");
            for(int i =0; i<qti-1; i++){
                printf("%d ", *(im+i));
            }
            printf("%d ]\n", *(im+qti-1));
        }

        free(v);
        free(p);
        free(im);

        return 0;
    }
