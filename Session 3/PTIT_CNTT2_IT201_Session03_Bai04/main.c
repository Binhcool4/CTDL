#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    const int MAX_INF = 100000;
    const int MIN_INF = -100000;
    do {
        printf("Nhap hang va cot: ");
        scanf("%d %d", &rows, &cols);
    }while (rows < 1 || cols < 1);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap [%d][%d]", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
    int min = MAX_INF;
    int max = MIN_INF;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    printf("Max = %d\n", max);
    printf("Min = %d\n", min);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}