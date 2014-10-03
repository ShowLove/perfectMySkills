#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**********************************************************************************
*
**********************************************************************************/

//Functions
void swapNumInPlace();
void ticTacToe();
int trailingZerosInFactorial(int n, int zeros);
//Test Code 
//swap_testCode
void testSwap(int orig_a, int orig_b, int swap_a, int swap_b);
//ttt_testCode
int **tttInit();
void printTTT( int **array );
int foundWin(int **array, int col);
//Trailing Zeros
int findZeros(int n);

int main()
{
	//trailingZerosFact
	int zeros = 0, n = 100;

	//swapNumInPlace();
	//ticTacToe();
	zeros = trailingZerosInFactorial(n, zeros);
	printf("\nthe number of trailing zeros in fact(%d):\t%d\n", n, zeros);
}

/**********************************************************************************
* Write an algorithm which computes the number of trailing zeros in n factorial
* The thoughs are right still has some bugs i have no time to fix now
**********************************************************************************/
int trailingZerosInFactorial(int n, int zeros)
{
	if(n == 0) 
		return zeros;
	else
	{
		zeros = findZeros(n);	
		return (zeros + trailingZerosInFactorial(n - 1, zeros) );
	}
}

int findZeros(int n)
{
	int mod = 10;
	int num = n;
	int numZeros = 1;

	if(num % mod != 0)
		numZeros = 0;
	
	//printf("\nn(%d) <-------------\n", n);

	while( num % mod == 0 )
	{			
		//printf("num(%d)mod mod(%d) = %d\n", num, mod, num%mod );
		numZeros++;
		mod *= 10;
	}

	//printf("numZeros(%d)\n", numZeros);
	return numZeros;
}

/**********************************************************************************
* Design an algorithm to figure out if someone has won a game oftic-tac-toe.
**********************************************************************************/
void ticTacToe()
{
	int size = 3, xo=3, foundW = 0; //0 = 0, 1 = x, 2 = none found
	int **array;

	//This aray holds a tic tac toe game
	array = tttInit();

	for(int j = 0; j < size; j++)
	{
		if( j == 0 )
		{
			foundW = foundWin(array, 0);
			if( foundW == 1)
				break;
		}
		else if( j == 1 )
		{
			foundW = foundWin(array, 1);
				if(foundW == 1)
					break;
		}	
		else if(j == 2)
		{
			foundW = foundWin(array, 2);
				if(foundW == 1)
					break;
		}		
	}
	if(foundW == 0)
		printf("\n No winner in this random tic tac to party\n");

}

int foundWin(int **array, int col)
{
	if(col == 0)
	{		printf("\nChecked col 0\n");
		//Horizontle
		if(array[0][0]+array[0][1]+array[0][2] == 3)
			printf("\n\tX wins at 0,0 0,1 0,2\n");	
		if(array[0][0]+array[0][1]+array[0][2] == 0)
			printf("\n\tO wins at 0,0 0,1 0,2\n");
		//Diaginal
		if(array[0][0]+array[1][1]+array[2][2] == 3)
			printf("\n\tX wins at array[0][0]+array[1][1]+array[2][2]\n");	
		if(array[0][0]+array[1][1]+array[2][2] == 0)
			printf("\n\tO wins array[0][0]+array[1][1]+array[2][2]\n");
		//Virticle
		if(array[0][0]+array[1][0]+array[2][0] == 3)
			printf("\n\tX wins at array[0][0]+array[1][0]+array[2][0]\n");	
		if(array[0][0]+array[1][0]+array[2][0] == 0)
			printf("\n\tO wins at array[0][0]+array[1][0]+array[2][0]\n");
			return 1;
	}
	if(col == 1)
	{				printf("checked col 1\n");
		//Virticle middle
		if(array[0][1]+array[1][1]+array[2][1] == 3)
			printf("\n\tX wins at array[0][1]+array[1][1]+array[2][1]\n");	
		if(array[0][0]+array[1][0]+array[2][0] == 0)
			printf("\n\tO wins at array[0][1]+array[1][1]+array[2][1]\n");
		//horizontle bottom
		if(array[2][0]+array[2][1]+array[2][2] == 3)
			printf("\n\tX wins at array[2][0]+array[2][1]+array[2][2]n");	
		if(array[2][0]+array[2][1]+array[2][2] == 0)
			printf("\n\tO wins at array[0][0]+array[1][0]+array[2][2]\n");
		return 1;
	}
	if(col == 2)
	{				printf("checked col 2\n");
	//Diaginal
		if(array[0][2]+array[1][1]+array[2][0] == 3)
			printf("\n\tX wins at array[0][2]+array[1][1]+array[2][0]\n");	
		if(array[0][0]+array[1][0]+array[2][0] == 0)
			printf("\n\tO wins at array[0][0]+array[1][0]+array[2][0]\n");
	//Horizontle
		if(array[0][2]+array[1][2]+array[2][2] == 3)
			printf("\n\tX wins at array[0][2]+array[1][2]+array[2][2]\n");	
		if(array[0][2]+array[1][2]+array[2][2] == 0)
			printf("\n\tO wins at array[0][2]+array[1][1]+array[2][0]\n");
		return 1;
	}
	return 0;
}


/**********************************************************************************
* Thoughts:
* right edge:	[i][size -1] 	right_CornerA: [0][size - 1]; right_CornerB[size -1][size - 1];  
* left edge:  [i][0]; 			left_CornerA: [0][0]; left_CornerB[size - 1][0]; 
* Diagonals 
* nw: [i - 1][j - 1] 	ne: [i - 1][j + 1]
* sw:	[i + 1][j - 1]	se: [i + 1][j + 1]
* Horiz/Virt
* up: 	[i - var][j];		down: [i + var][j]
* left: [i][j - var]; 	right[i][j + var]
* middle:	
* both i and j size must be odd for there to be a middle
* i_mid = i_size/2 + 1:		j_mid = j_size/2+1
*********************************************************************************/

int **tttInit()
{
	int size = 3;
	int **tttArray = malloc( sizeof(int *) * size );
	for(int k = 0; k < size; k++)
		tttArray[k] = malloc(sizeof(int)*size);//TODO free both of these in reverse order later

	srand(time(NULL) );

	for(int i = 0; i < size; i++)
	{	
		for(int j = 0; j < size; j++)
		{
			//1=x 0=o
			tttArray[i][j] = rand()%2;
		}
	}
	printf("your TTT!!!\n");
	printTTT(tttArray);
	
	return tttArray;
}

void printTTT(int **array)
{
	int size = 3;
	for( int i = 0; i < size; i++)
	{
		for( int j = 0; j < size; j++)
		{
			( j == (size - 1) )? printf("%d \n", array[i][j]) : printf("%d ", array[i][j] );
		}
	}
	printf("\n");
}

/*********************************************
* Write a function to swap a number in place 
* (that is, without temporary variables).
*********************************************/
void swapNumInPlace( )
{
	int a, b;
	int orig_a, orig_b;

	srand(time(NULL) );
	//Populate from [0,99]
	a = rand()%100;
	b = rand()%100;

	orig_a = a; orig_b = b;//TODO: delete this line

	a = a + b;
	b = a - b;
	a = a - b;

	testSwap( orig_a, orig_b, a, b );//TODO:dele thsi line
}

/**********************************************************************************
* callers responsibility to save new and old values
* we are assuming that storing the extra two values isn't a big deal
**********************************************************************************/
void testSwap(int orig_a, int orig_b, int swap_a, int swap_b)
{
	( orig_a == swap_b && orig_b == swap_a )?printf("Great!"):printf("No soop for you");
	printf("\t a(%d),b(%d),swap_a(%d),swap_b(%d)\n", orig_a, orig_b, swap_a, swap_b );
	
}

