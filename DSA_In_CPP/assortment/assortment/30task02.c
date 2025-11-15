#include <stdio.h>

int main()
{
    int rows, cols;
    int i,j;

    // Get the number of rows and columns from the user
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Declare the array with maximum size (or dynamically if desired)
    int arr[rows][cols];

    // Input values into the array
    printf("Enter the elements:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Initialize max value
    int maxVal = arr[0][0];

    // Find the largest element
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (arr[i][j] > maxVal)
            {
                maxVal = arr[i][j];
            }
        }
    }

    // Output the largest value
    printf("\nThe largest number is = %d\n", maxVal);

    return 0;
}
