#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }else if (arr[mid] < x) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <=0 || n > 100) {
        printf("So luong khong hop le");
        return 0;
    }
    printf("Nhap %d phan tu: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Sap xep
    printf("Phan tu truoc khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Phan tu sau khi sap xep:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Tim kiem nhi phan
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    int result = binarySearch(arr, n, x);
    if (result != -1) {
        printf("Phan tu co trong mang");
    }else {
        printf("Phan tu khong co trong mang");
    }
    return 0;
}