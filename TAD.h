// Biblioestecas
#include <stdio.h>
#include <stdlib.h>


//===========================================================================
//----------------------------Funcoes de Alocacao----------------------------
//===========================================================================

double** matPart(double** Mat, int rol, int col);                               // Funcao de alocassao da matriz
void printMat(double** Mat1, double** Mat2, int x, int y);                      // Funcao de printar a matriz

//==========================================================================
//----------------------------Funcoes de Calculo----------------------------
//==========================================================================

double** calcQuad(double** Mat, int x, int y, int t);                                  // Funcao para calcular o quadrado da matriz
double** difCalc(double** Mat1, double** Mat2, double** MatR, int x, int y, int t);    // Funcao para calcular a difernca das matrizes
double somDiff(double** Mat, int x, int y, int t);                                     // Funcao para realizar a soma da diferenca das matriz

//==========================================================================
//-----------------------------Funcoes de Print-----------------------------
//==========================================================================

void printMat(double** Mat1, double** Mat2, int x, int y);                      // Funcao de printar a matriz para o usuario