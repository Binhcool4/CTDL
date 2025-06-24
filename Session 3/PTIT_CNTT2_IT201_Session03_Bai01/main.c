#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100) {
        printf("Phan tu khong hop le\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Khong the cap phat bo nho\n");
    }

    printf("Nhap so %d phan tu n: \n",n);
    for(int i = 0; i < n; i++) {
        printf("arr[%d] =  ", i);
        scanf("%d", &arr[i]);
    }

    printf("Cac phan tu trong mang la:\n");
    for(int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
