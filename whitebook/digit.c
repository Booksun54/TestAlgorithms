#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int time = 0;
    while (scanf("%d", &num) != EOF)
    {
        time = 0;
        if (num < 10)
        {
            printf("1\n");
        }
        else
        {
            num = num / 10;
            while (num != 0)
            {
                num = num/10;
                time++;
            }
            time++;
            printf("%d\n",time);
        }
    }
}