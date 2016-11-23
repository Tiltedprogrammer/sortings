#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv)
{
	if(argc !=3 ) exit(1);
    FILE *fp;
    if((fp = fopen(argv[2], "w")) == NULL) exit(1);
    clock_t start, stop;
    start = clock();
    srand(time(NULL));
    int n = atoi(argv[1]);
    char **string = (char**)malloc(sizeof(char*)* n);
    int i,j,z;
    for (i = 0; i < n; i++)
    {
        int c = rand() % 6 + 2;
        string[i] = (char*)malloc(sizeof(char)* c + 1);
        for(j = 0; j < c; j ++)
        {
            while(( ( (z = rand()%25+97)<=122 ) && (z>=97) && (z!=91) && (z!=92) && (z!=93) && (z!=94) && (z!=95) && (z!=96))==0 ) ;
            string[i][j] = z;
        }
        string[i][j] ='\0';
    }
    for(i = 0; i < n; i++)
    {
        if(i!= n-1)
            fprintf(fp, "%s\n", string[i]);
        else
            fprintf(fp, "%s", string[i]);

    }
    fclose(fp);

    //printf("%s\n", string[0]);
    //printf("%s\n", string[1]);
    stop = clock();
    //printf("%f", (double)(stop -start )/ 1000);
}
