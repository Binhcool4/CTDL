#include <stdio.h>

int main() {
    int arr[100];
    int n;
    int index;
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
    printf("Moi ban nhap vi tri muon xoa: ");
    scanf("%d", &index);
    if (index > n) {
        printf("Vi tri khong hop le");
        return 0;
    }
    for(int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}