/*
 * DAA LAB-5 - Question 2
 * Find the K-th smallest element without sorting the list.
 * Method: Quickselect
 * Average Time: O(N), Worst Time: O(N^2)
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    while (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (k < pivotIndex)
            high = pivotIndex - 1;
        else
            low = pivotIndex + 1;
    }
    return -1;
}

int main(void) {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("N must be positive.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter K (1 to %d): ", n);
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid K.\n");
        free(arr);
        return 1;
    }

    int result = quickSelect(arr, 0, n - 1, k - 1);
    printf("%d-th smallest element = %d\n", k, result);

    free(arr);
    return 0;
}
