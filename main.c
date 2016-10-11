#include <stdio.h>
#include <stdlib.h>

int comparator(char** ,char**);
void bubblesort(char**, int);
void insertsort(char**,int);
void quick_sort(char**, int);

int main()
{
   int i=0,d = 0,N;
   FILE *file;
   file = fopen("C:\\Users\\CaptainSlow!\\Desktop\\c\\hernya\\tilt.txt", "r");
   fscanf(file,"%i", &N);
   char name[N][100];
   char *naname[N];
   while (fscanf (file, "%s", name[d]) != -1)
    {
		d++;
        i++;
		if(i>(N-1)) break;
	}
	for (i = 0; i < d; i++)
    {
        naname[i] = name[i];
    }
   quick_sort(naname,d);
   for(i = 0; i < d; i++)
   {
   printf("%s\n", naname[i]);
   }
   return 0;
}
