#define QUEUESIZE 20		/*定义顺序循环队列的最大容量*/
#include<math.h>
typedef int DataType;		/*定义顺序循环队列元素的类型为整数类型*/
#define MAXSIZE 100
#include<stdio.h>			/*包含头文件，主要包含输入输出函数*/
typedef struct Squeue{		/*顺序循环队列的类型定义*/      
	DataType queue[QUEUESIZE];
	int front,rear;		/*队头指针和队尾指针*/
	int tag;			/*队列空、满的标志*/
}SCQueue;                       
void PrintData(DataType e);
int CheckType(DataType e);
void InitQueue(SCQueue *SCQ)  
/*将顺序循环队列初始化为空队列，需要把队头指针和队尾指针同时置为0，且标志位置为0*/  
{
    SCQ->front=SCQ->rear=0;		/*队头指针和队尾指针都置为0*/
	SCQ->tag=0;					/*标志位置为0*/
}
int QueueEmpty(SCQueue SCQ)   
/*判断顺序循环队列是否为空，队列为空返回1，否则返回0*/
{
	if(SCQ.front==SCQ.rear&&SCQ.tag==0)	/*队头指针和队尾指针都为0且标志位为0表示队列已空*/
		return 1;
	else
		return 0;
}
int EnQueue(SCQueue *SCQ,DataType e)
/*将元素e插入到顺序循环队列SQ中，插入成功返回1，否则返回0*/
{
	if(SCQ->front==SCQ->rear&&SCQ->tag==1)  
		/*在插入新的元素之前，判断是否队尾指针到达数组的最大值，即是否上溢*/
	{
		printf("顺序循环队列已满，不能入队！");
		return 1;
	}
	else
	{
		SCQ->queue[SCQ->rear]=e;		/*在队尾插入元素e */
		SCQ->rear=SCQ->rear+1;			/*队尾指针向后移动一个位置，指向新的队尾*/
		SCQ->tag=1;					/*插入成功，标志位置为1 */
		return 1;
	}
}
int DeQueue(SCQueue *SCQ,DataType *e)
/*删除顺序循环队列中的队头元素，并将该元素赋值给e，删除成功返回1，否则返回0*/
{
	if(QueueEmpty(*SCQ))				/*在删除元素之前，判断队列是否为空*/
	{
        printf("顺序循环队列已经是空队列，不能再进行出队列操作！");
		return 0;
	}
	else
	{
		*e=SCQ->queue[SCQ->front];		/*要出队列的元素值赋值给e */
		SCQ->front=SCQ->front+1;			/*队头指针向后移动一个位置，指向新的队头元素*/
		SCQ->tag=0;					/*删除成功，标志位置为0 */
		return 1;
	}
}
void DisplayQueue(SCQueue SCQ)
/*顺序循环队列的显示输出函数。首先判断队列是否为空，输出时还应考虑队头指针和队尾指针值的大小问题*/
{
	int i;
	if(QueueEmpty(SCQ))				/*判断顺序循环队列是否为空*/
		return;
	if(SCQ.front<SCQ.rear)    
		/*如果队头指针值小于队尾指针的值，则把队头指针到队尾指针指向的元素依次输出*/
		for(i=SCQ.front;i<SCQ.rear;i++)
			printf("%4d",SCQ.queue[i]);
		else
			/*如果队头指针值大于队尾指针的值，则把队尾指针到队头指针指向的元素依次输出*/
			for(i=SCQ.front;i<SCQ.rear+ QUEUESIZE;i++)
				printf("%4d",SCQ.queue[i% QUEUESIZE]);
			printf("\n");	
}
void main()
{
	SCQueue Q;						/*定义一个顺序循环队列*/
	int e;							/*定义一个字符类型变量，用于存放出队列的元素*/
	int a[]={1,2,3,4},i;
	InitQueue(&Q);					/*初始化顺序循环队列*/
	/*将数组中的4个元素依次入列*/
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		EnQueue(&Q,a[i]);
	/*将顺序循环队列中的元素显示输出*/
	printf("队列中元素：");
	DisplayQueue(Q);
	/*将顺序循环队列中的队头元素出队列*/
	i=0;
	while(!QueueEmpty(Q))
	{
		printf("队头元素第%d次出队\n",++i);
		DeQueue(&Q,&e);
		printf("出队的元素：");
		//printf("%d\n",e);
		PrintData(e);
	}
}
void PrintData(DataType e)
/*数据的输出（为了使调用函数不需要格式控制符）*/
{
	int n;
	n=CheckType(e);
	switch(n)
	{
	case 1://字符型
		printf("%4c\n",e);
		break;
	case 2://整型
		printf("%4d\n",e);
		break;
	case 3://浮点型
		printf("%8.2f\n",e);
		break;
	}
}
int CheckType(DataType e)
/*判断e是浮点数，整数还是字母字符*/
{
	char str[MAXSIZE];
	int a;
	float b;
	if(fabs(e-(int)e)>1e-6)//是浮点数
		return 3;
	if(e>='A'&&e<='Z'||e>='a'&&e<='z')//是字母字符
		return 1;
	else //是整数
		return 2;
}


