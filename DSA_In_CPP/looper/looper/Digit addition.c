//Digit Addition
#include <stdio.h>

int main()
{
    int num, temp, Fdigit, Ldigit, ans;

    printf("Enter Number: ");
    scanf("%d", &num);

    temp = num;      
	// for last digit         
    Ldigit = temp % 10;     

    while(temp >= 10)        
    {
    // for first digit 
        temp = temp / 10;     
    }
    Fdigit = temp;         
	// Add first and last digit
    ans = Fdigit + Ldigit;   
	 printf("Addition is: %d",ans);
	// Display the answer

    return 0;
}

