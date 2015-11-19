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



int *insertionSort(int *array,int  size)
{
	int tmp;
	int k = 0, j = 0, i = 0;
	
	for(i = 0; i < size; i++)
	{
		
		for(j = 0; j < i; j++)
		{
			if( array[i] < array[j])
			{
				tmp = array[j];
				array[j] = array[i];

				for( k = i; k > j+1; k--)
					array[k] = array[k-1];

				array[k] = tmp;
			}
		}

	}

	return array;
}

void printArray(int *array, int size)
{

	printf("\nYour array -->");

	for(int i = 0; i < size; i++)
		printf(" %d ", array[i] );

	printf("\n");

}

int main()
{
	int size;
	printf("How big do you want your random array? size = ");
	scanf("%d", &size);

	int *array = intArray(size);

	printArray(array, size);
	
	array = insertionSort(array, size);

	printArray(array, size);

}		
