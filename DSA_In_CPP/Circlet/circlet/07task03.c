#include <stdio.h>

int main() {
    int i, j, k;

    for (i = 1; i <= 5; i++) {

        for (k = i + 1; k <= 5; k++) {
            printf(" ");  //  spaces
        }

        for (j = 6 - i; j <= 5; j++) {
            printf("%d", j);  // increasing numbers
        }

        printf("\n");
    }

    return 0;
}
