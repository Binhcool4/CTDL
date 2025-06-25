#include <stdio.h>

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("So luong khong hop le");
        return 0;
    }
    printf("Nhap %d so nguyen: \n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int search;
    int find = 0;
    printf("So ban muon tim: ");
    scanf("%d", &search);
    for(int i = 0; i < n; i++) {
        if(arr[i] == search) {
            printf("%d", i);
            find = 1;
            break;
        }
    }
    if(!find) {
        printf("Khon tim thay phan tu");
    }
}