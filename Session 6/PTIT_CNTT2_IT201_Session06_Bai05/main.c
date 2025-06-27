#include <stdio.h>

int findMax(int arr[], int size, int i) {
    if (i == size - 1) {
        return arr[i];
    }
    int max = findMax(arr, size, i + 1);
    return (arr[i] > max ? arr[i] : max);
}

int findMin(int arr[], int size, int i) {
    if (i == size - 1) {
        return arr[i];
    }
    int min = findMin(arr, size, i + 1);
    return (arr[i] < min ? arr[i] : min);
}

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d trong mang: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max = findMax(arr, n, 0);
    int min = findMin(arr, n, 0);
    printf("max trong mang: %d\n", max);
    printf("min trong mang: %d\n", min);
    return 0;
}