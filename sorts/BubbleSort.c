#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *intArray(int size)
{

	srand(time(NULL));

	int *array = malloc(sizeof(int)*size);

	for(int i =0; i < size; i++)
		array[i] = rand()%100;

	return array;
}

void printArray(int *array, int size)
{

	printf("\nYour array -->");

	for(int i = 0; i < size; i++)
		printf(" %d ", array[i] );

	printf("\n");

}

void swap(int *array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void bubbleSort(int *array, int size)
{

	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)	
		{
			if(array[j] > array[j+1])
				swap(array, j, j+1);
		}
	}

}

int main()
{
	int size;
	printf("What size do you want your array? size: ");
	scanf("%d", &size);

	int *array = intArray(size);

	printArray(array, size);

	bubbleSort(array, size);
	
	printArray(array, size);

	printf("\n");

}			
