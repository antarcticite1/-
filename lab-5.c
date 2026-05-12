#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    int n, i, j;
    char op;
    double *matrixA, *matrixB, *result;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    matrixA = (double*)malloc(n * n * sizeof(double));
    matrixB = (double*)malloc(n * n * sizeof(double));

    printf("Enter the elements of the first matrix:\n", n * n);
    for (i = 0; i < n * n; i++) {
        scanf("%lf", &matrixA[i]);
    }

    printf("Enter the elements of the second matrix:\n", n * n);
    for (i = 0; i < n * n; i++) {
        scanf("%lf", &matrixB[i]);
    }

    printf("Enter the operation (+, -, *): ");
    scanf(" %c", &op); 

    result = calculate_matrix(matrixA, matrixB, n, op);

    printf("Result:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f ", result[i * n + j]);
        }
        printf("\n");
    }

    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}
