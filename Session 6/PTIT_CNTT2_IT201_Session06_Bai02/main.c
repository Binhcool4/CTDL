#include <stdio.h>

int fibonaci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonaci(n - 1) + fibonaci(n - 2);
}

int main() {
    int n;
    printf("Nhap n o dau tien trong fibonaci: ");
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", fibonaci(i));
    }
    return 0;
}