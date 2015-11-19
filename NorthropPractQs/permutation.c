#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "helperfuncs.h"

int main()
{

	int asciiSize = 255;
	char *str1 = getString();
	char *str2 = getString();
	int bucket[asciiSize];
	int isPermutation = 1;

	memset( bucket, 0, sizeof(int)*asciiSize );

	if( strL(str1) != strL(str2) )
	{
		isPermutation++;
		printf("%s is NOT a permutation of %s", str1, str2);
	}

	int str1L = strL(str1), strL2 = strL(str2);

	for(int i = 0; i < str1L; i++)
	{
		bucket[ (int) str1[i] ]++;
	}

	for(int i = 0; i < strL2; i++)
	{
		bucket[ (int) str2[i] ]--;
		if( bucket[ (int) str2[i] ] < 0 )
			isPermutation = 0;
	}

	( isPermutation == 1 ) ? printf("They were permutations\n") : printf("They were NOT permutation\n");
}