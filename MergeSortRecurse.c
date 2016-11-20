#include "MergeSortRecurse.h"
#include "merge.h"

void MergeSortRecurse(char **array, char **arrayB, int n, int *pos)
{
    int i;
    //for (i =  0; i < n; i++)
      //  {
        //    printf("%s ", array[i]);
        //}
	//printf("\n");
	*pos = 0;
	if(n < 2)
	{
		return;
	}



	int mid = n / 2;
	int pos0; //= 0;
	int pos1; //= 0;

	MergeSortRecurse(array, arrayB, mid, &pos0);
	MergeSortRecurse(array + mid, arrayB + mid, n - mid, &pos1);

	if(pos0 != pos1)
	{
		if(pos0 == 0)
		{
		    int i;
			for(i = mid; i < n; i++)
			{
				array[i] = arrayB[i];
			}
		}
		else
		{   int i;
			for( i = mid; i < n; i++)
			{
				arrayB[i] = array[i];
			}
		}
	}

	if(pos0 == 0)
	{
		merge(array, mid, array + mid, n - mid, arrayB);
		*pos = 1;
		for (i = 0; i < n; i++)
		    {
	//	        printf("%s ", arrayB[i]);
		    }
		//    printf("\n");
	}
	else
	{
		merge(arrayB, mid, arrayB + mid, n - mid, array);
		*pos = 0;
		//for (i = 0; i < n; i++)
		  //  {
		     //   printf("%s ", array[i]);
		    //}
		    //printf("\n");

	}


}