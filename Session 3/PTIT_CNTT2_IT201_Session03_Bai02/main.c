#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100) {
        printf("So luong khong hop le");
        return 0;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Khong the cap phat");
        return 0;
    }
    printf("Nhap phan tu: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu max la: %d", max);
    free(arr);
    return 0;
}