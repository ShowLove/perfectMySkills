#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct node
{
	int num;	

	struct node *next;

}node;

/*******************************************************
*	Allocates space for a new node 
* This can be used to initiate or to append to ->next
*******************************************************/
node *initNode( int num )
{
	node *newNode = malloc( sizeof(struct node) );
	newNode->next = NULL;
	newNode->num = num;

	return newNode;
}

/*******************************************************
* Inserts node at the end of the linked list	
*******************************************************/
node *insertNodeEnd( int num, node *root )
{
	if( root == NULL )
		return NULL;		

	node *tmp;
	tmp = root;

	while( tmp->next != NULL ) 
		tmp = tmp->next;

	tmp->next = initNode( num );

	//Im return this so i dont have to itterate the entire list
	return tmp->next;
}

/*******************************************************
*	Prints the list: Currently prints the num field of the list
*******************************************************/
void printList( node *root )
{

	if( root == NULL )
	{
		printf("Can't print NULL list!\n");
		return;
	}

	if( root->next == NULL )
	{
		printf(" Num(%d), ", root->num );
		return;
	}

	while( root->next != NULL )
	{
		printf(" Num(%d), ", root->num );
		root = root->next;
	}

	//Print last node
	printf(" Num(%d), ", root->num);
}

/*******************************************************
*	 Calls insertNodeEnd() multiple times to insert nodes
*  at the end of the linked list
*  currently inserts at end of LL num field from 1--> end
*******************************************************/
node *insertMultipleNodes( node *root, int numNodes )
{
	if( root == NULL ) 
		return NULL;

	srand(time(NULL));

	node *tmp = root;
	
	for(int i = 1; i <= numNodes; i++)
	{
		tmp  = insertNodeEnd( rand()%100, tmp );
		if( tmp == NULL )
		{
			printf("Something went wrong!");
			break;
		}	
	}

	//could return tmp if I wanted to keep track of end of LL
	return root;
}

node *choose( node *root)
{
	int choice;
	int insertNum;
	int multNodes;
	srand(time(NULL));
	printf("What do you want to do?\n");
	printf("choice:\n \t\t 0 = initialize,\n \t\t 1 = insert single node at end of LL\n \t\t 2 = insert multiple random nodes at end of LL\n");
	printf("\t\t 3 = print\n");
	printf("Enter choice here: "); scanf("%d", &choice);



	switch( choice )
	{
		case 0:
			//Initialize
			if( root == NULL )
			{
				printf("Successfully initialized node\n\n");
				return initNode( rand()%100 );
			}
			else 
				printf(" You already initialized this node!\n\n");
			break;
		case 1:
			//insert single node at end of LL
			printf("What number do you want to insert? insert: ");
			scanf("%d", &insertNum);	
			insertNodeEnd(insertNum, root);
			printf("Successfully inserted node at end\n\n");
			break;
		case 2:
			//insert multiple rando nodes at end of LL
			printf("How many nodes do you want ot insert? numNodes: ");
			scanf("%d", &multNodes);
			insertMultipleNodes( root, multNodes );
			printf("Successfully inserted %d nodes\n\n", multNodes);
			break;
		case 3:
			//Print the nodes
			printList( root );
			printf("\n");
			break;

		default:
			printf("Invalid Entry\n\n");
	}
	return root;
}

/**********************
* main
**********************/
int main()
{
	node *root = NULL;
	int choice = 0;

	while( choice != -1 )
	{
		root = choose(root);

		printf("Enter any number to continue or -1 to quit --> ");
		scanf("%d", &choice);
	}

	free( root );
}
