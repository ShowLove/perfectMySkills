//Here's a few different implementations for Insertion sort
//SORTTYPES_H_INCLUDED


#include "SortTypes.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i, n = 0, *array = NULL;
    clock_t start, stop;

    //seed random generator
    srand(time(NULL));

    printf("How big is the array?\n");
    scanf("%d", &n);

    n = (n > DEFAULT_ARRAY_LEN) ? n: DEFAULT_ARRAY_LEN;

    array = malloc(sizeof(int) * n);

    printRand(array, n);

    start = clock();
    chooseSort(array, n);
    stop = clock();

    printf("%lf seconds, %lf milliseconds\n", (double)stop-start / CLOCKS_PER_SEC, (double)stop-start/1000 / CLOCKS_PER_SEC);

    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}

