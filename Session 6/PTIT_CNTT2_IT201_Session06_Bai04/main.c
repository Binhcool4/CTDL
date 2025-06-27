#include <stdio.h>

int tower(int n, char A, char B, char C) {
    if (n == 0) {
        return 0;
    }
    //Buoc 1: Dich chuyen n-1 dia tu cot A sang cot trung gian B
    tower(n-1, A, C, B);
    printf("%d di chuyen tu %c den %c\n", n, A, C);
    //Buoc 2: Dich chuyen n-1 dia tu cot trung gian B sang cot C
    tower(n-1, B, A, C);
}

int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);
    if (n == 1) {
        printf("Dia mot chuyen tu A sang C");
        return 0;
    }
    tower(n, 'A', 'B', 'C');
    return 0;
}