// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "TAD.h"
#include <omp.h>


// Funcao de alocassao da matriz
double** matPart(double** Mat, int rol, int col){
    // Aloca primeiramente a matriz na memória
    Mat = (double**)malloc(sizeof(double*)*rol);

    // Aloca as partes restantes da matriz
    for(int i = 0; i < rol; i++){
        Mat[i] = (double*)malloc(sizeof(double)*col);
    }

    return Mat;
}

// Funcao de printar a matriz
void printMat(double** Mat1, double** Mat2, int x, int y){
    for(int i = 0; i < x; i++){
        // Printa as linhas da matriz 1
        for(int j = 0; j < y; j++){
            if(j == 0)
                printf("|%lf ", Mat1[i][j]);
            else if(j != y-1)
                printf("%lf ", Mat1[i][j]);
            else
                printf("%lf|\t\t", Mat1[i][j]);

        }

        // Printa as linhas da matriz 2
        for(int j = 0; j < y; j++){
            if(j == 0)
                printf("|%lf ", Mat2[i][j]);
            else if(j != y-1)
                printf("%lf ", Mat2[i][j]);
            else
                printf("%lf|", Mat2[i][j]);

        }

        printf("\n");
    } 
}

//PP
// Funcao para calcular o quadrado da matriz
double** calcQuad(double** Mat, int x, int y, int t){
    // Variaveis auxiliares
    double aux;
    int i, j;

    // Realiza o calculo do quadrado da matriz
    omp_set_num_threads(t);
    #pragma omp parallel shared(Mat, i, x, y) private(j)
    {
        #pragma omp for
        for(i = 0; i < x; i++){
            for(j = 0; j < y; j++){
                //aux = Mat[i][j];
                //aux = pow(aux, 2);
                Mat[i][j] = Mat[i][j]*Mat[i][j];
            }
        }
    }

    return Mat;
}

//PP
// Funcao para calcular a difernca das matrizes
double** difCalc(double** Mat1, double** Mat2, double** MatR, int x, int y, int t){
    // Variaveis auxiliares
    double m1, m2;         
    int i, j;
    
    omp_set_num_threads(t);
    #pragma omp parallel shared(MatR, Mat1, Mat2, i, x, y) private(j)
    // Calculo da diferenca
    {
        #pragma omp for
        for(i = 0; i < x; i++){
            for(j = 0; j < y; j++){
                //m1 = Mat1[i][j];
                //m2 = Mat2[i][j];
                MatR[i][j] = Mat1[i][j] - Mat2[i][j];
            }
        }
    }

    return MatR;
}

//PP
// Funcao para realizar a soma da diferenca das matriz
double somDiff(double** Mat, int x, int y, int t){
    // Variaveis
    double soma=0;               // Variavel de retorno
    double aux;                  // Variavel auxiliar
    int i, j;

    omp_set_num_threads(t);
    #pragma omp parallel shared(Mat, i, x, y) private(j) reduction(+:soma)
    {
        #pragma omp for
        // Calculo da funcao
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                //aux = Mat[i][j];
                soma += Mat[i][j];
            }
        }
    }
    return soma;
}


