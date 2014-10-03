#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

void bubbleSort(int *array, int n);
void selectionSort(int *array, int n); 
void insertionSort(int *array, int n);
void bucketSort(int *array, int n);
void MergeSort(int *pInArray, int nSize);
////////HELPER FUNCTIONS//////////////
void swap(int *array, int index );
void printA(int *array, int n);
void rePolute(int *array, int array_size); 
int  mycmp(const void *a, const void *b);



int main(){

    int i = 0, array_size, *array;
		/*clock_t*/uintmax_t start,end;

		//promp user for array size
		printf("How long would you like your unsorted array to be? array_Length: ");
		scanf("%d", &array_size ); 

		//allocate array
		array = malloc( sizeof(int) * array_size );

		//Insert random data into the array from [0,99]
		for( i = 0; i < array_size; i++ )
				array[i] = rand() % 100;

		printf("\n");
    //bubble sort 
    printf("original \t->\t\t ");        printA( array, array_size );
		start = clock();
    bubbleSort(array, array_size);
		end = clock(); end = (end - start)/CLOCKS_PER_SEC;
    printf("bubble sort \t-> \t\t ");     printA( array, array_size ); printf("Clock_Time: %ju\n\n", (uintmax_t)(clock_t)end);
    rePolute(array,array_size);

    //selection sort
    printf("original \t->\t\t ");        printA( array, array_size );
    selectionSort(array, array_size);
    printf("selection sort \t->\t\t "); printA( array, array_size ); printf("\n");
    rePolute(array,array_size);

    //insertion sort
    printf("original \t->\t\t ");        printA( array, array_size );
    insertionSort(array, array_size);
    printf("insertion sort \t->\t\t "); printA( array, array_size ); printf("\n");
    rePolute(array,array_size);

/*  // Theres a but thats no worth my time to find right now in this sort
    //bucket sort
    bucketSort(array, array_size);
    printf("bucket sort -> \t\t "); printA( array, array_size );    
    rePolute(array,array_size);
*/
		//quick sort
    printf("original \t->\t\t ");        printA( array, array_size );
    qsort(array, array_size, sizeof(int), mycmp);
    printf("quick sort \t-> \t\t "); printA( array, array_size );  printf("\n");  
    rePolute(array,array_size);

		//mergesort
    printf("original \t->\t\t ");        printA( array, array_size );
		MergeSort(array, array_size);
    printf("merge sort \t-> \t\t "); printA( array, array_size ); printf("\n");
    rePolute(array,array_size);

    return 0; 
}

void bucketSort(int *array, int n){   
    
    int i, j;   
    int count[n+1];  
    for(i=0; i < n; i++)
        count[i] = 0;   
    for(i=0; i < n; i++)
        (count[array[i]])++; 
    for(i=0,j=0; i < n; i++) 
        for(; count[i]>0;(count[i])--)      
            array[j++] = i; 
        
} 

void insertionSort(int *array, int n){
    
    int i, j, k, temp; 

    for ( i = 0 ; i < n ; i++ ){
        for ( j = 0 ; j < i ; j++ ){
            if ( array[j] > array[i] ){
                temp = array[j] ;
                array[j] = array[i] ;
                
                for ( k = i ; k > j ; k-- )
                    array[k] = array[k - 1] ;
                
                array[k + 1] = temp ;
            }
        }
    }
    
}

void selectionSort(int *array, int n){
    
    int i, j, min, temp;
    for(i=0;i<n-1;i++){
        min = i;
        for(j= i+1;j<n;j++)
            if(array[j]<array[min])
                min = j;
        //notice we didn't use the swap func 
        temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
}

void bubbleSort(int *array, int n) //best n, Worst n^2 
{
    int i, j;
    
    for (i = 0 ; i < ( n - 1 ); i++)
    {
        for (j = 0 ; j < n - i - 1; j++)
            if (array[j] > array[j+1]) /* For decreasing order use < */
                swap(array, j);
    }
}

//////////////////////////////////SORTS WITH MORE CODE

//////////////////////////////////MERGE_SORT_BEG

void Merge(int *pInArray, int nLeftSize, int nRightSize)
{
//	int *pTemp = new int[nLeftSize + nRightSize];
	int *pTemp = malloc( sizeof(int)*(nLeftSize + nRightSize) );
	int nLeftIndex = 0, nRightIndex = 0;
	int *pLeftArray = pInArray, *pRightArray = &pInArray[nLeftSize];

	while (nLeftIndex + nRightIndex < nLeftSize + nRightSize)
	{
		if (nLeftIndex < nLeftSize && 
			(pLeftArray[nLeftIndex] <= pRightArray[nRightIndex] || nRightIndex >= nRightSize))
		{
			pTemp[nLeftIndex + nRightIndex] = pLeftArray[nLeftIndex];
			nLeftIndex++;
		}
		if (nRightIndex < nRightSize && 
			(pRightArray[nRightIndex] < pLeftArray[nLeftIndex] || nLeftIndex >= nLeftSize))
		{
			pTemp[nLeftIndex + nRightIndex] = pRightArray[nRightIndex];
			nRightIndex++;
		}
	}

	for (int i = 0; i < nLeftSize + nRightSize; i++)
	{
		pInArray[i] = pTemp[i];
	}
	//delete[] pTemp;
	free(pTemp);
}

void MergeSort(int *pInArray, int nSize)
{
	if (nSize <= 1)
	{
		return;
	}

	int nLeftSize = nSize / 2;
	int nRightSize = nSize - nLeftSize;
	MergeSort(pInArray, nLeftSize);
	MergeSort(&pInArray[nLeftSize], nRightSize);
	Merge(pInArray, nLeftSize, nRightSize);
}
//////////////////////////////////MERGE_SORT_END

//////////////////////////////////HELPER_FUNCTIONS

void rePolute(int *array, int array_size){
		int i;

		//Insert random data into the array from [0,99]
		for( i = 0; i < array_size; i++ )
				array[i] = rand() % 100;
}

void swap(int *array, int index ){
    //lagit swap function
    array[index] = array[index+1] + array[index]; 
    array[index + 1] = array[index] - array[index + 1]; 
    array[index] =  array[index] - array[index + 1]; 
}

// Print an array of n integers, space-separated, followed by two newline chars.
void printA(int *array, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');
		
//		printf("\n");
}

//Sorts

//Quick_Sort
int mycmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

