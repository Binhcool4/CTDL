#include <stdio.h>

int merge(int arr[], int left, int mid, int right) {
    int num1 = mid - left + 1;
    int num2 = right - mid;
    int L[num1], R[num2];
    for (int i = 0; i < num1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < num2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0;
    int k = left;
    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < num1) {
        arr[k++] = L[i++];
    }
    while (j < num2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}