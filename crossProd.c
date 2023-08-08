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

    return 0;
}