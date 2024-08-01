#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(float arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
        printf("Buoc %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%.2f ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Không thể mở file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%f", &arr[i]);
    }
    fclose(file);

    // Tìm số bé nhất và vị trí của chúng
    float min = arr[0];
    int min_pos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_pos = i;
        }
    }
    printf("So be nhat: %.2f, Vi tri: %d\n", min, min_pos);

    // Đưa ra các số xuất hiện k lần (k = 2)
    printf("Cac so xuat hien 2 lan: ");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 2) {
            printf("%.2f ", arr[i]);
        }
    }
    printf("\n");

    // Sắp xếp dãy số theo thuật toán sắp xếp chọn
    selectionSort(arr, n);

    return 0;
}
