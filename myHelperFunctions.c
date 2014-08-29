//AWSOME FUNCTIONS
char* prompAndAlocStringDynamically(void);
int findStrLen( char *str );
void findNumAlefB();

/*************************************************************************
//Quick_Sort
int mycmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
qsort(array, LEN, sizeof(int), mycmp);

/*************************************************************************
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

/************************************************************************
*/
int findStrLen( char *str )
{
	char *s;
	
	//Loop through to the end of this string
	for( s = str; *s; ++s);
	
	return ( (int) (s - str) );
}

/************************************************************************
Finds ascii representation in int value of a-z, A-Z, \0 - DEL
*/
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
	
