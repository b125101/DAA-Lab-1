/*
 * DAA LAB-5 - Question 3
 * Generate N random elements, store them in a file, read them,
 * sort them using Quick Sort, and store the sorted list in another file.
 * Average Time: O(N log N), Worst Time: O(N^2)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main(void) {
    int n;
    const char *inputFile = "quick_input.txt";
    const char *outputFile = "quick_sorted.txt";

    printf("Enter number of random elements: ");
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

    srand((unsigned int)time(NULL));

    FILE *fp = fopen(inputFile, "w");
    if (fp == NULL) {
        printf("Cannot create %s.\n", inputFile);
        free(arr);
        return 1;
    }

    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        fprintf(fp, "%d ", arr[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);

    /* Read the generated data back from the file. */
    fp = fopen(inputFile, "r");
    if (fp == NULL) {
        printf("Cannot open %s.\n", inputFile);
        free(arr);
        return 1;
    }

    int fileN;
    fscanf(fp, "%d", &fileN);
    for (int i = 0; i < fileN; i++)
        fscanf(fp, "%d", &arr[i]);
    fclose(fp);

    quickSort(arr, 0, n - 1);

    fp = fopen(outputFile, "w");
    if (fp == NULL) {
        printf("Cannot create %s.\n", outputFile);
        free(arr);
        return 1;
    }

    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", arr[i]);
    fprintf(fp, "\n");
    fclose(fp);

    printf("%d random elements stored in %s.\n", n, inputFile);
    printf("Quick Sort completed. Sorted elements stored in %s.\n", outputFile);

    free(arr);
    return 0;
}
