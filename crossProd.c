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
Calcular el producto cruz entre dos vectores
de tamaño N, establecido por el usuario.
--------------------------------------------
*/

#include <stdio.h>
#include <omp.h>

int main () {
    int N;

    printf("Ingrese el tamaño de los vectores con los que quiere trabajar.\n");
    scanf("%d", N);
    
    double A[N], B[N], C[N], X;

    printf("\nIngrese el numero de threads con los que desea trabajar.\n");
    scanf("%d", X);
    omp_set_num_threads(X);

    int i, j;
	
	for (i=0; i<N; i++) A[i] = i;
	for (i=0; i<N; i++) B[i] = i;


    for (i = 0; i < N; i++) {
        C[i] = A[i];
    }

    #pragma omp parallel
    {
        #pragma omp for reduction(+:sum)
        //Código a ejecutar
    }

    return 0;
}