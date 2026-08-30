/*
 * DAA LAB-5 - Question 4
 * Generate N random elements, store them in a file, read them,
 * sort them using Heap Sort, and store the sorted list in another file.
 * Time Complexity: O(N log N) in best, average, and worst cases.
 * Extra Space: O(1) apart from the input array.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    /* Build max heap. */
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Move maximum to the end one by one. */
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(void) {
    int n;
    const char *inputFile = "heap_input.txt";
    const char *outputFile = "heap_sorted.txt";

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

    heapSort(arr, n);

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
    printf("Heap Sort completed. Sorted elements stored in %s.\n", outputFile);

    free(arr);
    return 0;
}
