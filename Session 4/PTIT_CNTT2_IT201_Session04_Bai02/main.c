#include <stdio.h>

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100) {
        printf("So luong khong hop le");
        return 0;
    }

    printf("Nhap %d phan tu: \n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxIndex = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    printf("%d\n", maxIndex);
}