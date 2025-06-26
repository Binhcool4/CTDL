#include <stdio.h>

void getFibonanci(int fibonaci[], int i, int n, int prev, int curr) {
    if (i >= n) {
        return;
    }
    if (i == 0) {
        fibonaci[i] = 0;
        getFibonanci(fibonaci, i + 1, n, 0, 1);
    } else if (i == 1) {
        fibonaci[i] = 1;
        getFibonanci(fibonaci, i + 1, n, 1, 0);
    } else {
        fibonaci[i] = prev + curr;
        getFibonanci(fibonaci, i + 1, n, curr, fibonaci[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int fibonaci[n];
    getFibonanci(fibonaci, 0, n, 0, 1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", fibonaci[i]);
    }
    return 0;
}