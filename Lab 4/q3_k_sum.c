#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return 1;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

/*
   Recursively choose k-1 elements.
   For the last element, use binary search.
*/
int kSum(int arr[], int n, int k, int target, int start) {

    // Base case: choose one element
    if (k == 1) {
        return binarySearch(arr + start, n - start, target);
    }

    // Try every possible element
    for (int i = start; i <= n - k; i++) {

        if (kSum(arr, n, k - 1,
                 target - arr[i], i + 1)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, k, T;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter target T: ");
    scanf("%d", &T);

    if (k > n || k <= 0) {
        printf("Invalid value of k.\n");
        return 0;
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    if (kSum(arr, n, k, T, 0))
        printf("\nYes, %d elements can make sum %d.\n", k, T);
    else
        printf("\nNo, %d elements can make sum %d.\n", k, T);

    return 0;
}
