#include <stdio.h>

int main() {
    int i, j, k;

    for (i = 0; i < 5; i++) {
        for (k = 0; k < i; k++) {
            printf(" ");  // shift right
        }

        for (j = 1; j <= 5 - i; j++) {
            if (j % 2 == 1)
                printf("1");
            else
                printf("0");
        }

        printf("\n");
    }

    return 0;
}
