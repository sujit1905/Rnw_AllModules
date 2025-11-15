//Alphabet skipper
#include<stdio.h>
int main()
{
// Starting from the letter 'A'
    char ch = 'A'; 
    
    do {
        printf("%c\n", ch);  
        // Skip 3 alphabet
        ch = ch + 4;         
    } while(ch <= 'Z');// Stop at 'Z'
    
    return 0;
}

