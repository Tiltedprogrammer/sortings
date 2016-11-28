#include "swap.h"
#include "comparator.h" 
int comparator(char *first, char *second )
{
    int i = 0;
    int f,s;
    while((first[i] !='\0') && (second[i]!='\0'))
	{
		//CAPITAL letters first
	    f = first[i];
	    s = second[i];
		if (f > s)  return 1;
		else if(f < s) return -1;
			i++;
    }

	if (first[i]=='\0')return -1;
	return 1;
}
