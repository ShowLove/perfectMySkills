#include <stdio.h>
#include <stdlib.h>

/*****************************************************************
LOCAL FUNCTIONS*/
void arraysAndPointers();
void doublePointers();
void dynamicMemory();
void pointerArithmetic();

/****************************************************************
*DEFINES*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int 		uint32;
typedef unsigned long uint64;

void panic(char *s)
{
		fprintf(stderr, "%s", s);
		exit(1);
}

int main(void)
{
		int pointerFunction = 0;

		printf("sizeof unsinged:char uint8(%lu) ,short uint16(%lu),int uint32(%lu), long uint64(%lu) bytes\n",
									 sizeof(uint8), sizeof(uint16), sizeof(uint32), sizeof(uint64) );

		printf("what version of pointers do you wish to see? \n");
		printf("\tarrays and pointers = 0, double pointers = 1, dynamic mem = 2 :");
		printf("\tpointer arithmetic = 3 :");
		printf("\nEnter pointer function value: "); scanf("%d", &pointerFunction);
		printf("\n\n");

		switch(pointerFunction)
		{
				case 0:
						arraysAndPointers();
						break;
				case 1:
						doublePointers();
						break;
				case 2:
						dynamicMemory();
						break;
				case 3:
					pointerArithmetic();
					break;

				default:
						arraysAndPointers();
		}

		return 0;
}


void arraysAndPointers()
{
int i, a[5];

printf("int arrays\n");

for (i = 0; i < 5; i++)
a[i] = i + 1;

// An integer takes up 32 bits (4 bytes) in C, so the address of each
// integer in an array is greater than the previous index's address by 4.
//
// Note that, in C, arrays are always contiguous blocks in memory.
//
// 0x10 0x14 0x18 0x1c 0x20
// +------+------+------+------+------+
// | 1 | 2 | 3 | 4 | 5 |
// +------+------+------+------+------+
// a[0] a[1] a[2] a[3] a[4]

// No surprises here...
for (i = 0; i < 5; i++)
printf("a[%d] = %d ,", i, a[i]); 
(i > 3)? printf("a[%d] = %d\n", i, a[i]): printf("a[%d] = %d ,", i, a[i]); 



// Let's take a look at those memory addresses!
for (i = 0; i < 5; i++)
printf("&a[%d] is %p\n", i, &a[i]);

// But, what is a itself (without an index)? This line yields a compiler
// warning and the output isn't "1", so we can infer that a is not
// synonymous with a[0].
printf("what happens when we print a with d? I get a warning\n");
//printf("%d\n", a);

// This is the answer. a is treated as an address (a pointer!) in C.
// This is the base address for the array, which is also &a[0].
printf("what happens when we print a with p?\n");
printf("%p\n", a);

if (&a[0] == a)
printf("Yes, they're equal! &a[0] == a\n");


//Now what happens when we change the type from int(32) to uint64?
printf("\nuint64 type\n");
uint64 b[5], j;

//fill the array
for(j=0; j<5; j++)
		b[j] = j+1;

//print the addresses of b[]
for(j = 0; j < 5; j++)
		printf("&b[%lu] = %p \n", j, &b[j] );

printf("notice the addresses jump 8 instead of 4 now\n");
	
}

/*******************************************************************
* experiment with double pointers
*/
void doublePointers()
{
		int i, j, num_students, num_exams, **exam_scores = NULL, sum;

		printf("How many students are in the class? ");
		scanf("%d", &num_students);

		printf("How many exams have they taken? ");
		scanf("%d", &num_exams);

		// Each student gets their own array. (Recall that (int *) can point to the
		// begining of an array of integers. We'll want a bunch of those.)
		printf("we declared int **exam_scores (double array); exam_scores[row][col] row = student, col = test\n");
		printf("to malloc the row: exam_scores = malloc(sizeof(int *) * num_students); int* times num_students points to each row  \n");
		printf("to malloc the test for each individual student: exam_scores[i] = malloc(sizeof(int) * num_exams) \n");

		exam_scores = malloc(sizeof(int *) * num_students);

		if (exam_scores == NULL)
				panic("ERROR: out of memory in main()\n");

		// Each student gets an array.
		for (i = 0; i < num_students; i++)
		{
				exam_scores[i] = malloc(sizeof(int) * num_exams);

				if (exam_scores[i] == NULL)
						panic("ERROR: out of memory in main()\n");
		}

		for (i = 0; i < num_students; i++)
		{
				// Re-initialize sum of exam scores for each student.
				sum = 0;

				printf("\n");

				// Input exam scores
				(i == 0)? printf("Syntax is a acutally a double array a[i][j]\n"): printf("");
				for (j = 0; j < num_exams; j++)
				{
						printf("What did Student #%d earn on Exam #%d: ", i + 1, j + 1);
						scanf("%d", &exam_scores[i][j]);
				}

				// Let's make sure everything got in there.
				for (j = 0; j < num_exams; j++)
				{
						printf("Student #%d earned %d on Exam #%d.\n", i + 1,
						exam_scores[i][j], j + 1);

						sum += exam_scores[i][j];
				}

				if (num_exams != 0)
						printf("Student #%d's exam average: %.2f\n", i + 1,
								(float)sum/(float)num_exams);
		}

		// Free this before you free(exam_scores), because once exam_scores is
		// freed, you shouldn't be accessing exam_scores[i]!
		printf("we free this by  {for: free(exam_scores[i]} then free(exam_scores)\n");
		for (i = 0; i < num_students; i++)
				free(exam_scores[i]);

		free(exam_scores);

		// Notice that we had (1 + num_students) calls to malloc() above, as well
		// as (1 + num_students) calls to free(). We cleaned everything up nicely.

		// CHECK YOUR UNDERSTANDING:
		// What happens if we free(exam_scores) twice in a row?
}


void dynamicMemory()
{

			int i, n, *ptr, sum;

		// Sometimes we don't know how big of an array we need until runtime.
		// Let's ask the user.
		printf("How many exams have been taken? ");
		scanf("%d", &n);

		// Now let's create an array of n integers at runtime. malloc() will do that
		// for us. It needs to know how big each element in the array is, as well as
		// how many elements we want to store. Then it finds a contiguous block of
		// memory that's that size, gives you the block's address, and lets you play
		// with it. Be sure to include stdlib.h if you want to use malloc().
		ptr = malloc(sizeof(int) * n);

		// Some compilers want you to typecast malloc()'s return value, like so:
		// ptr = (int *)malloc(sizeof(int) * n);

		// NOTE: A common pitfall is to do malloc(sizeof(n)) or some such thing.
		// Please master malloc() ASAP. You'll have to use it on your exams!

		// NOTE: calloc() does what malloc() does, except it initializes all values
		// to zero, and you call it a bit differently: calloc(n, sizeof(int))

		// If malloc() fails to find a block as big as you need, it returns NULL.
		// This is very uncommon, but we check just to be on the safe side.
		if (ptr == NULL)
				panic("ERROR: out of memory in main()\n");

		// Now, we can proceed as before.
		for (i = 0; i < n; i++)
		{
				printf("What did the student earn on Exam #%d? ", i + 1);
				scanf("%d", &ptr[i]);
		}

		// Let's make sure everything got in there.
		for (i = 0; i < n; i++)
		{
				printf("Student earned %d on Exam #%d.\n", ptr[i], i + 1);
				sum += ptr[i];
		}

		if (n != 0)
				printf("Student's exam average: %.2f\n", (float)sum/(float)n);


		// CHECK YOUR UNDERSTANDING:
		// What if you wanted a string (i.e., an array of chars)? How does the
		// malloc() statement look different from the one above? Assume we want to
		// store a string of 5 characters, like "hello".

}

void pointerArithmetic()
{
	int i, a[5], *ptr;

	// This makes sense, right? We saw that 'a' is a memory address (int *), and
	// we know that 'ptr' is designed to hold memory addresses.
	ptr = a;

	// We can now treat 'ptr' as a synonym for 'a'.
	for (i = 0; i < 5; i++)
	ptr[i] = i + 1;

	// Let's test out that theory by printing each a[i] now.
	for (i = 0; i < 5; i++)
	printf("a[%d] = %d\n", i, a[i]);

	// Now, if an address is always 32 or 64 bits (depending on your system
	// architecture), why don't we just have a generic "memory address" type?
	// Why do we need to declare (int *) or (char *) instead of just (pointer)?

	// What happens if we do this?
	printf("\n");
	printf(" ptr: %p\n", ptr);
	printf("++ptr: %p\n", ++ptr);

	// Let's reset ptr and see another example.
	ptr = a;

	// The same is true even if we print this as an integer using typecasting:
	printf("\n");
	printf(" ptr: %d\n", (int) ptr);
	printf("++ptr: %d\n", (int)++ptr);

	// This also holds if we try to jam an integer into our integer pointer.
	// (This will generate a compiler warning.)
	printf("\n");
	ptr = 42;
	++ptr;
	printf("42 + 1 = %d?!\n", (int)ptr);  

}
