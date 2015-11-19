#include <stdio.h>
#include <string.h>

//sum all the numbers from o to n twice and add togethor
int sum(int num1)
{
	if( num1 = 0 )
		return sum;

	return num1 + sum(num1 - 1);
}

int mult(int num1, int num2, int sum )
{
	if(num2 == 0 || num1 == 0)
		return 0;

	sum = num1 + mult(num1, num2 -1, sum);

	return sum;
}

void print_string(char *str, int len)
{
	if( len == 0 )
	{
		printf("\n");
		return;
	}

	printf("%c", str[0]);

	print_string(str+1, len-1);
}

void print_string_a_little_bit_more_difficult(char *str)
{
	// Recall that *str and str[0] are synonymous
	if (*str == NULL)
	{
		printf("\n");
		return;
	}

	printf("%c", *str);
	print_string_a_little_bit_more_difficult(str + 1);
}

int main()
{
	char *p = "hello";
	print_string(p, 5);
	print_string_a_little_bit_more_difficult(p);
	int result = mult(2, 2, 0);
	printf("mult(%d)", result );


}