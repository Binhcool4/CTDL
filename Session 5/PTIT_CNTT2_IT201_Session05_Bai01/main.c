#include <stdio.h>

void countNum(int n) {
    if (n == 0) {
        return;
    }
    countNum(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Phai la so nguyen duong\n");
    }else {
        printf("Cac so tu 1 den %d la: ", n);
        countNum(n);
        printf("\n");
    }
    return 0;
}