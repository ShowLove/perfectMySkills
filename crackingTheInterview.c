#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Question 1.1
/*Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?*/
void q1_1();
//Question 1.2
/*Implement a function void reverse(char* str) in C or C++ which reverses a null- terminated string.*/
void q1_2(char* str);


//HELPER FUNCTIONS//
//Q1_1
int bubbleSortChars(char *array, int n); //best n, Worst n^2 
void charArraySwap( char *array, int index);
char* promptForString(); //Not used, i use instead prompAndAlocateStringDynamically its more elegant
char* prompAndAlocStringDynamically(void); //  *****
int findStrLen( char *str ); //*****
void listAllQuestions();
//Q1_2
void pCharSwap( char *A, char *B ); //swapts  contents of two char pointers


int main( void )
{


//	q1_2( myString );


/////////////////////////////////////////////////////////////////////////////////////
//	int keepLooping = 1, question = 11;
//for some reason when i put questions in case and while loop everything goes to shit
//Not worth my effort to fix it right now
//	while( keepLooping )
//	{
/*
		printf("\nWhich question do you want to look at?\n");	
		listAllQuestions();
		scanf("%d", &question);	

		switch( question )
		{
			case 11:
				printf("\n\tQUESTION 1_1\n");
				q1_1();
				break;
			
			default:
				printf("That was not a valid choice");
		}

		printf("/nKeep looping? 1 = yes, 0 = no: keepLooping = ");
		scanf("%d", &keepLooping);
*/
//	}

	return 0;
}

//Question 1.2
/*Implement a function void reverse(char* str) in C or C++ which reverses a null- terminated string.*/
void q1_2(char* str)
{
	printf("Q1_2\nImplement a function void reverse(char* str) in C or C++ which reverses a null- terminated string.\n");

	int stringLength;

	char* myString = prompAndAlocStringDynamically();

	stringLength = findStrLen( myString );
	printf("The string Length is strLen(%d)\n", stringLength );

	for(int i = 0; i < stringLength/2; i++)
		pCharSwap(&(myString[i]),  &(myString[ stringLength - 1 - i ]) );

	printf("The reversed string is %s\n", myString );

}

//question 1.1
/*implement an algorithm to determine if a string has all unique characters. what if you cannot use additional data structures?*/

void q1_1()
{
	int stringSize, unique;

	//printf("Question 1.1\n"
	//	"Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?\n");
   //printf("How long is your string? stringSize = ");
	//scanf("%d", &stringSize);

	char *ourString = prompAndAlocStringDynamically();
	//printf("\nDebug: Your string stored correctly: %s\n", ourString);

	stringSize = sizeof(ourString)/sizeof(*ourString);
	//printf("Debug: stringSize(%d)\n", stringSize );
	

	unique = bubbleSortChars( ourString, stringSize);

	( unique == 1 )? printf("String has all unique characters\n"):printf("Duplicates were found in string\n");

	free(ourString);
}
//Q1_FUNCTIONS
//return 0 if we found duplicates or 1 if all are unique
int bubbleSortChars(char *array, int n) //best n, Worst n^2 
{
	int i, j;

	for (i = 0 ; i < ( n - 1 ); i++)
	{
		for (j = 0 ; j < n - i - 1; j++)
		{
			if ( (int) array[j] == (int) array[j+1] )
				return 0;

			if ( (int) array[j] > (int) array[j+1] ) /* For decreasing order use < */
				 charArraySwap(array, j);
		}
	}
	return 1;
}



/************************///HELPER FUNCTIONS///*************************************/
/*
  Finds the length of a string like a boss!
*/
int findStrLen( char *str )
{
	char *s;
	
	//Loop through to the end of this string
	for( s = str; *s; ++s);
	
	return ( (int) (s - str) );
}

/*
	function: 	char *promptForString( int stringSize )

	Description:
   Prompts the user for a string and stores it in an static array because otherwise
   the compiler would store it on teh stack instead of the heap and memory would point
	to an undesired location
	caller can store the return in a char pointer
*/
char* promptForString( int stringSize )
{
	static char newString[30];

	printf("New string = ");
	scanf("%s", newString);

	return newString;
}

/*
function: char* prompAndAlocStringDynamically(void)

Description:
Prompts user for string and dynamically allocates space 
one char at a time for it 
returns a char pointer to the string

caller responsibilities: free the space
*/
char* prompAndAlocStringDynamically(void) {
	int size = 8; // initial str size to store input
	char* str = malloc(size*sizeof(char));

	if (str == NULL)
   {
	 return NULL; // out of memory
	}

	char c = '\0';
	int i = 0;
	printf("Enter your string: ");

	do {
	 c = getchar();
	 if (c == '\r' || c == '\n') 
		  c = '\0'; // end str if user hits <enter>

	 if (i == size) {
		  size *= 2; // duplicate str size
		  str = realloc(str, size*sizeof(char)); // and reallocate it
		  if (str == NULL) {
			 return NULL; // out of memory
		  }
	 }
	 str[i++] = c;
	} while (c != '\0');
	return str;
}

/*
	swap current index with next index of a char array
*/
void charArraySwap( char *array, int index)
{
	char arrayTmp[1];

	arrayTmp[0] = array[index];
	array[index] = array[index+1];
	array[index+1] = arrayTmp[0];
}

/*
	Swaps the contents of two char pointers
*/
void pCharSwap( char *A, char *B )
{
	char C = *A;
	*A = *B;
	*B = C;
}

//List all questions at beggining of function
void listAllQuestions()
{
	printf("\tENTER 11 for Question 1_1\n");
	printf("implement an algorithm to determine if a string has all unique characters. what if you cannot use additional data structures");

	printf("\nQuestion = ");
}

