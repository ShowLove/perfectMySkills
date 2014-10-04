//MergeSort

//Classic Swap
void swap(int *array, int i, int j)
{
    int tmp = 0;

    //perform classic swap
    tmp      = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void MergeSort(int *array, int lo, int hi)
// base case: one (or fewer) elements in this portion of the array
	if (lo >= hi)
		return;
int mid = lo + (hi-lo)/2;

	// recursive calls
	MergeSort(array, lo, mid);
	MergeSort(array, mid+1, hi);

	// mergey merge
	aux = malloc(sizeof(int) * (hi - lo + 1));

	while (i <= mid || j <= hi)
	{
		if (i > mid)
			aux[k++] = array[j++];
		else if (j > hi)
			aux[k++] = array[i++];
		else if (array[i] < array[j])
			aux[k++] = array[i++];
		else
			aux[k++] = array[j++];
	}

	// copy everything from the auxiliary array back into the original array
	for (i = lo; i <= hi; i++)
		array[i] = aux[i - lo];

	// clean up after yourself
	free(aux);
}
