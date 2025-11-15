#include <stdio.h>

int main() {
    int i, j, k;

    for (i = 1; i <= 5; i++) {

        for (k = 1; k < i; k++) {
            printf(" ");  // spaces
        }

        for (j = i; j <= 5; j++) {
            printf("%d", j);  // ascending numbers
        }

        for (j = 4; j >= k; j--) {
            printf("%d", j);  // descending numbers
        }

        printf("\n");
    }

    return 0;
}
