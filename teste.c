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

    scanf("%d %d", &x, &y);

    #pragma omp prallel shred(vet1, vet2, vet3)
    {
        vet1 = (int**)malloc(sizeof(int)*x);
        vet2 = (int**)malloc(sizeof(int)*x);
        vet3 = (int**)malloc(sizeof(int)*x);

        #pragma omp for
        for(int i=0; i<x; i++){
            vet1[i] = (int*)malloc(sizeof(int)*y);
            vet2[i] = (int*)malloc(sizeof(int)*y);
            vet3[i] = (int*)malloc(sizeof(int)*y);
        }

        #pragma omp for
        for int 

    }
        


    
}
