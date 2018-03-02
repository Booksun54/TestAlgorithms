#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <iostream>  

using namespace std;

/*
将400个房前的过道设为table[200]
没经过一次讲房前的时间table[i]+10
遍历的到最大的时间即为实际需要的时间
*/

int main()
{
    int count;
    int num, time;
    int table[200],a,b;
    scanf("%d", &count);
    while (count--)
    {
        memset(table, 0, sizeof(int) * 200);
        time = 0;
        scanf("%d", &num);
        for(int i =0;i<num;i++)
        {
            scanf("%d %d",&a,&b);
            int start = ((a<b?a:b)-1)/2;
            int end = ((a>b?a:b)-1)/2;
            for(int j = start;j<=end;j++)
            {
                table[j]+=10;
            }
        }
        for(int i = 0; i< 200;i++)
        {
            time=table[i]>time?table[i]:time;
        }
        printf("%d\n",time);

    }
    return 0;
}