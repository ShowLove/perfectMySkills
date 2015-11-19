nclude <stdio.h>
#include <time.h>

#define LEN 10

// BINARY SEARCH (ASSUMES ARRAY IS IN SORTED ORDER)
// Worst-case: ??
// Best-case:  ??
int binary_search(int *array, int n, int key)
{
	int lo = 0, hi = n - 1, mid;
	
	while (hi >= lo)
	{
		// Why use this instead of mid = (hi + lo) / 2, even though they're
		// algebraically equivalent?
		mid = lo + (hi  - lo) / 2;
		
		// if the key is less than the value at mid, consider only the left half
		// of the array
		if (key < array[mid])
			hi = mid - 1;
		
		// if the key is greater than the value at mid, consider only the right
		// half of the array
		else if (key > array[mid])
			lo = mid + 1;
		
		// otherwise, we found the key!
		else
			return 1;
	}
	
	return 0;
}

// This allows me to sort using the qsort() function in C. It returns a
// positive integer if (*a > *b), a negative integer if (*b < *a), and zero if
// (*a == *b). If you want to know more, google "c qsort" and read up on it.
int mycmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main(void)
{
	int i, r, array[LEN];
	
	srand(time(NULL));
	
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
	
	// Randomly select an integer from [1..20] to search for
	r = rand() % 20 + 1;
	printf("\nSearching for %d...\n", r);

	// Search for the key in the array. Try using binary_search() here, and try
	// using linear_search(). You could wire all this into the grind.c framework
	// and do some fun runtime analysis!
	if (binary_search(array, LEN, r))
		printf("Found %d in the array!\n", r);
	else
		printf("Could not find %d in the array. :(\n", r);
	
	return 0;
}