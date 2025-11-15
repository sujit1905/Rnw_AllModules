#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 5; i++) {

        for (j = 1; j <= i; j++) {
            printf("%d", j);  // left side
        }

        for (j = 1; j <= (5 - i) * 2; j++) {
            printf(" ");  // middle gap
        }

        for (j = 1; j <= i; j++) {
            printf("%d", i - j + 1);  // right side
        }

        printf("\n");
    }

    return 0;
}
