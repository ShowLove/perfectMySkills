#include <stdio.h>
#include <stdlib.h>

void findNumAlefB();

int main()
{
	findNumAlefB();
}

/*
	finds int representation of each letter of the alphabet
*/
void findNumAlefB()
{
	int a = (int) 'a';
	int A = (int) 'A';	
	int null = (int) '\0'; //First letter of ascii
	int tilde = (int) '~';  //Second to last letter in ascii DEL is last

	//26 letters in alphabet
	printf("lower case int rep of ascii a-z %d-%d \n", a, (a+26-1) );
	printf("Upper case int rep of ascii a-z %d-%d \n", A, (A+26-1) );
	printf("int rep of chars range from %d-%d in ascii \n", null, tilde+1 ); //+1 for del

	int num = 7;
	printf("%d,7%d,.7%d,:%7d,%.7d,%d", num, num, num, num, num, num );
	printf("\n %d num++", num++);
	printf("%d<--- 8  now  --num %d",num, --num);
	
}

