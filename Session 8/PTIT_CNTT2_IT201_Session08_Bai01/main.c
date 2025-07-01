#include <stdio.h>

int main() {
    int arr[1000];
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    int number;
    int found = 0;
    printf("Nhap so muon tim: ");
    scanf("%d", &number);
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            found = 1;
            printf("Vi tri thu %d", i + 1);
        }
    }
    if (!found) {
        printf("So %d khong tim thay", number);
    }
    return 0;
}