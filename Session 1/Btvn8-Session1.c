#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5, 2, 7, 8, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxCount = 0;
    int maxItem = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxItem = arr[i];
        }
    }
    printf("Max item is %d\n", maxItem);
}