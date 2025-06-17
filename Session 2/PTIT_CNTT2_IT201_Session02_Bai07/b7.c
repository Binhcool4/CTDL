#include <stdio.h>

int main() {
    int arr[100];
    int n, sum;
    int found = 0;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if(n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    printf("Nhap so %d so nguyen:\n",n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap tong can tim: ");
    scanf("%d", &sum);

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == sum) {
                printf("%d, %d", arr[i], arr[j]);
                found = 1;
                break;
            }
        }
        if(found) {
            break;
        }
    }
    if (!found) {
        printf("Khon tim thay cap nao co tong bang %d", sum);
    }
    return 0;
}