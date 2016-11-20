#include "comparator.h"
#include "merge.h"

void merge(char **L, int nL, char **R, int nR, char **array)
{
	int l = 0;
	int r = 0;
	int k = 0;

	while(l < nL && r < nR)
	{
		if(comparator(L[l], R[r]) == -1)
		{
			array[k++] = L[l++];
		}
		else
		{
			array[k++] = R[r++];
		}
	}

	while(l < nL)
	{
		array[k++] = L[l++];
	}
	while(r < nR)
	{
		array[k++] = R[r++];
	}
}
