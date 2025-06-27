#include <stdio.h>

int sumNumber(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumNumber(n / 10);
}

int main() {
    int n;
    printf("Nhap mot so nguyen duong n bat ki: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Phai la so nguyen duong");
    } else {
        int sum = sumNumber(n);
        printf("%d", sum);
    }
    return 0;
}