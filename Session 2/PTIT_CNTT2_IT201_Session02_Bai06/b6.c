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
    printf("Moi ban nhap vi tri muon them: ");
    scanf("%d", &index);
    if(index > n) {
        printf("Vi tri khong hop le");
        return 0;
    }
    int value;
    printf("Nhap gia tri muon them vao: ");
    scanf("%d", &value);
    for(int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}