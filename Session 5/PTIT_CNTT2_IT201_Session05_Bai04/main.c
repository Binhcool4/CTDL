#include <stdio.h>

int sumNumber(int fistNum, int secondNum) {
    if (fistNum > secondNum) {
        return 0;
    }
    return fistNum + sumNumber(fistNum + 1, secondNum);
}

int main() {
    int firstNum, secondNum;
    printf("Nhap so nguyen duong thu nhat: ");
    scanf("%d", &firstNum);
    printf("Nhap so nguyen duong thu hai: ");
    scanf("%d", &secondNum);

    if (firstNum <=0 || secondNum <= 0) {
        printf("Ca hai phai la so nguyen duong");
    } else if (firstNum > secondNum) {
        printf("So thu nhat phai nho hon so thu hai");
    } else {
        int total = sumNumber(firstNum, secondNum);
        printf("Tong cac so tu %d den %d la: %d", firstNum, secondNum, total);
    }
    return 0;
}