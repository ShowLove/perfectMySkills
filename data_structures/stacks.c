// stacks.c
// Adapted from class on June 13, 2013

// An array-based implementation of stacks with a command-based interface and
// a function that prints a little diagram of the stack's contents.


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Stack
{
	int *elements;
	int top;
	int max;
} Stack;

// Create a new stack that can hold up to n integers.
Stack *createStack(int n)
{
	Stack *s = malloc(sizeof(Stack));
	
	s->elements = malloc(sizeof(int) * n);
	s->top = 0;
	s->max = n;
	
	return s;
}

// Destroy the stack.
Stack *destroyStack(Stack *s)
{
	if (s == NULL)
		return NULL;
	
	free(s->elements);
	free(s);
	
	return NULL;
}

// Fancy function to print the stack.
void printStack(Stack *s)
{
	int i; char str[32];

	printf("\n");

	if (s == NULL)
	{
		printf("   (no stack)\n");
		return;
	}

	if (s->top == 0)
	{
		printf("   (stack is empty)\n");
		return;
	}

	for (i = s->top - 1; i >= 0; i--)
	{
		printf("   |  %-4d  |%s\n", s->elements[i],
		       (i == s->top - 1) ? " <-- top" : "");
		printf("   +--------+\n");
	}
}

// Returns 1 if the stack is empty, 0 otherwise. (Can you see how this is
// working?)
int isEmpty(Stack *s)
{
	return !s->top;
}

// Returns 1 if the stack is full, 0 otherwise.
int isFull(Stack *s)
{
	return (s->top == s->max);
}

// Pushes an element onto the top of the stack, if there's room.
void push(Stack *s, int n)
{
	if (s == NULL)
		return;
	
	if (isFull(s))
	{
		printf("\n  -> error: stack is full\n\n");
		return;
	}
	
	s->elements[s->top++] = n;
	
	// Or, you could use this:
	//s->elements[s->top] = n;
	//++s->top;
}

// Returns the value element on the top of the stack without popping it. Returns
// INT_MIN (defined in limits.h) if the stack is empty.
int peek(Stack *s)
{
	if (s == NULL || s->top == 0)
		return INT_MIN;
	
	return s->elements[s->top - 1];
}

// Pops an element off the stack and returns its value. Returns INT_MIN (defined
// in limits.h) if the stack is empty.
int pop(Stack *s)
{
	if (s == NULL || s->top == 0)
		return INT_MIN;
	
	return s->elements[--s->top];
}

// main() implements a command-based interface that lets you push(), pop(), and
// peek(), all while showing a little diagram that represents the state of the
// stack. You can create a new stack at any time, and you get to set the
// maximum capacity of the stack(s) you create.
int main(void)
{
	char buffer[128]; int n;
	Stack *myStack = NULL;

	printf("\n");
	printf("Stack ops:\n");
	printf("\n");
	printf("  new <n>    -- create a new stack with capacity set to <n>\n");
	printf("  destroy    -- completely destroy the current stack\n");
	printf("  push <n>   -- push <n> onto the stack\n");
	printf("  pop        -- pops the top element off the stack\n");
	printf("  pop        -- prints the stack's top element without removing it\n");
	printf("  isempty    -- indicates whether the stack is empty\n");
	printf("  isfull     -- indicates whether the stack is full\n");
	printf("\n");

	do
	{
		printf("Enter a command ('?' for help, or 'exit' to quit).\n");
		printf("%% ");

		scanf("%s", buffer);

		if (strcmp(buffer, "?") == 0)
		{
			printf("\n");
			printf("Stack ops:\n");
			printf("\n");
			printf("  new <n>    -- create a new stack with capacity set to <n>\n");
			printf("  destroy    -- completely destroy the current stack\n");
			printf("  push <n>   -- push <n> onto the stack\n");
			printf("  pop        -- pops the top element off the stack\n");
			printf("  pop        -- prints the stack's top element without removing it\n");
			printf("  isempty    -- indicates whether the stack is empty\n");
			printf("  isfull     -- indicates whether the stack is full\n");
		}
		
		else if (strcmp(buffer, "new") == 0)
		{
			if (myStack != NULL)
				destroyStack(myStack);

			scanf("%d", &n);
			myStack = createStack(n);
		}

		else if (strcmp(buffer, "destroy") == 0)
		{
			if (myStack != NULL)
				myStack = destroyStack(myStack);
		}

		else if (strcmp(buffer, "push") == 0)
		{
			scanf("%d", &n);
			push(myStack, n);
		}

		else if (strcmp(buffer, "pop") == 0)
		{
			n = pop(myStack);

			if (n != INT_MIN)
				printf("\n   -> popped %d\n", n);
		}

		else if (strcmp(buffer, "peek") == 0 || strcmp(buffer, "top") == 0)
		{
			n = peek(myStack);

			if (n != INT_MIN)
				printf("\n   -> peek: %d\n", n);
		}

		else if (strcmp(buffer, "empty") == 0)
		{
			if (isEmpty(myStack))
				printf("\n   -> stack is empty\n");
			else
				printf("\n   -> stack is not empty\n");
		}

		else if (strcmp(buffer, "full") == 0)
		{
			if (isFull(myStack))
				printf("\n   -> stack is full\n");
			else
				printf("\n   -> stack is not full\n");
		}

		else if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		if (myStack != NULL && !isEmpty(myStack))
			printStack(myStack);

		printf("\n");

	} while (1);
	
	destroyStack(myStack);
}
