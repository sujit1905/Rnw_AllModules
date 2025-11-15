#include <stdio.h>

int main() {
    int rows, cols, i, j;

    // Input matrix size
    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    int original[rows][cols];

    // Input matrix elements
    printf("\nEnter elements of the original matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &original[i][j]);
        }
    }

    int transpose[cols][rows];

    // Transpose logic
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = original[i][j];
        }
    }

    // Print transposed matrix
    printf("\nTranspose Matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    // Input matrix size
    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    int original[rows][cols];
    

    // Input matrix elements
    printf("\nEnter elements of the original matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &original[i][j]);
        }
    }

    int transpose[cols][rows];

    // Transpose logic
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = original[i][j];
        }
    }

    // Print transposed matrix
    printf("\nTranspose Matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
