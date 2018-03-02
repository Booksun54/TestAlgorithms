#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a , b , c, i=0,flag=0;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        flag=0;
        for(i=0;i<100;i++)
        {
            if(i%3==a && i%5==b && i%7==c)
            {
                flag++;
                printf("%d\n",i);
            }

        }
        if(!flag)
        {
            printf("No answer\n");
        }
    }
    return 0;
}