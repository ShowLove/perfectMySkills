// more-recursion.c
// Adapted from class on May 30, 2013


#include <stdio.h>
#include <string.h>

// Let's write a RECURSIVE FUNCTION that returns the sum of all digits in n.
// For example: digi_sum(123) = 1 + 2 + 3 = 6
// For example: digi_sum(-133) = 1 + 3 + 3 = 7
// HINT: Use integer division and modular arithmetic (/, %)
//
// 867 % 10 = 7
// 867 / 10 = 86
//
int digi_sum(int n)
{
	// initial condition
	if (n < 0)
		n = n * -1;
	
	// base case
	if (n < 10)
		return n;
	
	return (n % 10) + digi_sum(n / 10);
}

// THIS IS A RECURRENCE RELATION. It represents the runtime of digi_sum().
//
// if (n < 10) then T(n) = 2
//    otherwise T(n) = 2 + 2 + T(n/10)
//
// WE SOLVED THIS IN CLASS BY PERFORMING ITERATIVE SUBSTITUTION.
//
// T(n) = [T(n/10)] + 4
//
//      = [4 + T(n/(10^2))] + 4 = [T(n/(10^2))] + 4 * 2
//
//      = [4 + T(n/(10^3))] + 4 * 2 = T(n/(10^3)) + 4 * 3
//
//      = ...
//
//      = T(n/(10^k)) + 4*k
//
//
// Okay, so we have this general form, but how can I close it off? Where
// does this thing bottom out?
//
// If (n/(10^k)) is equal to 1, then we have T(1) + 4*k and we can stop.
//
// But in this case, what is k?
//
// n/(10^k) = 1 => n = 10^k => k = log(n)
//
// So, let's plug this into our T(1) + 4*k:
//
// T(n) = T(1) + 4*log(n)
//      = 2 + 4*log(n)
//
// T(n) is O(log n)


// A recursive function to print a string character-by-character.
void print_string_rec(char *s)
{
	if (*s == '\0')
	{
		printf("\n");
		return;
	}
	
	printf("%c", *s);
	print_string_rec(s + 1);
}

// A recursive function to print a string in reverse, character-by-character.
// Notice how this is just a slight variation on print_string_rec() above.
void reverse_print_string(char *s)
{
	// What happens if we put a printf("\n") in this base case?
	if (*s == '\0')
		return;
	
	reverse_print_string(s + 1);
	printf("%c", *s);
}

// This is fancy, clever, etc., and should be studied.
void reverse_print_string_fancy(char *s, char *anchor)
{
	if (*s == '\0')
		return;
	
	reverse_print_string_fancy(s + 1, anchor);
	printf("%c", *s);
	
	if (s == anchor)
		printf("\n");
}

// THIS RECURRENCE RELATION IS FANTASTIC. It's for reverse_print_string()
//
// Let n be the length of the string s. Then:
// T(0) = 1
// T(n) = 1 + T(n - 1) + 2  (for n > 0)
//
// T(n) = [T(n - 1)] + 3
//      = [T(n - 2) + 3] + 3
//      = T(n - 3) + 3 + 3 + 3
//      = T(n - 4) + 3 + 3 + 3 + 3
//      = ...
//      = T(n - k) + 3*k
//
// Let n - k = 0. Then k = n. Let's substitute:
//
//      = T(0) + 3(n)
//      = 1 + 3n
//
// T(n) = 3n + 1, which O(n)


// THIS IS THE FAMOUS FIBONACCI SEQUENCE
//
// F(0) = 0
// F(1) = 1
// F(n) = F(n - 1) + F(n - 2)
//
// F(2) = F(1) + F(0) = 1 + 0 = 1
// F(3) = F(2) + F(1) = 1 + 1 = 2
// F(4) = F(3) + F(2) = 2 + 1 = 3
// F(5) = F(4) + F(3) = 3 + 2 = 5
//
// ... and so on.
//
int Fibonacci(int n)
{
	int x;

	if (n == 0 || n == 1)
		return n;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// HERE'S THE RECURRENCE RELATION FOR Fibonacci()
//
// T(0) = 1;
// T(1) = 1;
// T(n) = 2 + T(n - 1) + T(n - 2)     (for n > 1)
//
// We saw that this funtion is EXPLOSIVE. It's actually O(2^n)! We also saw that
// the explosive runtime is a result of lots of repeated recursive calls!
//
// CHECK YOUR UNDERSTANDING: If we call F(5) from main(), how many recursive
// calls will be made to F(2) over the course of execution?


// Let's write a recursive function that returns a ^ b.
//
//   Recall: a ^ b = a * a * a * ... * a  (a occurs b number of times)
//
// You may assume 'b' is non-negative. However, 'a' may be any integer.
//
int my_power(int a, int b)
{
	// The base cases you all came up with in class today make this function
	// more efficient in certain cases. You all rock!
	
	if (b == 0 || a == 1)
		return 1;
	
	if (b == 1 || a == 0)
		return a;

	// a^b = a * a^(b-1), so...
	return a * my_power(a, b - 1);
}

// Now, what is the reccurence relation for my_power()? You could write the
// recurrence relation for my_power as a function of b. (Why not a?)

// Now, let's take a cleverer approach based on the observation that:
//
//   a^b = a^(b/2) * a(b/2)      -- if b is even
//   a^b = a^(b/2) * a(b/2) * a  -- if b is odd
//
// For example, a^6 = a^3 * a^3, and a^7 = a^3 * a^3 * a
//
// Do you see where this is going?
//
int faster_power(int a, int b)
{
	int x;
	
	// Simplified base case.
	if (b == 0)
		return 1;
	
	// We could write x = faster_power2(a, b / 2) * faster_power2(a, b / 2),
	// but it's a bit silly to call that function twice. Let's save time:
	x = faster_power(a, b / 2);
	
	// If b is even, we want to return a^(b/2) * a^(b/2)
	if (b % 2 == 0)
		x = x * x;
	// If b is odd, we want to return a^(b/2) * a^(b/2) * a
	else
		x = x * x * a;
	
	return x;
}

// This is just a different way of writing faster_power().
int faster_power_extra_fancy(int a, int b)
{
	int x;
	
	if (b == 0)
		return 1;
	
	x = faster_power_extra_fancy(a, b / 2);
	x = x * x;

	// x is (a^(b/2) * a^(b/2)) right now, but f b is odd, then we want
	// x = (a^(b/2) * a^(b/2) * a). This conditional statement does that for us.
	x = (b % 2) ? (x * a) : x;
	
	return x;
}

// RECURRENCE RELATION for the faster_power() functions. The constant (3) in the
// T(b) definition is a bit loose, but won't affect Big-Oh.
//
// T(0) = 1
// T(b) = 3 + T(b/2)  (for b > 0)
//
// Can you solve this using iterative substitution? It should come out to:
// O(log b).
//
// For the record, the following for-loop is also O(log n). Can you see the
// relationship? Could you derive the runtime by drawing a table and using
// iterative substitution? (We did an example like this in the second week
// of class.)
//
// for (i = 1; i < n; i *= 2)
//	   x++;
//
// for (i = n; i > 0; i = i/2)
//    x++;


int main(void)
{
	char buffer[100];
	strcpy(buffer, "Hello!");
	
	// Recursive function to print string
	print_string_rec(buffer);
	
	// Recursive function to print string in reverse; doesn't print \n
	reverse_print_string(buffer);
	printf("\n");

	// Fancy recursive function to print string in reverse; prints \n, too.
	reverse_print_string_fancy(buffer, buffer);
	
	// Slow for n = 42
	//printf("F(%d) = %d\n", 42, Fibonacci(42));
	
	printf("%d\n", my_power(-2, 4));

	printf("%d\n", faster_power(-2, 4));
	
	printf("%d\n", faster_power_extra_fancy(-2, 4));
	
	return 0;
}