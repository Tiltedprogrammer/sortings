#include "swap.h"

void swap(char **first, char **second)
{
    char *temp;
    temp = *first;
    *first = *second;
    *second = temp;

}