#include <stdio.h>
#include <stdlib.h>

void findNumAlefB();

//THIS WILL NOT COMPILE!  

int main()
{
	findNumAlefB();
}

/*
	finds int representation of each letter of the alphabet
*/
void findNumAlefB()
{
	int a = (int) 'a';
	int A = (int) 'A';	
	int null = (int) '\0'; //First letter of ascii
	int tilde = (int) '~';  //Second to last letter in ascii DEL is last

	//26 letters in alphabet
	printf("lower case int rep of ascii a-z %d-%d \n", a, (a+26-1) );
	printf("Upper case int rep of ascii a-z %d-%d \n", A, (A+26-1) );
	printf("int rep of chars range from %d-%d in ascii \n", null, tilde+1 ); //+1 for del

	int num = 7;
	printf("%d,7%d,.7%d,:%7d,%.7d,%d", num, num, num, num, num, num );
	printf("\n %d num++", num++);
	printf("%d<--- 8  now  --num %d",num, --num);
	
}

//Zero out array        int count[256];
                memset(count,0,256*sizeof(int));

//Pointers
-print pointers:     %p

//Double Pointers
//-Declaring double pointers:

int **exam_scores;
exam_scores = malloc( sizeof( (int *) * num_students ); //allocate rows
        if (exam_scores == NULL)
                panic("ERROR: out of memory in main()\n");
        for (i = 0; i < num_students; i++) {        //allocate collums for each row
                exam_scores[i] = malloc(sizeof(int) * num_exams);
                if (exam_scores[i] == NULL)
                        panic("ERROR: out of memory in main()\n");

//-Using double pointers:

    exam_scores[i][j];  //Now use as a double array
        printf("we free this by  {for: free(exam_scores[i]} then free(exam_scores)\n");

//-Freeing double pointers:
        for (i = 0; i < num_students; i++)
                free(exam_scores[i]);
        free(exam_scores);

//Realoc and Malloc

/* -malloc memory: */       str = realloc(str, size*sizeof(char)); //for double sizeof(char *)
/*- re-allocate memory:*/     str = realloc(str, size*sizeof(char));  //str: begining of pointer

//Print Strings        printf("The reversed string is %s\n", myString );
        
//Ascii
	lower case int rep of ascii a-z 97-122
	Upper case int rep of ascii A-Z 65-90
	int rep of chars range from 0-127 in ascii these are regular 
	128-255 are weird extended characters

int a = (int) ‘a’;

//Print %d
                printf(“:%7d,%.7d”, num, num ); =  “:       7,0000007”

// ++,-- (before/after)        int num = 7;    printf("\n %d num++", num++);
printf("%d<--- 8  now  --num %d",num, --num); 
= “7 num++8<--- 8  now  --num 7”

//Bit Manipulation        1. 0110 + 0119 is equivalent to 0110 * 2, which is equivalent to 
	shifting 0110 left by 1.
	2. (0100 * 0011) Since 0100 equals 4, we are just multiplying 0011 by 4. Multiplying by 2 just shifts a number by n. We shift 0011 left by 2 to get 1100.
	3. An operation like x & (~0 « n) clears the n rightmost bits of x. The value ~0 is simply a sequence of 1 s, so by shifting it left by n, we have a bunch of ones followed by n zeros. By doing an AND with x, we clear the rightmost n bits of x.


//Math             
	-Prime                every positive integer can be decomposed into a product of
	primes. For example:
	84 = 22 * 31 * 5e * 7i * 118 * 13e * 1?8 *
	-finding a prime        The Sieve of Eratosthenes non-prime numbers are divisible by 
	a prime number. We start with a list of all the numbers up through some value max. 
	First, we cross off all numbers divisible by 2. Then, we look for the next prime 
	(the next non-crossed off number) and cross off all numbers divisible by it. 
	By crossing off all numbers divisible by 2,3, 5,7,11, and so on, we wind up with a 
	list of prime numbers from 2 through max.

//Hash
-Horner’s Rule        for(i = 0; i < strlen(key); i++)
/*hval = 0;*/ 			hval = (hval*37 + key[i]) % table_size

//Random values
srand(time(NULL));
//Populate random values in the array from [0,99]
for(i = 0; i < LENGTH; i++)
    array[i] = rand()%100;

//c type lengths in bytes
sizeof unsinged:char uint8(1) ,short uint16(2),int uint32(4), long uint64(8) bytes

//Pointers and Arrays
-first address:            &a[0] == a;
-array size matters:        int[size] (4bytes per space), long[size] 8 bytes per space










