#include <stdio.h>
#include <stdlib.h>

int comparator(char *first, char *second )
{
    int diff;
    while(*first != '\0' || *second != '\0')
    {
        diff = *first - *second ;
        if (diff!=0) break;
        first++;
        second++;
           }
           if(diff > 0 ) return 1;
           if(diff == 0) return 0;
           if(diff < 0 ) return -1;}

void bubblesort(char *p[] , int d)
{
    char *temp;
    int i,j;
       for (i=0; i < d; i++)
    {
            for (j = d-1; j > i; j--)
    if(comparator(p[j-1],p[j]) == 1)
        {
            temp = p[j];
            p[j]= p[j-1];
            p[j-1]= temp;
        }
    }
}
void insertsort(char *p[], int d)
{
    char *temp;
    int i,j;
    for(i = 1; i < d;i++)
    {
        for(j = i; j > 0 && comparator(p[j-1],p[j]) == 1;j--)
        {
            temp = p[j];
            p[j]= p[j-1];
            p[j-1]= temp;
        }
    }
}

void quick_sort(char *p[],int right)
{
   int  l = 0, r = right-1;
   char *temp,*m = p[right/2];
   if (l == r) return;
   while(l <= r)
   {
       while(comparator(p[l], m) == -1)
       {
           l++;
       }
       while(comparator(m,p[r])== -1)
       {
           r--;
       }
       if(l <= r)
       {

          temp = p[l];
          p[l] = p[r];
          p[r]= temp;
          l++;
          r--;
       }
   }
   if (r > 0) quick_sort(p,r);
   if (l < right) quick_sort(p + l, right-l);


}

