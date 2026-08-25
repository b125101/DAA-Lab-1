#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];

    int pos = partition(arr, low, high);

    if (k == pos)
        return arr[pos];

    if (k < pos)
        return quickSelect(arr, low, pos - 1, k);

    return quickSelect(arr, pos + 1, high, k);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (n % 2 != 0)
    {
        // Odd number of elements
        int median = quickSelect(arr, 0, n - 1, n / 2);

        printf("Median = %d\n", median);
    }
    else
    {
        // Even number of elements
        int left = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int right = quickSelect(arr, 0, n - 1, n / 2);

        float median = (left + right) / 2.0;

        printf("Median = %.2f\n", median);
    }

    return 0;
}
