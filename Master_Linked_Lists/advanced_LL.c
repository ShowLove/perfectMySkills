#include <stdio.h>
#include <stdlib.h>

struct node
{
        int item;
        struct node *next;
};

//Prompt user to know what value he wants to input with the node
struct node* promptForNodeInsertEnd_LL(struct node *root);
struct node* promptForNodeInsertFront_LL(struct node *root);
struct node* promptForNodeInsertMiddle_LL(struct node *root);
//Add a value to to initialize, front, middle, or end
struct node* addNodes(struct node *root, int nodes);  
struct node* addToFront(struct node *root, int value);
struct node* addToMiddle(struct node *root, int value);
struct node* addToEnd(struct node *root, int value);
void printNodes(struct node *conductor);

int main()
{

    int nodes;

    struct node *root; /* This will be the unchanging first node */
        							 /* This will point to each node as it traverses the list */
    struct node *conductor;

    printf("How many nodes do you desire? >");
    scanf("%d", &nodes);

    //create and print initial set of nods
    root = addNodes(root, nodes);
    conductor = root;
		printf("This is our initial Linked List\n");
    printNodes(conductor);

    printf("\n\n\nInput a node to the end of our Linked List\n");
    root = promptForNodeInsertEnd_LL(root);
    conductor = root;
    printNodes(conductor);

		printf("Input a node to the front of our List\n");
    root = promptForNodeInsertFront_LL(root);
    conductor = root;
    printNodes(conductor);

		printf("Input a node to the middle of our list");
    root = promptForNodeInsertMiddle_LL(root);
		if(root == NULL)
			printf("We had an error in inserting middle\n");
		else{
			conductor = root;
			printNodes(conductor);
		}

getchar();
}

/*****************************************************
* This function initializes a new LL with how ever 
* many "nodes" you want
*****************************************************/
struct node* addNodes(struct node *root, int nodes) {

    struct node *conductor;
		int x;
    //allocating space for the root
    root = malloc(sizeof(struct node));
    conductor = root;
		//initialize condutor
    root->next = 0;
    root->item = 777;
	
		//Create desired amount of nodes
    for(x = 0; x < nodes; ++x)
    {
                /* Creates a node at the end of the list */
                conductor->next = malloc( sizeof(struct node) );

                /*checking that memory is allocated*/
                if ( conductor == 0 )
                {
                  printf( "Out of memory" );
                  return 0;
                }

                conductor = conductor->next;
                conductor->item = x+1;
    }

    //marking the last as NULL
    conductor->next = 0;

    //do this immidiately after function
    //conductor points to root again
    //conductor = root;

    return root;

}

void printNodes(struct node *conductor) {
    //must have conductor = root;  before executing this function

    //print the list
    if ( conductor != 0 )  /* Makes sure there is a place to start */
    {
        while(conductor->next != 0)
        {
            printf(" [%d]-> ",conductor->item);
            conductor = conductor->next;
        }
    }
}

/**********************************************************
* Prompts the user asking what number he wants to insert at 
* end of Linked List
**********************************************************/
struct node* promptForNodeInsertEnd_LL(struct node *root){
	//must create addToEnd function before using this function
	int number = 0;
	// User enters data for new node (or -1 to exit)
	while(number!= -1) {
		// Get the next number.
		printf("enter data you want to insert at end of node: ");
		scanf("%d", &number);
		// Add to linked list if it's not -1.
		if (number !=-1)
		root = addToEnd(root, number);

	}
	return root;
}

/*******************************************************
*Adds a new value and node to the end of the Linked List
*******************************************************/
struct node* addToEnd(struct node *root, int value) {
	//keep in mind the begining of our list is root
	// Make helper pointer and store head of list into it
	struct node *help_ptr = root;   //address of list in contents of helpptr
	// Create the new node and put data (from argument) into it
	struct node * pNew = (struct node *)malloc(sizeof(struct node)); //store a pointer in a pointer
	pNew->item = value; //put argument in new node
	pNew->next = NULL;
	// If list is empty, pNew becomes the first node
	if (root == NULL)
	return pNew;
	// Else, traverse the list to arrive a the last node
	while (help_ptr->next != NULL)
		help_ptr = help_ptr->next;  //notice there are no bracets here
																//help_ptr finishes on last node
																//before the next code runs
	// Make the last node point to the to-be-inserted node, i.e.
	// put the address of new node into the last node’s “next”
	help_ptr->next = pNew;
	// Return a pointer to the modified list
	return root;            //I dont see the point of returning this pointer
}

/*******************************************************
*Adds a new value and node to the front of the Linked List
*******************************************************/
struct node* addToFront(struct node *root, int value) {
	// Create the new node and put data (from argument) into it
	struct node * pNew = (struct node *) malloc(sizeof(struct node));
	pNew->item = value;
	pNew->next = NULL;
	// If the original list is empty, set the original head
	// pointer to point to the new node.
	if(root == NULL)
		root = pNew;
	// Else, list is currently pointing to a non-empty list.
	else 
	{
		// Point new node to wherever Head pointer pointed to.
		pNew->next = root;
		// Now make Head pointer point to the new node.
		root = pNew;
	}

	return root;
}

/**********************************************************
* Prompts the user asking what number he wants to insert at 
* front of Linked List
**********************************************************/
struct node* promptForNodeInsertFront_LL(struct node *root){
	int number = 0;
	// User enters data for new node (or -1 to exit)
	while(number!= -1) {
		// Get the next number.
		printf("Enter the value you want to insert into a new beginning node: >");
		scanf("%d", &number);
		// Add to linked list if it's not -1.
		if (number !=-1)
		root = addToFront(root, number);
	}

	return root;
}

/**********************************************************
* Prompts the user asking what number he wants to insert at 
* middle of Linked List
**********************************************************/
struct node* promptForNodeInsertMiddle_LL(struct node *root){
	int number = 0;
	while(number!= -1) {
		// Get the next number.
		printf("you are now inserting data: >");
		scanf("%d", &number);
		// Add to linked list if it's not -1.
		if (number !=-1)
		root = addToMiddle(root, number);
	}

	return root;
}

/*******************************************************
*Adds a new value and node to the front of the Linked List
*******************************************************/
struct node* addToMiddle(struct node *root, int value){
	// Make helper pointer and store head of list into it
	struct node *help_ptr = root;
	// Create the new node and put data (from argument) into it
	struct node * pNew = (struct node *)malloc(sizeof(struct node));
	pNew->item = value;
	pNew->next = NULL;
	// Insertion into an empty list
	// OR Insertion at the front of a non-empty list
	if (root == NULL || root->item > value) {
		pNew->next = root;
		root = pNew;
		return root;
	}
	return NULL;
}

