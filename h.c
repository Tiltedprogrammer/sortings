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
           if(diff < 0) return -1;

}
char** merge_sort(char **up, char **down, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (unsigned int)((left + right) * 0.5);

    // раздел€й и сортируй
    char **l_buff = merge_sort(up, down, left, middle);
    char **r_buff = merge_sort(up, down, middle + 1, right);

    // сли€ние двух отсортированных половин
    char **target;//= l_buff == up ? down : up;
    if(l_buff == up) target = down;
    else target = up;

    unsigned int width = right - left, l_cur = left, r_cur = middle + 1;
    unsigned int i;
    for (i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (comparator(l_buff[l_cur], r_buff[r_cur]) == -1)
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;

}
void quick_sort(char **p,int right)
{
   int  l=0, r=right-1;
   char *m = p[r/2];
   char *temp;
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
   if (r > 0 ) quick_sort(p,r);
   if (right> l ) quick_sort(p + l, right - l);
}
