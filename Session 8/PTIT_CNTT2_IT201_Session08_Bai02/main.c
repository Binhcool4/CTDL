#include <stdio.h>

int main() {
    int arr[1000];
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int number;
    printf("Nhap so muon tim: ");
    scanf("%d", &number);
    int left = 0;
    int right = n -1;
    int found = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == number) {
            found = mid;
            break;
        }
        if (arr[mid] < number) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (found != -1) {
        printf("Phan tu vi tri thu %d", found + 1);
    } else {
        printf("Khong ton tai phan tu");
    }
    return 0;
}