#include <stdio.h>

// Add
int add(int x, int y) {
    return x + y;
}

// Subtract
int sub(int x, int y) {
    return x - y;
}

// Multiply
int mul(int x, int y) {
    return x * y;
}

// Divide
float divi(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero.\n");
        return 0.0;
    }
    return (float)x / y;
}

// Modulo
int modulo(int x, int y) {
    if (y == 0) {
        printf("Error: Modulo by zero.\n");
        return 0;
    }
    return x % y;
}

int main() {
    int ch, a, b;

    while (1) {
        // Display menu
        printf("\n--- CALCULATOR ---\n");
        printf("[1] Add\n");
        printf("[2] Subtract\n");
        printf("[3] Multiply\n");
        printf("[4] Divide\n");
        printf("[5] Modulus\n");
        printf("[0] Exit\n");
        printf("Choose: ");
        scanf("%d", &ch);

        if (ch == 0) {
            printf("Thanks for using the calculator.\n");
            break;
        }

        if (ch < 1 || ch > 5) {
            printf("Invalid option. Try again.\n");
            continue;
        }

        // Input values
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);

        // Perform operation
        switch (ch) {
            case 1:
                printf("Result: %d\n", add(a, b));
                break;
            case 2:
                printf("Result: %d\n", sub(a, b));
                break;
            case 3:
                printf("Result: %d\n", mul(a, b));
                break;
            case 4:
                printf("Result: %.2f\n", divi(a, b));
                break;
            case 5:
                printf("Result: %d\n", modulo(a, b));
                break;
        }
    }

    return 0;
}

