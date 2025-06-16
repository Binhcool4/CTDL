#include <stdio.h>
//Do phuc tap khong gian O(1)
//Do phuc tap thoi gian O(n)
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1,2,1,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int countNum = 3;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == countNum) {
            count++;
        }
    }
    printf("So lan xuan hien cua %d la %d\n",countNum, count);
}