/* Olá Mundo não tão simples
	exemplo 03b.c 
      redução
   compilação:
      gcc -fopenmp 03b.c -o 03b.x 
*/
#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <time.h>

#define MAX 10

int main(){
    int x, y;
    int **vet1;
    int **vet2;
    int **vet3;
    int i, j;

    scanf("%d %d", &x, &y);
    //printf("%d %d", x, y);

    vet1 = (int**)malloc(sizeof(int*)*x);
    vet2 = (int**)malloc(sizeof(int*)*x);
    vet3 = (int**)malloc(sizeof(int*)*x);

    //#pragma omp for
    for(i=0; i<x; i++){
        vet1[i] = (int*)malloc(sizeof(int)*y);
        vet2[i] = (int*)malloc(sizeof(int)*y);
        vet3[i] = (int*)malloc(sizeof(int)*y);
    }

    #pragma omp parallel shared(x,y, vet1, vet3, vet2, i) private(j)
    {
        #pragma omp for
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                vet1[i][j] = 1;
                vet2[i][j] = 2;
            }
        }

        #pragma omp for
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                vet3[i][j] = vet1[i][j] + vet2[i][j];
            }
        }
    }

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            printf("%d ", vet1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            printf("%d ", vet2[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            printf("%d ", vet3[i][j]);
        }
        printf("\n");
    }   


    
}
