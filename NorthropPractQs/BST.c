// BST.c
// Adapted from class on June 25, 2013

// In this program, we implement binary search tree (BST) insertion. We also
// have functions to do in-order, pre-order, and post-order traversals of
// binary trees, and there are a few recursive function exercises.


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;

node *createNode(int data)
{
	node *ptr = malloc(sizeof(node));
	
	ptr->data = data;
	ptr->left = ptr->right = NULL;
	
	return ptr;
}

node *BST_insert(node *root, int data)
{
	// insertion into an empty tree
	if (root == NULL)
		return createNode(data);
	
	// insertion into left subtree
	else if (data < root->data)
		root->left = BST_insert(root->left, data);
	
	// insertion into right subtree
	else if (data > root->data)
		root->right = BST_insert(root->right, data);
	
	// disallow duplicate values in my BST
	else
		;
	
	return root;
}

void InOrder(node *root)
{
	if (root == NULL)
		return;
	
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PreOrder(node *root)
{
	if (root == NULL)
		return;
	
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void PostOrder(node *root)
{
	if (root == NULL)
		return;
	
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// a recursive function that returns the height of the tree
int height(node *root)
{
	if (root == NULL)
		return -1;

	return 1 + max(height(root->left), height(root->right));
}

// a recursive function to find the max element in a binary tree
int findMax(node *root)
{
	int a;
	
	if (root == NULL)
		return INT_MIN;
	
	a = max(findMax(root->left), findMax(root->right));
	return max(a, root->data);
}

// a recursive function to find the max element in a BST (binary search tree)
int BST_findMax(node *root)
{
	// How would this function differ from the findMax() function above?
}

int main(void)
{
	int i, r;
	node *root = NULL;
	
	srand(time(NULL));
	
	for (i = 0; i < 10; i++)
	{
		printf("Inserting %d...\n", r = rand() % 25 + 1);
		root = BST_insert(root, r);
	}
	
	printf("Inorder traversal:\n");
	InOrder(root);
	printf("\n");
	
	return 0;
}