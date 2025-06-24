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
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int avg;
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            sum += arr[i];
            count++;
        }
    }
    avg = sum / count;
    printf("Trung binh cong cua so chan la: %d", avg);
    free(arr);
    return 0;
}