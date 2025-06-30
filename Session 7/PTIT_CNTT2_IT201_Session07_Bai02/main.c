#include <stdio.h>

int main() {
    int n;
    int arr[1000];
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if (n <= 0|| n > 1000) {
        printf("So luong khong hop le");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("So phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("\nafter: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}