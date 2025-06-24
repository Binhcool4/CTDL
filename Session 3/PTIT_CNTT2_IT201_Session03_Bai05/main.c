#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    do {
        printf("Nhap so hang");
        scanf("%d", &rows);
        printf("Nhap so cot");
        scanf("%d", &cols);
        if (rows <= 0 || cols <= 0) {
            printf("So hang va cot khong hop le \n");
        }
    }while (rows <= 0 || cols <= 0);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap [%d][%d]", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sumMain = 0;
    int sumSub = 0;
    for (int i = 0; i < rows; i++) {
        sumMain += matrix[i][i];
        if (rows == cols) {
            sumSub += matrix[i][cols - 1];
        }
    }
    printf("Tong duong cheo chinh la: %d", sumMain);
    if (rows == cols) {
        printf("Tong duong cheo phu: %d \n", sumSub);
    }else {
        printf("Khong ton tai duong cheo phu");
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}