// linked-lists.c
// Adapted from class on June 11, 2013


#include <stdio.h>
#include <stdlib.h>

/*

 Topic: Linked Lists


Some problems with arrays:

- Fixed sized

- Insertion and deletion from the beginning of the array is expensive

- Suppose we have 1000 elements and we want to delete the 10th one.
  This, too, is an O(n) operation.

- Memory bloat (unused space in the array)


ArrayLists ameliorate these problems to some extent:

- They expand dynamically if the array gets full

- trimArrayList() eliminates excess memory bloat


Accessing an arbitrary element of an array is an O(1) operation. Arrays give
us direct access to elements.


A linked list is just a data structure where the length of the list is dynamic
and nodes are located all over the place in memory.

 
Pros:

 - Insertion and deletion at arbitrary positions in the list doesn't require us
	to shift elements all over the place. Thus, the operations are pretty cheap
   (that is, after we find the element we're looking for!).

 - Length the of the list can change dynamically.

Cons:

 - We no longer have direct access to each element.
 
 - Takes up more memory than an array; we have to store lots of addresses!
 
 
We briefly discussed the following exotic variations on linked lists at the end
of class:
 
 - Doubly linked lists (which maintain 'next' and 'prev' pointers for mobility
   in both directions. (Note that this has some extra memory overhead!)
 
 - Circularly linked lists (where the tail points to the head node)
 
 - Circular doubly linked lists (combination of the above two ideas)
 
*/


// Basic linked list node struct; contains 'data' and 'next' pointer.
// What happens if we type "node *next" instead of "struct node *next"?
typedef struct node
{
	int data;
	struct node *next;
} node;

// Linked list node for doubly linked lists.
typedef struct dl_node
{
	int data;
	struct node *next;
	struct node *prev;
} dl_node;

// We saw that we can use a node pointer (node *) to store the head of our
// linked list, but sometimes we want to track the head AND tail, and it's just
// super convenient to package them up in a struct like this.
typedef struct linked_list
{
	node *head;
	node *tail;
} linked_list;

// Allocate a new node. Initialize its fields. Return the pointer.
// We call this from our insertion functions.
node *createNode(int data)
{
	node *ptr = malloc(sizeof(node));

	ptr->data = data;
	ptr->next = NULL;

	return ptr;
}

// Insert into the end of the linked list. (What is the order (Big-Oh) of
// this function?)
node *insertNode(node *head, int data)
{
	node *helper;

	// If the head is NULL, we create a node and return head. We want to ship the
	// address of the new head node back to main() (or wherever we call this
	// function from) so we can refer to the list from there.
	if (head == NULL)
	{
		head = createNode(data);
		return head;
	}

	// If there are elements in the list, skip forward to the last (non-NULL)
	// element.
	for (helper = head; helper->next != NULL; helper = helper->next)
		;

	// 'helper' is pointing to the last node in the list now. So, to add a node
	// to the end, set helper->next to the new node we're creating.
	helper->next = createNode(data);
	return head;
}

// This is a modification that allows us to insert at the beginning of the
// linked list. What is the runtime here?
node *frontInsert(node *head, int data)
{
	node *ptr = createNode(data);

	// The new node is the first one in the list. So, its ->next pointer is
	// the head of the old list. Notice that this code works even if 'head'
	// is NULL (i.e., adding a new node to the front of an empty list).
	ptr->next = head;

	return ptr;
}

// We saw that we can improve runtime of end-of-list insertion by keeping track
// of a tail pointer. The problem here is that sometimes the function returns
// the head pointer, and sometimes it returns the tail. We rely on the person
// calling the function to capture the return value and store it in the correct
// place (head or tail).
node *insertNodeWithTail(node *head, node *tail, int data)
{	
	if (head == NULL)
	{
		// If inserting into an empty list, return the head of the list.
		return createNode(data);
	}
	else
	{
		// If inserting into a non-empty list, return the tail of the list.
		tail->next = createNode(data);
		return tail->next;
	}
}

// Modification of our insertion functions to work with the linked_list struct.
// Updates head and tail. The nice thing is, we don't have to return any
// addresses back to main() (or whatever the calling function is), so we don't
// have to capture the function's return value, as with:
//
//    head = insertNode(...);
//
// Instead, we just call the function without need for assignment, like so:
//
//    insertToListStruct(...);
//
void insertToListStruct(linked_list *list, int data)
{
	if (list->head == NULL)
	{
		// If inserting into the empty list, both the head and tail are changing.
		list->head = list->tail = createNode(data);
	}
	else
	{
		// If inserting into a non-empty list, the head doesn't change. Only the
		// tail changes. So, insert the new node and move the tail pointer forward.
		list->tail->next = createNode(data);
		list->tail = list->tail->next;
	}
}

// Simple function to print the contents of a linked list.
void printList(node *head)
{	
	for ( ; head != NULL; head = head->next)
	{
		printf("%d\n", head->data);
	}
}

int main(void)
{
	int i;

	// Head and tail of linked list
	node *head = NULL;
	node *tail = NULL;

	// Misc. linked lists
	node *head2 = NULL;
	node *head3 = NULL;

	// Helper pointer. We'll use this to loop through our lists.
	node *helper = NULL;

	// Another helper pointer. Thanks, Andrew. :-)
	node *whateverYouWantToStoreItTo = NULL;

	// A linked list struct that stores the head *and* tail of a list.
	linked_list myList;
	myList.head = myList.tail = NULL;

	// Let's call our various insertion functions and see what happens.
	for (i = 23; i < 27; i++)
	{
		// Insert into linked list.
		if (head == NULL)
			head = tail = insertNodeWithTail(head, tail, i);
		else
			tail = insertNodeWithTail(head, tail, i);

		// Insert at end of list.
		head2 = insertNode(head2, i);
		
		// Insert at front of list.
		head3 = frontInsert(head3, i);

		// Insert into linked_list struct.
		insertToListStruct(&myList, i);
	}

	// We started with this rather cumbersome way of printing elements in a list:
	printf("The first element in the list is: %d\n",
	       head->data);
	
	whateverYouWantToStoreItTo = head->next;
	
	printf("The second element in the list is: %d\n",
	       whateverYouWantToStoreItTo->data);
	
	whateverYouWantToStoreItTo = whateverYouWantToStoreItTo->next;
	
	printf("The third element in the list is: %d\n",
	       whateverYouWantToStoreItTo->data);

	// Not only is the above a rather cumbersome idea, but it will segfault if
	// we inadvertently dereference a NULL pointer. It's not safe at all.
	
	// Let's print our various linked lists:
	printList(head);
	printf("-------\n");

	printList(head2);
	printf("-------\n");

	printList(head3);
	printf("-------\n");
	
	// Here, we saw that we can re-use our printList() function with the
	// linked_list struct. We just have to pass in its 'head' member!
	// Why do we use the dot operator (.) instead of the arrow (->) here?
	printList(myList.head);
	printf("-------\n");
	
	// NOTE: A Patently Bad Idea for Printing the Second Element
	//       The following causes us to lose track of our list's head!
	head = head->next;
	printf("%d\n", head->data);
	
	return 0;
}