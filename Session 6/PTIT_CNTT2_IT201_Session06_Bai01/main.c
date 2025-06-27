#include <stdio.h>

int binary(int number) {
    if (number == 0) {
        return 0;
    }
    binary(number / 2);
    printf("%d", number % 2);
}

int main(void) {
    int number;
    scanf("%d", &number);
    binary(number);
    return 0;
}