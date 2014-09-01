//AWSOME FUNCTIONS
void qsort(array, LEN, sizeof(int), mycmp);
char* prompAndAlocStringDynamically(void);
int findStrLen( char *str );
void findNumAlefB();
int next_prime(int n);
int sz_array_min(int *array, int n); find min of array in n time

/************************************************************************
* Helper function to call qsort 
***********************************************************************/
//Quick_Sort
int mycmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
qsort(array, LEN, sizeof(int), mycmp);

/*************************************************************************
* function: char* prompAndAlocStringDynamically(void)
*
* Description:
* Prompts user for string and dynamically allocates space 
* one char at a time for it 
* returns a char pointer to the string
*
* caller responsibilities: free the space
******************************************************************/
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

/************************************************************************
* finds length of the string in a most efficient way
*********************************************************************/
int findStrLen( char *str )
{
	char *s;
	
	//Loop through to the end of this string
	for( s = str; *s; ++s);
	
	return ( (int) (s - str) );
}

/************************************************************************
Finds ascii representation in int value of a-z, A-Z, \0 - DEL
**********************************************************************/
void findNumAlefB()
{
	int a = (int) 'a';
	int A = (int) 'A';	
	int null = (int) '\0'; //First letter of ascii
	int tilde = (int) '~';  //Second to last letter in ascii DEL is last

	//26 letters in alphabet
	printf("lower case int rep of ascii a-z %d-%d \n", a, (a+26-1) );
	printf("Upper case int rep of ascii A-Z %d-%d \n", A, (A+26-1) );
	printf("int rep of chars range from %d-%d in ascii \n", null, tilde+1 ); //+1 for del
}

/*****************************************
* determines whether an integer is prime
****************************************/
int is_prime(int n)
{
	int i;
	
	for (i = 3; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	
	return 1;
}

/*********************************************************
* a function to find the next prime number, beginning at n
*********************************************************/
int next_prime(int n)
{
	if (n % 2 == 0)
		n++;
	
	while (!is_prime(n))
		n += 2;
	
	return n;
}

/********************************************************
* These functions return the min val of an array i n time
********************************************************/
// return the minimum of two integers
int min(int a, int b)
{
	// conditional operator is awesome
	return (a < b) ? a : b;
}

// This is how I would implement the recursive solution. 
int sz_array_min(int *array, int n)
{
	// If there's just one element in our array, that's the minimum element in
	// the array.
	if (n == 1)
		return array[0];

	// Take the minimum of the last element in the array, or the minimum element
	// among the first (n - 1) elements of the array.
	return min(array[n - 1], sz_array_min(array, n - 1));
}
	
