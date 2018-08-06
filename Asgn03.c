#include <stdio.h>
#include <stdlib.h>

/**
Caleb Privitera
Assignment 3
Count the number of carry operations for addition problems
so that educators may assess their difficulty.
**/

int firstnum, secondnum, sum, summods;
int modone, modtwo, count, first, second;
int carry, numzero;

int main(){
    
    //initialize numzero to 1 to start counting carries
    numzero = 1;
    
    // exit when number is zero
    while (numzero > 0)
    {
    
    //initialize carry, count, and sum to zero
    carry = 0;  
    count = 0;  
    sum = 0;
    
    //prompt user for input
    printf ("Enter two integers to add together (enter 0 first to exit):\n");
    scanf ("%d %d", &firstnum, &secondnum);
    
    first = firstnum;
    second = secondnum;
    // check first number for zero, find sum, print sum
    numzero = firstnum;
    sum = firstnum + secondnum;
    printf ("The sum of your two integers is: %d\n", sum);
    
    // when number is divided or modded and the result is 1 or greater, a carry is needed
    while((firstnum % 10 >= 1 || secondnum % 10 >= 1 || firstnum / 10 >= 1 || secondnum / 10 >= 1 ))
            {
    
    
    modone = firstnum % 10;
    modtwo = secondnum % 10;
    
    summods = modone + modtwo + carry;
    
    firstnum = firstnum / 10;
    secondnum = secondnum / 10;
    
    if (summods > 9)
    {
        carry = summods / 10;
        count++;
    }
    }
    // print result
    printf ("There were %d carries performed when adding %d and %d.\n", count, first, second);
}
printf ("Program terminated.\n");
return 0;
}

