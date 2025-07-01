#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int number) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (number == arr[mid]) {
            return mid;
        }else if (arr[mid] < number) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("Mang duoc sap xep la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int number;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &number);
    int result = linearSearch(arr, n, number);
    if (result == -1) {
        printf("Gia tri khong tim thay");
    } else {
        printf("Gia tri duoc tim thay o vi tri %d", result);
    }
    return 0;
}