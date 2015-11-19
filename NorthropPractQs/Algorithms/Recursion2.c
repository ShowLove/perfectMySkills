// recursion-basics.c
// Adapted from class on May 28, 2013

// These are some introductory recursive functions from class today. You should
// experiment with these functions. Make subtle changes to them. Inject printf()
// statements into them so you can trace through their execution. Become one
// with recursion. Also, check out the runtime analysis at the end of this file.


#include <stdio.h>
#include <string.h>

// A recursive function that sums all numbers from 0 to n.
// Assume n is a non-negative integer.
int sum(int n)
{
	// base case
	if (n == 0)
		return 0;
	
	return n + sum(n - 1);
}

/*
Here's what the return values are:

sum(n) = n + sum(n - 1)
             ^
             (n - 1) + sum(n - 2)
                       ^
                       (n - 2)  + sum(n - 3)
                                  ^
                                  ...and so on, until we call sum(0)

Here's a more concrete example:

sum(5) = 5 + sum(4)
             ^
             4 + sum(3)
                 ^
                 3 + sum(2)
                     ^
                     2 + sum(1)
                         ^
                         1 + sum(0)
                             ^
                             0
*/

// A recursive function to multiply integers a and b using only addition and
// subtraction operators. Assume a and b are non-negative integers.
//
// Recall that this is an iterative solution:
//
// for (sum = i = 0; i < a; i++)
//    sum += b;
//
int mult(int a, int b)
{
	int x;
	
	if (a == 0 || b == 0)
		return 0;
	
	x = a + mult(a, b - 1);

	// You could just return (a + mult(a, b - 1)), but maybe you want to print
	// out some debugging statements after you return from the recursive call,
	// before returning. For example:
	printf("You called: mult(%d, %d)\n", a, b);
	
	return x;
}

// A recursive function to print a string character-by-character. Uses pointer
// arithmetic. Is moderately fancy.
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

// A recursive function to print a string character-by-character. Uses pointer
// arithmetic. Is very fancy.
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

// Find the minimum element in an array of integers. Use recursion. Initially,
// n is the number of elements in the array. (Assume n > 0. But, the values in
// the array themselves can be negative.)
int array_min(int *array, int n)
{
	int x;
	
	if (n == 1)
	{
		return array[0];
	}
	
	if (array[0] < array_min(array + 1, n - 1))
		return array[0];
	else
		return array_min(array + 1, n - 1);


	// ANOTHER APPROACH: Avoid the second call to array_min(), which could be
	// quite expensive (if n is huge). Instead, save its return value in a
	// variable, x, and use that in your comparison and return statements.
	x = array_min(array + 1, n - 1);

	if (array[0] < x)
		return array[0];
	else
		return x;
	

	// ANOTHER APPROACH: Nest the x = array_min(array + 1, n - 1) statement
	// within the comparison statement.
	if (array[0] < (x = array_min(array + 1, n - 1)))
		return array[0];
	else
		return x;

	
	// YET ANOTHER APPROACH: Start by peeling the last element off. Then, we
	// don't even need pointer arithmetic!
	if (array[n - 1] < (x = array_min(array, n - 1)))
		return array[n - 1];
	else
		return x;
}

// return the minimum of two integers
int min(int a, int b)
{
	// conditional operator is awesome
	return (a < b) ? a : b;
}

// This is how I would implement the recursive solution. 
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

// We saw the following runtime analysis for sz_array_min():
//
// T(n) = T(n - 1) + 2, with T(1) = 1 (for the base case)
//
// Using that formula, we can also plug (n - 1) in for (n) and get:
//
// T(n - 1) = T((n - 1) - 1) + 2
//          = T(n - 2) + 2
//
// Now, let's substitute into the original formula until we start to see a
// pattern emerge:
//
// T(n) = T(n - 1) + 2
//      = (T(n - 2) + 2) + 2              = T(n - 2) + 2 * 2
//      = ((T(n - 3) + 2) + 2) + 2        = T(n - 3) + 2 * 3
//      = (((T(n - 4) + 2) + 2) + 2) + 2  = T(n - 4) + 2 * 4
//      = ...
//      = T(n - k) + 2 * k
//
// Our ticket out of this thing is to get T(1) in there somewhere, since we
// have a value for that (T(1) = 1). So, we want (n - k) = 1, which implies
// k = n - 1. Thus, we get:
//
// T(n) = T(1) + 2 * (n - 1)     -- substituting (n - k) = 1
//      = 1 + 2 * (n - 1)        -- substituting T(1) = 1 (given)
//      = 2n - 1                 -- algebra
//
//  => T(n) is O(n)
//             ^ TADA!

int main(void)
{
	int a[] = {4, 5, 3, 2, 6, 1, 8, 7};

	printf("The sum of all integers 0..5 is: %d\n", sum(5));

	printf("11 * 12 = %d\n", mult(11, 12));

	print_string("Hello!", strlen("Hello!"));

	print_string_a_little_bit_more_difficult("Hello!");

	printf("Minimum array element is: %d\n", array_min(a, 8));

	printf("Minimum array element is: %d\n", sz_array_min(a, 8));

	return 0;
}