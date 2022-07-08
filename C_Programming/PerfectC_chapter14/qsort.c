#define _CRT_SECURE_NO_WARNINGS
/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

/*void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));*/

int main()
{
    int n;
    qsort(values, 6, sizeof(int), compare);
    for (n = 0; n < 6; n++)
        printf("%d ", values[n]);
    return 0;
}
