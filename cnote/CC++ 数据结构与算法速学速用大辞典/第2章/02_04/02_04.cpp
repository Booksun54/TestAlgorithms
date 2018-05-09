#include <stdio.h>
#define MAXSIZE 100
int Comb(int n,int m);
void main()
{
	int n,m;
	printf("请输入n和m（大于等于1小于等于20且n>m）：");
	scanf("%d,%d",&n,&m);
	printf("栈顶指针  [top][1] [top][2] [top][3]\n");
	printf("C(%d,%d)=%8d\n",n,m,Comb(n,m));
}
int Comb(int n,int m)
//计算c(n,m)的值
{
	int s1,s2,tag=0;//tag标志为了避免重复输出
	int stack[MAXSIZE][3],top=1;//定义栈stack并初始化栈
	if (n<m || n<0 || m<0)
	{
		printf("n，m值不正确!" );
		return -1;
	}
	stack[top][1]=0; //栈顶编号1的初始化，初值0入栈
	stack[top][2]=n; //栈顶编号2的初始化，初值n入栈
	stack[top][3]=m; //栈顶编号3的初始化，初值m入栈
	do
	{
		printf("top=%d:%8d,%8d,%8d\n",top,stack[top][1],stack[top][2],stack[top][3]);
		if (stack[top][1]==0)
		//若栈顶为(0,n,m)，表示要对其分解，将(0,n-1,m)入栈，计算C(n,m-1)的值
		{
			top++;
			stack[top][1]=0;
			stack[top][2]=stack[top-1][2]-1;
			stack[top][3]=stack[top-1][3];
			if (stack[top][3]==0 || stack[top][2]==stack[top][3])
			//若栈顶编号3的值为0或编号2的值等于编号3的值，则给编号1赋初值1
			{
				stack[top][1]=1;	
			}
			tag=1;
		}
		if (top>=2 && stack[top][1]>0 && stack[top-1][1]==0)
		//若栈顶编号1的值大于0且次栈顶编号1的值为0，表示C(n,m-1)部分已计算，该求C(n-1,m-1)部分，将(0,n-1,m-1)入栈
		{
			printf("top=%d:%8d,%8d,%8d\n",top,stack[top][1],stack[top][2],stack[top][3]);
			top++;
			stack[top][1]=0;
			stack[top][2]=stack[top-2][2]-1;
			stack[top][3]=stack[top-2][3]-1;
			if (stack[top][3]==0 || stack[top][2]==stack[top][3])
			//若栈顶编号2的值为0或编号2的值等于编号3的值，则得到编号1的值1
				stack[top][1]=1;
			tag=1;
		}
		if (top>2 && stack[top][1]>0 && stack[top-1][1]>0)
		//若栈顶和次栈顶编号1的值都大于0，则退栈两次，计算新栈顶编号1之值
		{
			if(tag)
			{
				printf("top=%d:%8d,%8d,%8d\n",top,stack[top][1],stack[top][2],stack[top][3]);
				tag=0;
			}	
			s1=stack[top][1];
			s2=stack[top-1][1];
			top=top-2;
			stack[top][1]=s1+s2;
		}
	} while (top>1);//当栈中只有一个元素时，则计算完成，退出循环
	return(stack[1][1]);
}
