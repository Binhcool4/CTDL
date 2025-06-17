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
    int find;
    int count = 0;
    printf("Moi ban nhap so can tim: ");
    scanf("%d", &find);
    for(int i = 0; i < n; i++) {
        if(arr[i] == find) {
            count++;
        }
    }
    printf("So %d can tim co so lan lap la %d\n", find, count);
}