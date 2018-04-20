#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <iostream>  

using namespace std;

/*
将400个房前的过道设为table[200]
每经过一次房前的时间table[i]+10
遍历的到最大的时间即为实际需要的时间

题意：在一个狭窄的走廊里将桌子从一个房间移动到另一个房间，走廊的宽度只能允许一个桌子通过。给出t，

   表示有t组测试数据。再给出n，表示要移动n个桌子。n下面有n行，每行两个数字，表示将桌子从a房间

   移到b房间。走廊的分布图如一图所示，每移动一个桌子到达目的地房间需要花10分钟，问移动n个桌子

   所需要的时间。

解题思路：若移动多个桌子时，所需要经过的走廊没有重合处，即可以同时移动。若有一段走廊有m个桌子都

     要经过，一次只能经过一个桌子，则需要m*10的时间移动桌子。设一个数组，下标值即为房间号。

     桌子经过房间时，该房间号为下标对应的数组值即加10。最后找到最大的数组值，即为移动完桌子

     需要的最短时间。

     1 3 5 7 ... 397 399
     2 4 6 8 ... 398 400

     1 2 3 4 ... 199 200 table 贪心算法
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
            int start = ((a<b?a:b)-1)/2;//按照图片位置 计算房间在数组中的位数 三号房间 (3+1)/2=2 table[2]
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