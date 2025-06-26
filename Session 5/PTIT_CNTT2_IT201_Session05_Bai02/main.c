#include <stdio.h>

int sumNum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumNum(n - 1);
    }

}

int main() {
    int n;
    int result;
    printf("Nhap so bat ki: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le");
    } else {
        result = sumNum(n);
        printf("Tong cac so tu 1 den %d la: %d", n, result);
    }
    return 0;
}