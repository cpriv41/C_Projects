#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int todecimal(char *str, int base )
{

    int length = strlen(str);
    int result = 0;
    int power = 1;
    int index;

    for(index = length -1; index >= 0; index--)
    {
        result = result + val(str[index] * power); // calculate the result at each index position
        power = power * base;
    }
    return result;
}


//char string[];
char o, d, x, b;
char inbase, convertbase;
char innumber[];
char outbase;
char dummy;
int main()
{

    printf("Enter a base of input (o = otal, d = decimal, x = hex, b = binary):\n");
    scanf("%c", &inbase);
    scanf("%c", &dummy);

    printf("Enter a number to be converted:\n");
    scanf("%s", &innumber);

    printf("Choose a base to convert number to (o = otal, d = decimal, x = hex, b = binary):\n ");
    scanf("%c", &convertbase);

    /*if(inbase == d){
        inbase = 10;
        outbase = todecimal(innumber, inbase);
        printf("Result of conversion is %s:\n", outbase);
    }*/
    if(inbase == o && convertbase == d){
        inbase = 8;
        outbase = todecimal(innumber, inbase);
        printf("Result of conversion is %s:\n", outbase);
    }
    if(inbase == x && convertbase == d){
          inbase = 16;
        outbase = todecimal(innumber, inbase);
        printf("Result of conversion is %s:\n", outbase);
    }
    if(inbase == b && convertbase == d){
          inbase = 2;
        outbase = todecimal(innumber, inbase);
        printf("Result of conversion is %s:\n", outbase);
    }

    return 0;
}
