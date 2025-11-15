#include <stdio.h>

int main() {
    int n, i;

    // Ask for the array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];  // Declare array with user-defined size

    // Ask for array elements
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display negative elements
    printf("Negative numbers in the array:\n");
    for(i = 0; i < n; i++) {
        if(arr[i] < 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}
