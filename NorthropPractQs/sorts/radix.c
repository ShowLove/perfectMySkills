// radix.c
// Adapted from class on June 20, 2013


#include <stdio.h>
#include <stdlib.h>

#define LENGTH 7

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef struct Queue
{
	struct node *head;
	struct node *tail;
} Queue;

node *createNode(int data)
{
	node *n = malloc(sizeof(node));

	n->data = data;
	n->next = NULL;

	return n;
}

Queue *initQueue(void)
{
	Queue *p = malloc(sizeof(Queue));

	p->head = NULL;
	p->tail = NULL;

	return p;
}

// Insert a new node at the back of the queue (i.e., the tail of the list).
// Return -1 if insertion fails, or 'data' if insertion succeeds. You might
// want to call the createNode() function defined in node.c.
int enqueue(Queue *p, int data)
{
    //node *helper;

    if (isEmpty(p))
        return p->head = p->tail = createNode(data);

//    for(helper = p->head; helper->next != NULL; helper = helper->next)
//        ;

    p->tail->next = createNode(data);
    p->tail = p->tail->next;

    if (p->tail->next == NULL)
        return -1;

    return p->tail->data;
}

// Remove the element at the front of the list (i.e., the head of the list).
// Return the 'data' stored in the dequeued node, or -1 if the queue is empty.
// Keep in mind that you need to free() the node being removed to avoid memory
// leaks.
int dequeue(Queue *p)
{
    int lol;

    if (isEmpty(p))
        return -1;

    lol = p->head->data;

    p->head = p->head->next;

    return lol;
}

int isEmpty(Queue *p)
{
	return (p->head == NULL);
}

void RadixSort(int *array, int n)
{
	int i, j, pow, max = array[0];

	Queue *buckets[10];

	// create some buckets
	for (i = 0; i < 10; i++)
		buckets[i] = initQueue();

	// find the max element in the array
	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];

	// Recall that if we want to pull out the ones, tens, or hundreds digits of
	// some number, we can use:
	//
	// 402 % 10 = 2         <- ones digit
	// 402 / 1 % 10 = 2     <- also for the ones digit
	// 402 / 10 % 10 = 0    <- tens digit
	// 402 / 100 % 10 = 4   <- hundreds digit

	// loop for each digit in the max integer
	for (pow = 1; max / pow > 0; pow *= 10)
	{
		// place into buckets
		for (i = 0; i < n; i++)
		{
		    enqueue(buckets[ array[i] / pow % 10 ], array[i]);
		}

		// pull out of buckets and into the original array
		for (i = j = 0; i < 10; i++)
			while (!isEmpty(buckets[i]))
			{
			    array[j++] = dequeue(buckets[i]);
			}

	}

	// clean up after yourself
	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

// Print an array of n integers, space-separated, followed by two newline chars.
void printArray(int *array, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');

	printf("\n");
}

int main(void)
{
	// Note: Since LENGTH is #defined, we don't need to do this dynamically...
	int i, *array = malloc(sizeof(int) * LENGTH);

	// Seed the random number generator.
	srand(time(NULL));

	// Populate our array with random numbers on the range [0, 99].
	for (i = 0; i < LENGTH; i++)
		array[i] = rand() % 100;

	// Print the unsorted array.
	printf("Unsorted array:\n");
	printArray(array, LENGTH);

	// Sort the array.
	RadixSort(array, LENGTH);

	// Print the sorted array.
	printf("Sorted array:\n");
	printArray(array, LENGTH);

	return 0;
}
