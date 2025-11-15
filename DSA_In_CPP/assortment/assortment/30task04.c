#include <stdio.h>

int main() {
    int i, j, rows, cols;

    // Input dimensions
    printf("Enter the array's row size: ");
    scanf("%d", &rows);
    printf("Enter the array's column size: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Invalid array dimensions.\n");
        return 1;
    }

    int arr[rows][cols];

    // Input array elements
    printf("Enter array's elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Display full array
    printf("\n--- Your 2D Array ---\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    int targetRow, targetCol;

    // Input and validate row number
    printf("\nEnter row number (0 to %d): ", rows - 1);
    scanf("%d", &targetRow);
    if (targetRow < 0 || targetRow >= rows) {
        printf("Invalid row number.\n");
        return 1;
    }

    // Compute row sum
    int rowSum = 0;
    printf("Elements of row %d: ", targetRow);
    for (j = 0; j < cols; j++) {
        printf("%d", arr[targetRow][j]);
        rowSum += arr[targetRow][j];
        if (j < cols - 1){
        	 printf(", ");
		}
    }
    printf("\nThe sum of row %d: %d\n", targetRow, rowSum);

    // Input and validate column number
    printf("\nEnter column number (0 to %d): ", cols - 1);
    scanf("%d", &targetCol);
    if (targetCol < 0 || targetCol >= cols) {
        printf("Invalid column number.\n");
        return 1;
    }

    // Compute column sum
    int colSum = 0;
    printf("Elements of column %d: ", targetCol);
    for (i = 0; i < rows; i++) {
        printf("%d", arr[i][targetCol]);
        colSum += arr[i][targetCol];
  		if (i < rows - 1) {
  			printf(", ");
		  }
    }
    printf("\nThe sum of column %d: %d\n", targetCol, colSum);

    return 0;
}
