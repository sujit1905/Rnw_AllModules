#include <stdio.h>

int main() {
    int i, j;

    for (i = 0; i < 5; i++) {

        for (j = 0; j < 5; j++) {

            if (i == 0 || i == 2) {
                printf("* ");  // full row
            } 
            else if (i == 1) {
                if (j == 0 || j == 4) {
                    printf("* ");  // edges only
                } else {
                    printf("  ");  // hollow space
                }
            } 
            else {
                if (j == 0) {
                    printf("*");  // single star
                }
            }
        }

        printf("\n");
    }

    return 0;
}
