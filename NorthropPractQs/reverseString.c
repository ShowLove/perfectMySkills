#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "helperfuncs.h"

char *reverseString(char *str );

void main()
{
	char *str = getString();
	printf("OriginalString(%s)", str );
	printf("revString(%s)", reverseString(str) );
	//reverseString(str);
}

char *reverseString(char *str)
{
	int Length = strLength(str);

	for(int i = 0; i < Length/2; i++)
	{
		swapP( &str[i], &str[Length - i - 1] );
	}

	return str;
}