#include "swap.h"
#include "comparator.h"
#include "bubblesort.h"

void bubblesort(char **p , int d)
{
    int i,j;
       for (i=0; i < d; i++)
    {
            for (j = d-1; j > i; j--)
    if(comparator(p[j-1],p[j]) == 1)
        {
            swap(&p[j], &p[j-1]);
        }
    }
}