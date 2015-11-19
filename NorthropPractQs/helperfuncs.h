#ifndef WHATEVER_H_INCLUDED
#define WHATEVER_H_INCLUDED

char *getString(void)
{
	int size = 100;
	int space = 0, spaceIndex = 0;
	char *str = malloc(size*sizeof(char) ), c = 'a';

	//Safty mechanism
	if( str == '0' )
		return NULL; //We are out of spacee

	while( c != NULL )
	{
		c = getchar();

		if (c == '\r' || c == '\n')
		{
			return str;
		}

		str[spaceIndex] = c;
		spaceIndex++;	//how much of the array we've filled

		if( spaceIndex == size )
		{
			realloc(str, size*2*sizeof(char));
			size *= 2;
			//Safty mechanism
			if( str == NULL )
				return NULL; //We are out of spacee
		}

	}
	return NULL;
}

int strLength(char *str )
{
	char *s;

	//traverse to end of string with s
	for( s = str; *s; s++);

	//(pos in mem at end of string) minus (pos in mem at beg of string)
	return( (int) (s - str) );
}

//Because I hated the other name of the same func
int strL(char *str )
{
	char *s;

	//traverse to end of string with s
	for( s = str; *s; s++);

	//(pos in mem at end of string) minus (pos in mem at beg of string)
	return( (int) (s - str) );
}

void swapP( char *a, char *b )
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif