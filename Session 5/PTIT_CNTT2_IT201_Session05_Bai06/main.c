#include <stdio.h>

int sum(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + sum(arr, n - 1);
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = sum(arr, n);
    printf("%d", result);
    return 0;
}