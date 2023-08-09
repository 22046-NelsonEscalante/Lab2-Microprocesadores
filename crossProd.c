/*
--------------------------------------------
crossProd.c
--------------------------------------------
Universidad del Valle de Guatemala
CC3086 - Programacion de Microprocesadores
Laboratorio 2

Nelson Escalante - 22046
Nicolle Gordillo - 22246
--------------------------------------------
Calcular el producto matricial entre dos vectores 
de 3*3, con el número de threads a utilizar 
establecido por el usuario.
--------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void fillMatrixRandom(int mat[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = rand() % 11;  
        }
    }
}

void matrixMultiplication(int mat1[][3], int mat2[][3], int result[][3]) {
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }
}

int main() {
    srand(time(0)); 

    int A[3][3];
    int B[3][3];
    int X;

    printf("\nIngrese el numero de threads con los que desea trabajar.\n");
    scanf("%d", &X);
    omp_set_num_threads(X);

    fillMatrixRandom(A);
    fillMatrixRandom(B);

    int resultMatrix[3][3];
    matrixMultiplication(A, B, resultMatrix);

    printf("Matriz 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nResultado:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}