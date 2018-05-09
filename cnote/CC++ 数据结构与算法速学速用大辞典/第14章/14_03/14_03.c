#include<stdio.h>
void main()
{
    int s[6] = {0},i;
    for(s[5]=1;;s[5]++)
    {
        s[4] = 5 * s[5] + 1;
        if (s[4]%4)
            continue;
        else
            s[4] /= 4;
        s[3] = 5 * s[4] + 1;
        if (s[3]%4)
            continue;
        else
            s[3] /= 4;  
		s[2] = 5 * s[3] + 1;
        if (s[2]%4)
            continue;
        else
            s[2] /= 4; 
        s[1] = 5 * s[2] + 1;
        if (s[1]%4)
            continue;
        else
            s[1] /= 4;
        s[0] = 5 * s[1] + 1;
        break;
    } 
	for(i=1;i<6;i++)
		printf("第%d个猴子将桃子分为5堆，每堆%4d个桃子.\n",i,s[i]);
    printf("共摘了%d个桃子, 剩下%d个桃子.\n", s[0], s[5]*4);
}   
