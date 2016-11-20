#include "swap.h"
#include "comparator.h"
#include "quick_sort.h"

void quick_sort(char **s, int right)
{
     int l = 0, r = right;
	 char *pivot;
	 pivot = s[right / 2];
	 while(l <= r)
	 {   //printf("%i %i\n", l,r);
		 while(comparator(pivot, s[l]) == 1)
			 l++;
		 while(comparator(s[r], pivot)== 1)
			 r--;
		//printf("%i %i\n", l,r);
		 if (l <= r)
		 {
			 swap(&s[l++], &s[r--]);
		 }
	 }
	  if (r > 0)
		 quick_sort(s, r);
	  if (right > l)
		 quick_sort(s + l, right - l);
}