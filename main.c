#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "swap.h"
#include "comparator.h"
#include "bubble_sort.h"
#include "insert_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		exit(1);
	}
    clock_t tic = clock(),tac;
    FILE *fp;
    if( (fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Unable to open the file\n");
        exit(1);
    }
    int size = atoi(argv[1]);
    int *amount = (int*)malloc(sizeof(int)*size);
    int n = 0, k = 0;
    char ch;
    do
    {
     ch = fgetc(fp);
     n++;
     if(ch == '\n' || ch == EOF)
        {  
           if (k >= size) break;
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
    int i,j;
    rewind(fp);
    char **strings = (char**)malloc(sizeof(char*)*actualsize);
    for(i = 0; i != actualsize; i++)
	{
		j = 0;
		strings[i] = (char*)malloc(sizeof(char)*(amount[i]));
		while(((ch = fgetc(fp)) != '\n') && (ch != EOF))
		{
			strings[i][j] = ch;
			j++;
		}
		strings[i][j] = '\0';
	}
    if(actualsize > 1)
    {
        printf("Get sorting:\nBubble sort    -> 1\nInsert sort    -> 2\nQuick sort     -> 3\nMerge sort     -> 4\n  Sorting number: ");
        if(scanf("%i", &j) == EOF) exit(1);
        switch(j)
        {
            case 1:
                bubble_sort(strings, actualsize);
                break;
            case 2:
                insert_sort(strings, actualsize);
                break;
            case 3:
                quick_sort(strings, actualsize-1);
                break;
            case 4:
                merge_sort(strings,actualsize);
            default:
                quick_sort(strings, actualsize-1);
                break;
        }
    //MergeSort(strings, actualsize);
    }

    for (i = 0; i < actualsize; i++)
        {
            printf("%s\n", strings[i]);
            free(strings[i]);
        }
    fclose(fp);
    free(strings);
    free(amount);
    tac = clock();
    printf("%f", (double)(tac - tic)/ CLK_TCK);
    return 0;
}


