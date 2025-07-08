#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int *data;
    int capacity;
}Stack;

Stack createStack(int maxSize) {
    Stack s;
    s.data = (int *)malloc(maxSize * sizeof(int));
    s.top = -1;
    s.capacity = maxSize;
    return s;
}

int main() {
    Stack s = createStack(5);
    printf("Ngan xep co suc chua toi da la: %d", s.capacity);
    free(s.data);
    return 0;
}