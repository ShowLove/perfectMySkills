// Sean Szumlanski (COP 3502, Summer 2013)
// linked_lists.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function is a bit tongue-in-cheek. Include stdlib.h for exit().
void panic(char *s)
{
	fprintf(stderr, "%s", s);
	exit(1);
}

typedef struct node
{
	int data;
	struct node *next;
} node;

// Create a new node and initialize all fields.
node *createNode(int data)
{
	node *ptr = malloc(sizeof(node));

	if (ptr == NULL)
		panic("ERROR: out of memory in createNode()\n");

	ptr->data = data;
	ptr->next = NULL;

	return ptr;
}

// Insert a new node at the end of the linked list.
node *insert(node *head, int data)
{
	node *ptr = NULL;

	// If the list is empty, just create a new node and return.
	if (head == NULL)
		return createNode(data);

	// Find the last node in the list.
	for (ptr = head; ptr->next != NULL; ptr = ptr->next)
		;

	// Now 'ptr' is pointing to the last node. Set it up so its 'next' field
	// points to the new node we're creating.
	ptr->next = createNode(data);

	// Return the head of the list so we preserve 'head' in main().
	return head;
}

// Print nodes in the list sequentially.
void printList(node *head)
{
	node *ptr = NULL;

	if (head == NULL)
		printf("(empty)\n");

	for (ptr = head; ptr != NULL; ptr = ptr->next)
		printf("%d%c", ptr->data, (ptr->next == NULL) ? '\n' : ' ');
}

// Clean up all dynamically allocated memory.
node *destroyList(node *head)
{
	node *temp = NULL;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	return NULL;
}

int main(void)
{
	int i, r;

	// Initialize to NULL, or insert() won't work.
	node *head = NULL;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		// Populate the linked list with random ints from 1..100 (inclusive).
		r = rand() % 100 + 1;
		printf("Inserting: %d\n", r);
		head = insert(head, r);
	}

	printf("List contents: ");
	printList(head);

	// Notice that the destroyList() line cleans up memory AND sets our 'head'
	// pointer to NULL again.
	printf("Destroying list.\n");
	head = destroyList(head);

	printf("List contents: ");
	printList(head);

	return 0;
}