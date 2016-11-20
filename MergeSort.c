#include "MergeSort.h"
#include "MergeSortRecurse.h"
#include <stdlib.h>

void MergeSort(char**array, int n)
{
	if(n < 2)
	{
		return;
	}

	int pos = 0;
	int i = 0;
	char **arrayB = (char**)malloc(sizeof(char*) * n);

	MergeSortRecurse(array, arrayB, n, &pos);

	if(pos == 1)
	{
		for(i = 0; i < n; i++)
		{
			array[i] = arrayB[i];
		}
	}
	free(arrayB);
}