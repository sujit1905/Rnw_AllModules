#include <stdio.h>

int main() {
    int i, j, num;
    // starting number
    int start = 41;  

    for (i = 0; i < 5; i++) {
    	// reset num for each row
        num = start;  
        for (j = 0; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}
