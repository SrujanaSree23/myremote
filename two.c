#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, i;

    // Prompt user for the number of elements
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0 || n > 100) {
        printf("Please enter a valid number of integers (1-100).\n");
        return 1;
    }

    // Input the integers
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}