// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "TAD_SDQM_S.c"

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
    int      x, y;                // Variaveis para a entrada do tamanho da matriz
    double **mat1, **mat2;        // Matrizes dinamicamnete alocadas a serem calculdas
    double **mat1q, **mat2q;      // Matriz com os valores dos quadrados
    double** matD;                // Matriz da diferença
    double   R;                   // Resultado da soma da direnfeça
    int      rando;               // Variavel auxiliar para os numeros randomicos
    clock_t  Temp;                // Variavle para ver o tempo de execucao

    // Entrada de dados
    printf("Digite o tamanho das matrizes (x y): ");
    scanf("%d %d", &x, &y);

    //Inicia o contador
    Temp = clock();

    // Aloca a matriz e suas partes
    mat1 = matPart(mat1, x, y);
    mat2 = matPart(mat2, x, y);
    matD = matPart(matD, x, y);

    // Pepara a seed para os numeros serem gerados
    srand((unsigned)time(NULL));

    // Preenche a matriz 1 com valores aleatorios
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            rando = rand() % 10;
            mat1[i][j] = (((double)rand()) / ((double)RAND_MAX)) * rando;
        }
    }

    // Preenche a matriz 2 com valores aleatorios
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            rando = rand() % 10;
            mat2[i][j] = (((double)rand()) / ((double)RAND_MAX)) * rando;
        }
    }

    // Calculo do quadrado das matrizes
    mat1q = calcQuad(mat1, x, y);
    mat2q = calcQuad(mat2, x, y);

    // Calculo da diferença das matrizes
    matD = difCalc(mat1q, mat2q, matD, x, y);

    // Calculo da soma da diferenca
    R = somDiff(matD, x, y);
    
    // Pega o tempo de execucao
    Temp = Temp - clock();                             // Pega a quantidade de tiks
    double Time_tk = ((double)Temp)/CLOCKS_PER_SEC;    // Transforma a quantidade de ticks
    if(Time_tk < 0)                                    // Corige o tempo
        Time_tk *= -1;

    if(argc > 1){
        if(strcmp(argv[1], "-u") == 0){
            printUser(mat1, mat2, mat1q, mat2q, matD, x, y, R);
            printf("Tempo Levado = %lss\n", Time_tk);

        }else if(strcmp(argv[1], "-t") == 0){
            printf("Tempo Levado = %lfs\n", Time_tk);
        }
    }
    
    return 0;

}
