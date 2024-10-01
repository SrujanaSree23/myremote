#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100]; // Declare a string with a maximum length of 99 characters
    int length, i;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if it's present
    str[strcspn(str, "\n")] = '\0';

    // Calculate the length of the string
    length = strlen(str);

    // Reverse the string
    printf("Reversed string: ");
    for (i = length - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    
    printf("\n");
    return 0;
}