//Digit counter
#include<stdio.h>

int main()
{
	int num, Digit = 0;
	// Ask user for input
	printf("Enter Number: ");  
	scanf("%d", &num);

	while(num != 0)
	{
		// Drop the last digit
    	num = num / 10;
    	Digit++;   
	}
	// Show total count
	printf("The Digits are: %d", Digit); 
}
