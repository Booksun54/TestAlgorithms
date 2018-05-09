#include<stdio.h>
typedef struct{
	char name[20];
	char sex;  /*性别，'F'或'f'表示女性，'M'或'm'表示男性*/
}Person;
typedef Person DataType;  /* 将队列中元素的数据类型改为Person */
#include"SeqQueue.h"
void DancePartner(DataType dancer[],int num)
/*结构数组dancer中存放跳舞的男女，num是跳舞的人数*/
{
	int i;
	DataType p;
	SeqQueue Mdancers,Fdancers;
	InitQueue(&Mdancers);/*男士队列初始化*/
	InitQueue(&Fdancers);/*女士队列初始化*/
	for(i=0;i<num;i++){/*依次将跳舞者依其性别入队*/
		p=dancer[i];       
		if(p.sex=='F'||p.sex=='f')
			EnQueue(&Fdancers,p);   /*排入女队*/
		else
			EnQueue(&Mdancers,p);   /*排入男队*/
	}
	printf("配对成功的舞伴分别是: \n");
	while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers)){
		/*依次输入男女舞伴名*/
		DeQueue(&Fdancers,&p);     /*女士出队*/
		printf("%s   ",p.name);/*打印出队女士名*/
		DeQueue(&Mdancers,&p);     /*男士出队*/
		printf("%s\n",p.name);    /*打印出队男士名*/
	}
	if(!QueueEmpty(Fdancers)){ /*输出女士剩余人数及队头女士的名字*/
		printf("还有%d名女士等待下一轮舞曲.\n",DancerCount(Fdancers));
		GetHead(Fdancers,&p);  /*取队头*/
		printf("%s 将在下一轮中最先得到舞伴. \n",p.name);
	}
	else if(!QueueEmpty(Mdancers)){/*输出男队剩余人数及队头者名字*/
		printf("还有%d名男士等待下一轮舞曲.\n",DancerCount(Mdancers));
		GetHead(Mdancers,&p);
		printf("%s 将在下一轮中最先得到舞伴.\n",p.name);
	}
}  
int DancerCount(SeqQueue Q)
/*队列中等待配对的人数*/
{
	return (Q.rear-Q.front+QueueSize)%QueueSize;
}
void main()
{
	int i,n;
	DataType dancer[30];
	printf("请输入舞池中排队的人数:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("姓名:");
		scanf("%s",dancer[i].name);
		getchar();
		printf("性别:");
		scanf("%c",&dancer[i].sex);
	}
	DancePartner(dancer,n);
}