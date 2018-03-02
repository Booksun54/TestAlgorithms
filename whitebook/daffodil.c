#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int start, end, i = 0, a, b, c, total, size = 0;
    while (scanf("%d %d", &start, &end) == 2)
    {
        size = 0;
        for (i = start; i <= end; i++)
        {
            a = i / 100;
            b = i / 10 % 10;
            c = i % 10;
            total = pow(c, 3) + pow(a, 3) + pow(b, 3);
            if (total == i)
            {

                if (size == 0)
                {
                    printf("%d", i);
                }
                else
                {
                    printf(" %d", i);
                }
                size++;
            }
        }
        if (!size)
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}