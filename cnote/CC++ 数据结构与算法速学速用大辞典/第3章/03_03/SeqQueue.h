#define  QueueSize  100		/*队列的容量*/
typedef struct Squeue{
	DataType queue[QueueSize];
	int front,rear; 		/*队头指针和队尾指针*/
}SeqQueue;
void InitQueue(SeqQueue *SCQ)   
/*顺序循环队列的初始化*/
{
    SCQ ->front=SCQ ->rear=0;	/*把队头指针和队尾指针同时置为0*/
}
int QueueEmpty(SeqQueue SCQ)    
/*判断顺序循环队列是否为空，队列为空返回1，否则返回0*/
{
	if(SCQ.front== SCQ.rear)		/*当顺序循环队列为空时*/
		return 1; 				/*返回1*/
	else						/*否则*/
		return 0; 				/*返回0*/
}
int EnQueue(SeqQueue *SCQ,DataType e)
/*将元素e插入到顺序循环队列SQ中，插入成功返回1，否则返回0*/
{
	if(SCQ->front== (SCQ->rear+1)%QueueSize)
	/*在插入新的元素之前，判断队尾指针是否到达数组的最大值，即是否上溢*/
		return 0;
	SCQ->queue[SCQ->rear]=e;		/*在队尾插入元素e */
	SCQ->rear=(SCQ->rear+1)%QueueSize;		/*队尾指针向后移动一个位置*/
	return 1;
}
int DeQueue(SeqQueue *SCQ,DataType *e)
/*将队头元素出队，并将该元素赋值给e，删除成功返回1，否则返回0*/
{
	if(SCQ->front==SCQ->rear)		/*在删除元素之前，判断顺序循环队列是否为空*/
		return 0;
	else
	{
		*e=SCQ->queue[SCQ->front];		/*将要删除的元素赋值给e*/
		SCQ->front=(SCQ->front+1)%QueueSize;		/*将队头指针向后移动一个位置，指向新的队头*/
		return 1;
	}
}
int GetHead (SeqQueue SCQ,DataType *e)
/*取队头元素，并将该元素赋值给e，取元素成功返回1，否则返回0*/
{
	if(SCQ.front==SCQ.rear)		/*在取队头元素之前，判断顺序循环队列是否为空*/
		return 0;
	else
	{
		*e=SCQ.queue[SCQ.front];	/*将队头元素赋值给e，取出队头元素*/
		return 1;
	}
}
void ClearQueue(SeqQueue *SCQ) 
/*清空队列*/
{
	SCQ->front=SCQ->rear=0;		/*将队头指针和队尾指针都置为0*/
}