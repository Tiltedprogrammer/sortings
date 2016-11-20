#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "swap.h"
#include "comparator.h"
#include "bubblesort.h"
#include "insertsort.h"
#include "quick_sort.h"
#include "MergeSort.h"
#include "MergeSortRecurse.h" 
#include "merge.h"

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
    if (actualsize < size)
    {
        (int*)realloc(amount, sizeof(int) * actualsize);
    }
    int i;
    //for (i = 0; i < actualsize; i++)
    //{
      //  printf("%i\n", amount[i]);
    //}
    //printf("%i\n", actualsize);
    i = 0;
    rewind(fp);
    while((ch = fgetc(fp))!= '\n');//move the pointer to the BOF and step 1 line;
    char **strings = (char**)malloc(sizeof(char*)*actualsize);
    for(i = 0; i != actualsize; i++)
	{
		strings[i] = (char*)malloc(sizeof(char)*(amount[i]));  // memory for each string
		fscanf(fp,"%s", strings[i]);
	}
    if(actualsize > 1)
    {
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
        }
    //MergeSort(strings, actualsize);
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


