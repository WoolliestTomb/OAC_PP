// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "TAD_SDQM_P.c"
#include <omp.h>

// Funcao de print para o usário
void printUser(double** mat1, double** mat2, double** qmat1, double** qmat2, double** matd, int x, int y, double res){
    // Print da matriz original
    printf("===========================================================================\n");
    printf("----------------------------Matrizes de Entrada----------------------------\n");
    printf("===========================================================================\n\n");
    printMat(mat1, mat2, x, y);
    printf("\n");

    // Print do quadrado da matriz
    printf("===========================================================================\n");
    printf("--------------------Matrizes Depois de Serem Calculadas--------------------\n");
    printf("===========================================================================\n\n");
    printMat(qmat1, qmat2, x, y);
    printf("\n");

    // Print da matriz da diferença
    printf("===========================================================================\n");
    printf("----------------------------Matriz da Diferenca----------------------------\n");
    printf("===========================================================================\n\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(j==0)
                printf("|%lf ", matd[i][j]);
            else if(j != y-1)
                printf("%f ", matd[i][j]);
            else
                printf("%lf|", matd[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Printa o resulstado
    printf("===========================================================================\n");
    printf("------------------------------Resultado Final------------------------------\n");
    printf("===========================================================================\n\n");
    printf("R = %lf\n", res);


}

// Funcao Principal
int main(int argc, char *argv[]){
    // Variaveis
    int      x=atoi(argv[1]), y=atoi(argv[2]);                // Variaveis para a entrada do tamanho da matriz
    double **mat1, **mat2;                                    // Matrizes dinamicamnete alocadas a serem calculdas
    double **mat1q, **mat2q;                                  // Matriz com os valores dos quadrados
    double** matD;                                            // Matriz da diferença
    double   R;                                               // Resultado da soma da direnfeça
    int      rando;                                           // Variavel auxiliar para os numeros randomicos
    double  Temp;                                             // Variavle para ver o tempo de execucao
    int     Thred=atoi(argv[3]);                              // N° de threads a serem usadas

    //Inicia o contador
    Temp = omp_get_wtime();

    // Aloca a matriz e suas partes
    mat1 = matPart(mat1, x, y);
    mat2 = matPart(mat2, x, y);
    matD = matPart(matD, x, y);

    // Pepara a seed para os numeros serem gerados
    srand((unsigned)time(NULL));

    // PP
    // Preenche as matrizes com valores aleatorios
    unsigned int seed = time(NULL);
    #pragma omp paralel shared(mat1, mat2, x, y, i) private(j) firstprivate(seed)
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            // Preenche a matriz 1
            // rando = rand_r() % 10;
            mat1[i][j] = ((double)(rand_r(&seed))) / (((double)RAND_MAX)) * (rand_r(&seed) % 10);

            // Preenche a matriz 2
            //rando = rand_r() % 10;
            mat2[i][j] = ((double)(rand_r(&seed))) / (((double)RAND_MAX)) * (rand_r(&seed) % 10);
        }
    }

    // Calculo do quadrado das matrizes
    mat1q = calcQuad(mat1, x, y, Thred);
    mat2q = calcQuad(mat2, x, y, Thred);

    // Calculo da diferença das matrizes
    matD = difCalc(mat1q, mat2q, matD, x, y, Thred);

    // Calculo da soma da diferenca
    R = somDiff(matD, x, y, Thred);

    // Pega o tempo de execucao
    double Time_tk = omp_get_wtime() - Temp;

    printf("%lf\n", Time_tk);
    
    return 0;

}
