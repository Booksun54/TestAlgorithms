#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int count, i, j, k,l;
    while (scanf("%d", &count) != EOF)
    {
        for (i = 0; i < count; i++)
        {
            for (k = i; k >= 0; k--)
            {
                printf(" ");
            }
            for (j = 2 * (count-i) - 1; j > 0; j--)
            {
                printf("#");
            }
            for ( l = i; l >= 0; l--)
            {
                printf(" ");
               
            }
             printf("\n");
        }
        
    }
}
