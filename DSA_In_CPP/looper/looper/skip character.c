//Alphabet skipper
#include<stdio.h>
int main()
{
// Starting from the letter 'a'
    char ch = 'a'; 
    
    do {
        printf("%c\n", ch);  
        // Skip 3 alphabet
        ch = ch + 4;         
    } while(ch <= 'z');// Stop at 'z'
    
    return 0;
}

