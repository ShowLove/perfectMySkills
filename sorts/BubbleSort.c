//Here's a few different implementations for bubble sort
//SORTTYPES_H_INCLUDED



#include "SortTypes.h"

void BubbleSort(int *array, int n)
{
    int i,swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (i = 0;i < n - 1;i++)
        {
            if (array[i] > array[i+1])
            {
                swap(array, i, i+1);
                swapped = 1;
            }
        }
    }
}


//int main(void)
//{
//    int i, n = 0, *array = NULL;
//
//    //seed random generator
//    srand(time(NULL));
//
//    printf("How big is the array?\n");
//    scanf("%d", &n);
//
//    n = (n > DEFAULT_ARRAY_LEN) ? n: DEFAULT_ARRAY_LEN;
//
//    array = malloc(sizeof(int) * n);
//
//    printRand(array, n);
//
//    chooseSort(array, n);
//
//    for (i = 0; i < n; i++)
//    {
//        printf("%d ", array[i]);
//    }
//
//    printf("\n");
//
//    return 0;
//}
//
