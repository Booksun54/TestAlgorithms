#include <stdio.h>
/* 3n+1 简单问题 */
int main()
{
    int i, count=0;
    while (scanf("%d", &i) != EOF)
    {
        count=0;
        while (i != 1)
        {
            if (i % 2 == 0)
            {
                i /= 2;
            }
            else
            {
                i = (3 * i + 1) / 2;
            }
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}