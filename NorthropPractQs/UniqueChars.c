#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "helperfuncs.h"

	/*
	Implement an algorithm to determine if a string has all unique characters. What if
	you cannot use additional data structures
	*/

int onlyUniqueChars( char *str );

int main(){

	char *str = getString();
	//printf("yourString(%s)", str );

	if( onlyUniqueChars(str) == 1)
		printf("You have unique characters in %s", str );
	else
		printf("You do not have all unique chars in %s", str);
}

int onlyUniqueChars( char *str )
{
	//Set array to zero representing all ascii values
	int newChars[256];
	memset(newChars,0,256*sizeof(int));

	for( int i = 0; i < strLength(str); i++)
	{
		if( newChars[ str[i] ] == 0 )
		{
			newChars[ str[i] ] = 1; //We haven't seen this char yet
		}
		else if( newChars[ str[i] ] == 1 )
		{
			return 0; 					//not all unique characters
		}
			
	}
	return 1;
}