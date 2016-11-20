#include "swap.h"
#include "comparator.h"
#include "insertsort.h"

void insertsort(char **p, int d)
{
    int i,j;
    for(i = 1; i < d;i++)
    {
        for(j = i; j > 0 && comparator(p[j-1],p[j]) == 1;j--)
        {
            swap(&p[j-1], &p[j]);
        }
    }
}