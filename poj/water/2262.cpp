/*
    |埃式筛法|
    |快速筛选素数|
　　　　|15-7-26|
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int SIZE = 1e7;

int prime[SIZE];     // 第i个素数
bool is_prime[SIZE]; //true表示i是素数

int slove(int n)
{
    int p = 0;
    for (int i = 0; i <= n; i++)
        is_prime[i] = true;            //初始化
    is_prime[0] = is_prime[1] = false; //0,1不是素数
    for (int i = 3; i <= n; i++)
    {
        if (is_prime[i]) //这里比较巧妙, 我只是意会
        {
            prime[p++] = i;                     //计算素数的个数,也记录下了素数
            for (int j = 2 * i; j <= n; j += i) // 除掉了i的倍数的数字
                is_prime[j] = false;
        }
    }
    return p;
}

int main()
{
    int a;
    // while(cin >> n)
    // {
    //     int res = slove(n);
    //     cout << res << endl;
    //     for(int i = 0; i < res; i++)
    //         cout << prime[i] << endl;
    // }

    while (scanf("%d", &a) && a)
    {
        int res = slove(1000001);
        int sum = 0;
        int s = 0, t = 0;
        int count = 0;

        while(prime[s]<a)
        {
            s++;
        }

        s--;
        if(prime[s]==a)
        {
            printf("%d = %d\n",a,prime[s]);
        }else{
            std::cout<<prime[s];
            while(prime[t] == (a-prime[s] && t<s))
            {
                t++;
            }
            printf("%d = %d + %d\n",a,prime[s],prime[t]);
        }
       
    }
    return 0;
}