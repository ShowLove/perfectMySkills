#include "linkedlist.h"

/******************************************************
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*******************************************************/

/*******************************************************
* Deletes One particular node
******************************************************/
node *deleteThisNode( node *root, node *prevNode )
{
	if( root->next == NULL )	//We are trying to delete the last node
	{
		prevNode->next = NULL;
		free( root );
		return NULL;
	}

	prevNode->next = root->next;

	printf("\nDeleted node %d\n", root->num);

	if( root != NULL )
		free(root);

	return prevNode->next;
}

/********************************
* Deletes all duplicates of a LL
******************************** 			TODO: BUG, if n element is dublicate of element (n-1)*/
node *delDuplicates( node *root )
{
	node *tmp = root;
	node *tmp2 = root;
	node *tmp2_prev = NULL;
	int data;

	while( tmp->next != NULL )
	{
		
		data = tmp->num;
		tmp2 = tmp;

		while( tmp2->next != NULL )
		{
			tmp2 = tmp2->next;

			if( tmp2->num == data )
			{
				tmp2 =	deleteThisNode( tmp2, tmp2_prev );
				if( tmp2 == NULL)
					break;
			}
			//update the nodes
			tmp2_prev = tmp2;
		}

		if( tmp2 == NULL )
			break;

		//Check if last element is a duplicate
		if( tmp2->num == data )
		{
			tmp2 =	deleteThisNode( tmp2, tmp2_prev );
		}

		
		tmp2_prev = tmp2;
		tmp = tmp->next;	
	}

	return root;

}


int main()
{
	node *root = NULL;
	int choice = 0;

	while( choice != -1 )
	{
		root = choose(root);

		printf("\nEnd? \t enter -1 to quit --> ");
		scanf("%d", &choice);
	}

  root =	delDuplicates( root );

	root = choose(root);

	printf("\nAbout to Deleted node\n");

	freeNodes(root);
}