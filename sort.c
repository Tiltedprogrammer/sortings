#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
void swap(char**, char**);
int comparator(char*,char*);
void bubblesort(char**, int);
void insertsort(char**, int);
void quick_sort(char**, int);
int median(char**, int, int);
void MergeSort(char**, int );
void MergeSortRecurse(char**, char**, int , int*);
void merge(char**, int , char**, int , char**);

int main()
{
    clock_t tic,tac;
    tic = clock();
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
    {/**
        printf("Get sorting you want:\nBubble sort    -> 1\nInsertion sort -> 2\nQuick sort     -> 3\nMerge sort     -> 4\n  Sorting number: ");
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
            case 4:
                MergeSort(strings,actualsize);
            default:
                quick_sort(strings, actualsize-1);
                break;
        }**/
    MergeSort(strings, actualsize);
}

    for (i = 0; i < actualsize; i++)
        {
            printf("%s\n", strings[i]);
        }
    fclose(fp);
    free(strings);
    free(amount);
    tac = clock();
    printf("%f", (double)(tac - tic)/ CLK_TCK);
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
    int f,s;
    while((first[i] !='\0')&& (second[i]!='\0'))
	{
	    f = first[i];
	    s = second[i];
		if ((f <91) && (s >=96))  //FOR ENGLISH LETTERS
			{
				f+=32;
			}
        if ((f >= 96)&&(s < 91))
			{
				s+=32;
			}
		if (f > s) { return 1;}
			else if(f < s) {return -1;}
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
		 quick_sort(s + l, right - l);
}
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

	if(pos0 != pos1)							//Prepare for merge. Both of answers must locate in same array
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


void MergeSort(char**array, int n)
{
	if(n < 2)
	{
		return;
	}

	int pos = 0;								//If pos == 0, then sorted array located in array, else in arrayB
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

