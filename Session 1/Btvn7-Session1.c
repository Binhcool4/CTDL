#include <stdio.h>
//Do phuc tap thoi gian O(n^2)
// int main() {
//     int arr[] = {10, 20, 30, 44, 5, 5, 6, 78, 55, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int found = 0;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n + i - 1; j++) {
//             if (arr[i] == arr[j]) {
//                 found = 1;
//                 break;
//             }
//         }
//         if (found == 1) {
//             break;
//         }
//     }
//     if (found == 1) {
//         printf("Mang co phan tu trung lap");
//     } else {
//         printf("Mang khong co phan tu trung lap");
//     }
//     return 0;
// }

//Do phuc tap thoi gian O(n^2)
//Do phuc tap khong gian O(n)
int main() {
    int arr[] = {1, 2, 3, 4, 5, 2, 7, 0, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int unique[100];
    int count = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = 1;
                found = 1;
                break;
            }
        }
        if (isDuplicate == 0) {
            unique[count] = arr[i];
            count++;
        }else {
            break;
        }
    }
    if (found == 1) {
        printf("Mang co phan tu trung lap");
    }else {
        printf("Mang khong co phan tu trung lap");
    }
}