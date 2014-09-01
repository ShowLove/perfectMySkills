#include <stdio.h>
#include <string.h>

/****************************************************************************
*  A recursive function to print a string character-by-character. Uses pointer
*  arithmetic. Is moderately fancy.
*****************************************************************************/
void print_string(char *str, int len)
{
	if (len == 0)
	{
		printf("\n");
		return;
	}
	
	printf("%c", str[0]);
	print_string(str + 1, len - 1);	
}

/****************************************************************************
*  A recursive function to print a string character-by-character. Uses pointer
*  arithmetic. Is very fancy.
****************************************************************************/
void print_string_a_little_bit_more_difficult(char *str)
{
	// Recall that *str and str[0] are synonymous
	if (*str == '\0')
	{
		printf("\n");
		return;
	}

	printf("%c", *str);
	print_string_a_little_bit_more_difficult(str + 1);
}

/****************************************************************************
*  return the minimum of two integers
****************************************************************************/
int min(int a, int b)
{
	// conditional operator is awesome
	return (a < b) ? a : b;
}

/****************************************************************************
*  This is how I would implement the recursive solution. 
****************************************************************************/
int sz_array_min(int *array, int n)
{
	// If there's just one element in our array, that's the minimum element in
	// the array.
	if (n == 1)
		return array[0];

	// Take the minimum of the last element in the array, or the minimum element
	// among the first (n - 1) elements of the array.
	return min(array[n - 1], sz_array_min(array, n - 1));
}

/**********************************************************
* This is just a different way of writing faster_power().
* returns a^b
********************************************************/
int faster_power_extra_fancy(int a, int b)
{
	int x;
	
	if (b == 0)
		return 1;
	
	x = faster_power_extra_fancy(a, b / 2);
	x = x * x;

	x = (b % 2) ? (x * a) : x;
	
	return x;
}

/****************************
* returns the facorial of n
* this cant handle huge numbers
****************************/
long factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}

int main()
{
	int a = 3, b = 7;

	a = 	faster_power_extra_fancy(a,b);

	printf("the output was %d \n",a);
}
