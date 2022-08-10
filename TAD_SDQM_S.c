// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "TAD_SDQM.h"

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

// Funcao para calcular o quadrado da matriz
double** calcQuad(double** Mat, int x, int y){
    // Variaveis auxiliares
    double aux;

    // Realiza o calculo do quadrado da matriz
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            aux = Mat[i][j];
            aux = pow(aux, 2);
            Mat[i][j] = aux;
        }
    }

    return Mat;
}

// Funcao para calcular a difernca das matrizes
double** difCalc(double** Mat1, double** Mat2, double** MatR, int x, int y){
    // Variaveis auxiliares
    double m1, m2;                  

    // Calculo da diferenca
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            m1 = Mat1[i][j];
            m2 = Mat2[i][j];
            MatR[i][j] = m1 - m2;
        }
    }

    return MatR;
}

// Funcao para realizar a soma da diferenca das matriz
double somDiff(double** Mat, int x, int y){
    // Variaveis
    double soma=0;               // Variavel de retorno
    double aux;                  // Variavel auxiliar

    // Calculo da funcao
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            aux = Mat[i][j];
            soma += aux;
        }
    }

    return soma;
}


