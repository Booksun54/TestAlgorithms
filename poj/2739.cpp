#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>


/*
埃拉托斯尼筛法
简单检索素数的算法
详细列出算法如下：

    列出2以后的所有序列：
        2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    标出序列中的第一个素数，也就是2，序列变成：
        2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    将剩下序列中，划掉2的倍数，序列变成：
        2 3 5 7 9 11 13 15 17 19 21 23 25
    如果现在这个序列中最大数小于最后一个标出的素数的平方，那么剩下的序列中所有的数都是素数，否则回到第二步。
    本例中，因为25大于2的平方，我们返回第二步：
    剩下的序列中第一个素数是3，将主序列中3的倍数划掉，主序列变成：
        2 3 5 7 11 13 17 19 23 25
    我们得到的素数有：2，3
    25仍然大于3的平方，所以我们还要返回第二步：
    现在序列中第一个素数是5，同样将序列中5的倍数划掉，主序列成了：
        2 3 5 7 11 13 17 19 23
    我们得到的素数有：2，3，5 。
    因为23小于5的平方，跳出循环.

结论：2到25之间的素数是：2 3 5 7 11 13 17 19 23。

题目分析

    先求出所有可能构成加数的素数，使用埃氏筛选法。然后求出所有的可能形式，由于所选择的是一个连续的区间，可以使用一个头指针，一个尾指针，区间选择为头尾指针内部的区域，通过头尾指针的移动来更改区间。即尺取法。 
    尾部保持不动，不断增加头部，并加上头部数据，记录区间内的和，若恰好等于n，则计数加1，若大于等于n，则不断的减去尾部的数据....
*/
using namespace std;

bool is_prime[10005];

int primes[10005];
int prime_count;

void GetPrimes(int n)
{
    int k = 0;
    memset(is_prime, true, sizeof(is_prime));
    for(int i = 2; i <=n; i++)
    {
        if(!is_prime[i])//删除倍数后若不存在则跳过
            continue;
        primes[k++] = i;

        for(int m = 1; m*i <= n;m++)
        {
            is_prime[m*i] = false;//删除i的倍数
        }
    }
    prime_count = k;//记录素数的个数
}
int main()
{
    int n;
    GetPrimes(10000);

    while(scanf("%d",&n) && n){
        int sum = 0;
        int s = 0, t = 0;
        int count = 0;
        //尺取法
        for (;;){
            while (primes[t] <= n && sum < n){    //若小于n则头部一直增加，直到大于等于n
                sum += primes[t++];
            }

            if(sum == n) //计数
                count++;
            
            sum -= primes[s++];//减去头部

            if(sum <= 0)
                break;
        }
        printf("%d\n",count);
    }
    return 0;
}