/*
 * DAA LAB-5 - Question 1
 * Find the median of N numbers without sorting the list.
 * Method: Quickselect (selection algorithm)
 * Average Time: O(N), Worst Time: O(N^2)
 * Extra Space: O(log N) average due to recursion.
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

/* Returns the k-th smallest element, where k is 0-based. */
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
    return -1;  // k is invalid
}

int main(void) {
    int n;
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

    double median;

    if (n % 2 == 1) {
        int middle = quickSelect(arr, 0, n - 1, n / 2);
        median = middle;
    } else {
        int leftMiddle = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int rightMiddle = quickSelect(arr, 0, n - 1, n / 2);
        median = ((double)leftMiddle + rightMiddle) / 2.0;
    }

    printf("Median = %.2f\n", median);

    free(arr);
    return 0;
}
