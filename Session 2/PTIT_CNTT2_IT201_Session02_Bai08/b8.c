#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("So luong ko hop le");
        return 0;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho");
        return 0;
    }

    printf("Nhap phan tu n : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        int isGreater = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isGreater = 0;
                break;
            }
        }
        if (isGreater) {
            printf("%d ", arr[i]);
        }
    }
    printf("%d\n", arr[n - 1]);
    free(arr);
    return 0;
}