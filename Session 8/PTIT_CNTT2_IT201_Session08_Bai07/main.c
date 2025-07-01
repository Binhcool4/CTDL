#include <stdio.h>

int quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high; j++) {
            if (arr[j] < pivot) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i++;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int next = i + 1;
        quicksort(arr, low, next - 1);
        quicksort(arr, next + 1, high);
    }
}

int main() {
    int arr[1000];
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf('So luong khong hop le"');
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}