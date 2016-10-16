#include <stdio.h>
#include <stdlib.h>
void swap(char**, char**);
int comparator(char*,char*);
void bubblesort(char**, int);
void insertsort(char**, int);
void quick_sort(char**, int);
int median(char**, int, int);

int main()
{
    FILE *fp;
    if( (fp = fopen("C:\\Users\\CaptainSlow!\\Desktop\\c\\Sortanothertry\\sort.txt", "r")) == NULL)
    {
        printf("Unable to open the file\n");
        exit(1);
    }
    int size;
    fscanf(fp, "%i", &size);
    //printf("%i\n", size);
    int *amount = (int*)malloc(sizeof(int)*size);
    int n = 0, k = 0;
    char ch;
    ch = fgetc(fp);//move the pointer through the file
    do
    {
     ch = fgetc(fp);
     n++;
     if(ch == '\n' || ch == EOF)
        {  if (k >= size) break;
           amount[k] = n;
           k++;
           n = 0;
           if (ch == EOF)break;

        }
    }while(1);
    int actualsize = k;
    int i;
    //for (i = 0; i < actualsize; i++)
    //{
      //  printf("%i\n", amount[i]);
    //}
    //printf("%i\n", actualsize);
    i = 0;
    fseek(fp,3,SEEK_SET);//move the pointer to the BOF and step 3 bytes
    char **strings = (char**)malloc(sizeof(char*)*actualsize);
    for(i = 0; i != actualsize; i++)
	{
		strings[i] = (char*)malloc(sizeof(char)*(amount[i]));  // memory for each string
		fscanf(fp,"%s", strings[i]);
	}
    if(actualsize > 1)
    {
        printf("Get sorting you want:\nBubble sort -> 1\nInsertion sort -> 2\nQuick sort -> 3\n  sorting number: ");
        int j;
        scanf("%i", &j);
        switch(j)
        {
            case 1:
                bubblesort(strings, actualsize);
                break;
            case 2:
                insertsort(strings, actualsize);
                break;
            case 3:
                quick_sort(strings, actualsize-1);
                break;
            default:
                quick_sort(strings, actualsize-1);
                break;
        }
    //printf("%i\n", median(strings, 0, actualsize - 1));
    }

    for (i = 0; i < actualsize; i++)
        {
            printf("%s\n", strings[i]);
        }
    fclose(fp);
    return 0;
}
void swap(char **first, char **second)
{
    char *temp;
    temp = *first;
    *first = *second;
    *second = temp;

}
int comparator(char *first, char *second )
{
    int i = 0;
    while((first[i] !='\0')&& (second[i]!='\0'))
	{
		if (first[i] > second[i]) return 1;
		else if(first[i] < second[i])return -1;
		i++;
	}
	if (first[i]=='\0')return -1;
	return 1;

}
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
		 quick_sort(s + l, right-l);
}
/**int median(char **p, int left, int right)
{


if (comparator(p[(left + (right - left) / 2)], p[left]) == -1 && comparator(p[right], p[left]) == -1)
	{
		if (comparator(p[(left + (right - left) / 2)], p[right]) == 1)
			return (left + (right - left) / 2);
		else
			return right;
	}
else
	{
		if (comparator(p[left + (right - left) / 2], p[left]) == 1 && comparator(p[right], p[left]) == 1)
		{
			if (comparator(p[left + (right - left) / 2], p[right]) < 0)
				return left + (right - left) / 2;
			else
				return right;
		}else
			return left;
	}**/

