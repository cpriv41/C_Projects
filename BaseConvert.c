#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char o, d, x, b;
char inbase, convertbase, dummy;
int innumber;
char bin [16]; //binary

int main()
{	

char response = 'y';

	while(response =='y' || response == 'Y'){
	
	printf("Enter a base of input (o = otal, d = decimal, x = hex, b = binary):\n");
	scanf("%c", &inbase);
	scanf("%c", &dummy);
	
	if (inbase == 'x'){
		printf("Enter a number to be converted:\n");
		scanf("%x", &innumber);
		scanf("%c", &dummy);
		
		printf("Choose a base to convert number to (o = otal, d = decimal, x = hex):\n ");
		scanf("%c", &convertbase);
		scanf("%c", &dummy);
	
	if(convertbase == 'd'){
		printf("%d", innumber);
	}
	else if(convertbase == 'o'){
		printf("%o", innumber);
	}
	else if(convertbase == 'x'){
		printf("%x", innumber);
	}
	}
	else if (inbase == 'o'){
		printf("Enter a number to be converted:\n");
		scanf("%o", &innumber);
		scanf("%c", &dummy);
		
		printf("Choose a base to convert number to (o = otal, d = decimal, x = hex):\n ");
		scanf("%c", &convertbase);
		scanf("%c", &dummy);
	
	if(convertbase == 'd'){
		printf("%d", innumber);
	}
	else if(convertbase == 'o'){
			printf("%o", innumber);
	}
	else if(convertbase == 'x'){
		printf("%x", innumber);
	}
	}
	
	else if (inbase == 'd'){
		printf("Enter a number to be converted:\n");
		scanf("%d", &innumber);
		scanf("%c", &dummy);
			
		printf("Choose a base to convert number to (o = otal, d = decimal, x = hex):\n ");
		scanf("%c", &convertbase);
		scanf("%c", &dummy);
	
	if(convertbase == 'd'){
		printf("%d", innumber);
	}
	else if(convertbase == 'o'){
			printf("%o", innumber);
	}
	else if(convertbase == 'x'){
		printf("%x", innumber);
	}
	
	}
	else if(inbase == 'b'){
		printf("Enter a number to be converted:\n");
		scanf("%s", &bin);
		scanf("%c", &dummy);
		
		int sum = 0;
		int i;

		for (i = 0; i < strlen(bin); i++)
		{
			sum = (sum << 1) + (bin[i] - 48);
		}
		
		printf("Choose a base to convert number to (o = otal, d = decimal, x = hex):\n ");
		scanf("%c", &convertbase);
		scanf("%c", &dummy);
		
	if(convertbase == 'd'){
		printf("%d", sum);
	}
	}
	
	printf("\nDo you want to continue? (Y or N):\n");
	scanf("%c", &response);
	scanf("%c", &dummy);
	}
	
		
	return 0;
}

