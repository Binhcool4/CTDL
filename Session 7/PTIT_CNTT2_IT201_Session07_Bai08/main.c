#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    if (rows <= 0 || cols <= 0) {
        printf("Du lieu khong hop le");
        return 0;
    }
    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");

    int k;
    printf("Nhap cot muon xep: ");
    scanf("%d", &k);
    if (k <= 0 || k > cols) {
        printf("Du lieu khong hop le");
        return 0;
    }
    k = k - 1;
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (arr[i][k] > arr[j][k]) {
                int t = arr[i][k];
                arr[i][k] = arr[j][k];
                arr[j][k] = t;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}