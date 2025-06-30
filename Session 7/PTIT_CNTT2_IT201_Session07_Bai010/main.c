#include <stdio.h>

int absDiff(int a, int b) {
    return a > b ? a - b : b - a;
}

void bubbleSort(int arr[], int n, int x) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int d1 = absDiff(arr[j], x);
            int d2 = absDiff(arr[j + 1], x);
            if (d1 > d2 || (d1 == d2 && arr[j] > arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, x;
    int arr[1000];
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    bubbleSort(arr, n, x);
    printf("Mang sau khi sap xep theo khoang cach toi %d:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}