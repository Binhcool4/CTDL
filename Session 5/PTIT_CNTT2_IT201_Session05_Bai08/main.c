#include <stdio.h>

int convert(char str[], int i, int res) {
    if (str[i] == '\0') {
        return res;
    }
    if (str[i] < '0' || str[i] > '9') {
        return -1;
    }
    return convert(str, i + 1, res * 10 + str[i] - '0');
}

int main() {
    char str[100];
    scanf("%s", str);
    int minus = (str[0] == '-');
    int start = minus ? 1 : 0;
    if (minus) {
        start = 1;
    } else {
        start = 0;
    }
    int res = convert(str, start, 0);
    if (res == -1) {
        printf("Khong hop le");
    } else {
        if (minus) {
            res = -res;
        }
        printf("%d\n", res);
    }
    return 0;
}