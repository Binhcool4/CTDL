#include <stdio.h>

int count(int n, int i) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return count(n, i + 1) + count(n, i + 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", count(n, 0));
    return 0;
}