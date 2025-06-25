#include <stdio.h>

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("So luong khong hop le");
        return 0;
    }
    printf("Nhap %d phan tu: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int search;
    int found = 0;
    printf("Nhap gia tri muon tim: ");
    scanf("%d", &search);
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            found = i;
        } else {
            printf("Khong tim thay phan tu");
            return 0;
        }
    }
    printf("%d", found);
}