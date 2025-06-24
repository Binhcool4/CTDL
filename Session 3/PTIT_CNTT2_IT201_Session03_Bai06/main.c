#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so luong phan tu n:");
    scanf("%d", &n);
    if(n <= 0) {
        printf("So luong phsn tu khong hop le");
        return 0;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Cap phat khong thanh cong");
        return 0;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int m;
    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &m);
    arr = (int *)realloc((int*)arr, (n+m) * sizeof(int));
    for(int i = 0; i < n + m; i++) {
        scanf("%d", arr + i);
    }
    for(int i = 0; i < n + m; i++) {
       printf("%d ", *(arr + i));
    }
    free(arr);
    return 0;
}