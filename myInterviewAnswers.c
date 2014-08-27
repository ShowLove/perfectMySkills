//Qestion1
/*"Given an array of integers, define an algorithm that deduces whether a given sum can be attained by adding two numbers in the array without using data structures." */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void q1();

//HELPER FUNCTIONS
int mycmp(const void *a, const void *b);
void sortArray(int *array, int LEN);


int main( void )
{
	q1();

	return 0;
}


//HELPER FUNCTIONS//
// This allows me to sort using the qsort() function in C. It returns a
// positive integer if (*a > *b), a negative integer if (*b < *a), and zero if
// (*a == *b). If you want to know more, google "c qsort" and read up on it.
int mycmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

//This function sorts an array
void sortArray(int *array, int LEN)
{
	int i, r;

	// Populate with random integers. (What is the range of values here?)
	for (i = 0; i < LEN; i++)
		array[i] = rand() % 20 + 1;

	// Print the array for posterity.
	printf("Unsorted array:\n");
	for (i = 0; i < LEN; i++)
		printf("%d%c", array[i], (i == LEN - 1) ? '\n' : ' ');

	// Sort the array using C's built-in QuickSort function. This is using a
	// function pointer. It's amazing. You should google "c qsort" and read
	// about how it works.
	qsort(array, LEN, sizeof(int), mycmp);

	// Print the array for posterity.
	printf("\nSorted array:\n");
	for (i = 0; i < LEN; i++)
		printf("%d%c", array[i], (i == LEN - 1) ? '\n' : ' ');

}
//HELPER FUNCTIONS END//

void q1()
{
	int LEN;
	int findDisSumInArray;
	int array[LEN];
	int *arrayBeg, *arrayEnd;
	int weFoundSumInArray = 0;

 	printf("Q1: Given an array of integers, define an algorithm that deduces whether a given sum can be attained by adding two numbers in the array without using data structures.\nHow long do you want your array to be?\n L:");
	scanf("%d", &LEN);

	//Use my sort array function to sort this array
  sortArray(array, LEN);

	//prompt for the sum
	printf("What sum do you want to find in the array? Sum: ");
	scanf("%d", &findDisSumInArray);

	//Set pointers to beginning and end of array then print to confirm
	arrayBeg = array;
	arrayEnd = &(array[LEN - 1]);
	printf("\narrayBeg(%d), arrayEnd(%d)\n", *arrayBeg, *arrayEnd);

	int aSum;
	//logic
	while( weFoundSumInArray < 1 )
	{
		aSum =  (*arrayBeg+*arrayEnd); 
		if( findDisSumInArray == aSum )
			weFoundSumInArray = 1;

	  if( arrayBeg == arrayEnd )
			weFoundSumInArray = 2;

		findDisSumInArray < aSum ? arrayEnd-- : arrayBeg++;

		//debug
		printf("\nDebug: arrayBeg(%d)arrayEnd(%d)aSum(%d)", *arrayBeg, *arrayEnd, aSum);
		
	}	

	weFoundSumInArray == 1 ? printf("sum is %d plus %d = %d\n", *arrayBeg, *arrayEnd, findDisSumInArray) : printf("We could not find it :/ ");

}