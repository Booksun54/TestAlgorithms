#include<stdio.h>
#define N 12
int b[N+1];
int a[10];/*存放方格填入的整数*/
int total=0;/*共有多少种填法*/
int checkmatrix[][3]={ {-1},{0,-1},{1,-1},
						{0,-1},{1,3,-1},{2,4,-1},
						{3,-1},{4,6,-1},{5,7,-1}};
void write(int a[])
/*输出方格中的数字*/
{ 
	int i,j;
	for (i=0;i<3;i++)
	{ 
		for (j=0;j<3;j++)
			printf("%3d",a[3*i+j]);
		printf("\n");
	}
}
int isprime(int m)
/*判断m是否是质数*/
{ 
	int i;
	int primes[]={2,3,5,7,11,17,19,23,29,-1};
	if(m==1||m%2==0) 
		return 0;
	for(i=0;primes[i]>0;i++)
		if (m==primes[i])
			return 1;
	for (i=3;i*i<=m;)
	{ 
		if (m%i==0) 
			return 0;
		i+=2;
	}
	return 1;
}
int selectnum(int start)
/*从start开始选择没有使用过的数字*/
{ 
	int j;
	for (j=start;j<=N;j++)
		if (b[j]) 
			return j;
	return 0;
}
int check(int pos)
/*检查填入的pos位置是否合理*/
{ 
	int i,j;
	if(pos<0) 
		return 0;
	/*判断相邻的两个数是否是质数*/
	for(i=0;(j=checkmatrix[pos][i])>=0;i++)
		if(!isprime(a[pos]+a[j]))
			return 0;
	return 1;
}
int extend(int pos)
/*为下一个方格找一个还没有使用过的数字*/
{
	a[++pos]=selectnum(1);
	b[a[pos]]=0;
	return pos;
}
int change(int pos)
/*调整填入的数，为当前方格寻找下一个还没有用到的数*/
{ 
	int j;
	/*如果所有数都被使用，则回溯*/
	while (pos>=0&&(j=selectnum(a[pos]+1))==0)
		b[a[pos--]]=1;
	if (pos<0)
		return -1;
	b[a[pos]]=1;
	a[pos]=j;
	b[j]=0;
	return pos;
}
void find()
/*查找*/
{ 
	int ok=0,pos=0;
	a[pos]=1;
	b[a[pos]]=0;
	do
	{
		if (ok)
			if (pos==8)
			{ 
				total++;
				printf("第%d种填法\n",total);
				write(a);
				pos=change(pos);/*调整*/
			}
			else 
				pos=extend(pos);/*扩展*/
		else 
			pos=change(pos);/*调整*/
		ok=check(pos);/*检查*/
	} while (pos>=0);
}
void main()
{ 
	int i;
	for (i=1;i<=N;i++)
		b[i]=1;
	find();
	printf("共有%d种填法\n",total);
}