#include <stdio.h>

int main() {
    int arr[100];
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100) {
        printf("Phan tu khong hop le");
        return 0;
    }
    printf("Nhap so %d so nguyen:\n",n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int index;
    int value;
    printf("Nhap vi tri can doi:");
    scanf("%d", &index);
    if(index > n ) {
        printf("Vi tri khong hop le");
        return 0;
    }
    printf("Nhap gia tri can doi:");
    scanf("%d", &value);
    arr[index] = value;
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}