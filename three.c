#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define NAME_LENGTH 50

// Function to perform binary search
int binarySearch(char names[][NAME_LENGTH], int size, const char *target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int result = strcmp(names[mid], target);
        
        // Check if target is present at mid
        if (result == 0) {
            return mid; // Found
        }
        // If target is greater, ignore the left half
        else if (result < 0) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Not found
}

int main() {
    char names[MAX_NAMES][NAME_LENGTH];
    int n;

    // Prompt user for the number of names
    printf("Enter the number of names (max %d): ", MAX_NAMES);
    scanf("%d", &n);
    getchar(); // Consume newline after number input

    // Input names
    printf("Enter %d names (each name up to %d characters):\n", n, NAME_LENGTH - 1);
    for (int i = 0; i < n; i++) {
        fgets(names[i], NAME_LENGTH, stdin);
        // Remove the newline character
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Sort the names (simple bubble sort for demonstration)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char temp[NAME_LENGTH];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    // Prompt user for the name to search
    char target[NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(target, NAME_LENGTH, stdin);
    target[strcspn(target, "\n")] = '\0'; // Remove newline

    // Perform binary search
    int result = binarySearch(names, n, target);

    // Output the result
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found in the list.\n", target);
    }

    return 0;
}
