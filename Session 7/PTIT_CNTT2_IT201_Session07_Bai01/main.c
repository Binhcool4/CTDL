#include <stdio.h>

int main() {
    int arr[1000];
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Before:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("After:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}