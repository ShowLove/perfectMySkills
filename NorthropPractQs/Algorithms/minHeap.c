// Sean Szumlanski
// COP 3502, Summer 2013

// Adapted from class on July 9, 2013

// This is the minheap implementation from class today. There are lots of other
// ways to do this. You might want to outsource the percolate-up and percolate-
// down operations to their own functions. Note that main() is performing a
// heapsort.


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct heap
{
	// heap
	int *array;

	// number of elements in heap
	int size;

	// max size of heap
	int max;
} heap;


// create a new heap that can hold up to 'n' values
heap *makeHeap(int n)
{
	heap *h = malloc(sizeof(heap));
	
	h->array = malloc(sizeof(int) * n);
	h->size  = 0;
	h->max   = n;
	
	return h;
}

void swap(int *array, int i, int j)
{
	int tmp = array[i]; array[i] = array[j]; array[j] = tmp;
}

// insert into the heap; O(log n) in the worst case, O(1) in the best case
void heapInsert(heap *h, int key)
{
	int child, parent;
	
	// if heap is full, abort
	if (h->size >= h->max)
	{
		printf("ERROR: heap is full in heapInsert()\n");
		return;
	}
	
	h->array[h->size++] = key;

	// percolate up like nobody's business
	child = h->size - 1;
	parent = (child - 1) / 2;
	
	while (h->array[child] < h->array[parent])
	{
		// swappy swap
		swap(h->array, child, parent);
		
		// after the swap, the element we're percolating up is in this new
		// position
		child = parent;
		
		// find the place we're thinking of swapping this element into next
		parent = (child - 1) / 2;
	}
	
	// Suppose 'child' is zero (i.e., the root). Then, 'parent' will be zero
	// also! Therefore, this while-loop terminates if the new node percolates all
	// the way up to the root!
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

// Return the index of whichever child of node 'parent' has the smallest
// value. If the node at index 'parent' has no children, return parent.
int minChildIndex(heap *h, int parent)
{
	int lc, rc;
	
	lc = (parent * 2 + 1 >= h->size) ? parent : (parent * 2 + 1);
	rc = (parent * 2 + 2 >= h->size) ? parent : (parent * 2 + 2);
	
	return (h->array[lc] <= h->array[rc]) ? lc : rc;
}

// delete the minimum element from the heap; O(log n) worst case, O(1) best case
int deleteMin(heap *h)
{
	int ret, child, parent;

	if (h->size <= 0)
	{
		printf("ERROR: heap is empty in deleteMin()\n");
		return 0;
	}

	// the value at the root will have to be returned
	ret = h->array[0];
	
	// if the minheap is now empty, just return
	if (--h->size == 0)
		return ret;
	
	// move the last element up to the root
	h->array[0] = h->array[h->size];
	
	// otherwise, percolate down like nobody's watching
	parent = 0;
	child = minChildIndex(h, 0);
	while (h->array[parent] > h->array[child])
	{
		// swappy swap
		swap(h->array, parent, child);
		
		// after the swap, the element we're percolating down is in this new
		// position
		parent = child;
		
		// find the place we're thinking of swapping this element into next
		child = minChildIndex(h, parent);
	}
	
	return ret;
}

// print the heap array to the screen
void printHeap(heap *h)
{
	int i;

	for (i = 0; i < h->size; i++)
		printf("%d%c", h->array[i], (i == h->size - 1) ? '\n' : ' ');
}


// If an operation is T(n) = n + n log n, then T(n) is O(n log n).
int main(void)
{
	int i, r, n = 10;
	heap *h = makeHeap(n);

	srand(time(NULL));

	// insert some random integers
	for (i = 0; i < n; i++)
	{
		printf("Inserting %d...\n", r = rand() % 100 + 1);
		heapInsert(h, r);
	}

	// print the heap so we can check that everything go in there correctly
	printHeap(h);

	// delete the minimum element from the heap until it's empty; these should
	// print all the integers out in sorted order
	while (h->size > 0)
	{
		r = deleteMin(h);
		printf("Deleted %d.\n", r);
		
		// exercise: call printHeap(h) here so you can see how the array is
		// changing with each deleteMin() operation. Perform the deleteMin()
		// operation on paper and verify that your results are the same.
	}

	// this should be empty now
	printHeap(h);

	return 0;
}