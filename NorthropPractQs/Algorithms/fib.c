#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int fib( int num )
{

	if( num  == 0  ) 
		return 0;
	else if( num == 1 )
		return 1;
	else 
		return ( fib( num - 1 ) + fib( num - 2 ) );
}

int main()
{

	printf(" fib 5 = %d ", fib( 7) );

}


