
#include<stdio.h>
typedef int DataType;
#include "SeqQueue.h"
void FerryManage()
{
	SeqQueue bus,truck; /*bus表示客车队列，truck表示货车队列*/
	char ch;
	DataType n;/*n为车号*/
	int tag; /*tag是标志，tag=1表示客车，tag=2表示货车*/
	int count=0,countbus=0,counttruck=0;
	InitQueue(&bus);
	InitQueue(&truck);
	while(1)
	{
		fflush(stdin);
		printf("输入命令(e或E表示入队，o或O表示出队，q或Q表示退出)：\n");
		scanf("%c",&ch);
		switch (ch)
		{
		case 'e':
		case 'E':
			printf("请输入车号(整数)：");
			scanf("%d",&n);
			printf("是客车(1)还是货车(2)：");
			scanf("%d",&tag);
			if (tag==1)
				EnQueue(&bus,n);
			else
				EnQueue(&truck,n);
			break;
		case 'o':
		case 'O':
			while (count<10)
			{
				if (count<4 && !QueueEmpty(bus)) /*客车出队*/
				{
					DeQueue(&bus,&n);
					printf("上船的车号为：%d\n",n);
					count++;
					countbus++;
				}
				else if (!QueueEmpty(truck))/*货车出队*/
				{
					countbus=0;
					DeQueue(&truck,&n);
					printf("上船的车号为：%d\n",n);
					count++;
					counttruck++;
				}
				else if (!QueueEmpty(bus))
				{
					counttruck=0;
					DeQueue(&bus,&n);
					printf("上船的车号为：%d\n",n);
					count++;
					countbus++;
				}
				else
				{
					printf("排队轮渡的车辆少于10辆.\n" );
					return;
				}
			}
			break;
		case 'q':
		case 'Q':
			break;
		}
		if (ch=='q' || ch=='Q')
			break;
	}
}
void main()
{
	FerryManage();
}