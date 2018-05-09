#include<iostream.h>
#include<stdio.h>
#include"SeqString.h"
#define MAX 255
void MaxComStr(SeqString S,SeqString T,int *index,int *length);
void main()
{
	char str1[MAX],str2[MAX];
	int index,length,i;
	SeqString S,T;
	cout<<"请输入第1个字符串:"<<endl;
	cin>>str1;
	StrAssign(&S,str1);
	cout<<"请输入第二个字符串:"<<endl;
	cin>>str2;
	StrAssign(&T,str2);
	MaxComStr(S,T,&index,&length);
	cout<<"最长公共子串为:"<<endl;
	for(i=index;i<index+length;i++)
		cout<<S.str[i];
	cout<<endl;
}
void MaxComStr(SeqString S,SeqString T,int *index,int *length)
//求S和T的最长公共子串
{
	int i,j,k,length1,con;
	*index=0;
	*length=0;
	i=0;
	while(i<S.length)
	{
		j=0;
		while(j<T.length)
		{
			if(S.str[i]==T.str[j])//如果在S和T当前对应字符相等
			{
				k=1;
				length1=1;
				con=1;
				while(con)
				{
					if(i+k<S.length&&j+k<T.length&&S.str[i+k]==T.str[j+k])//如果在S和T的长度内，对应字符相等，则指针k后移比较下一个字符
					{
						length1=length1+1;//当前公共子串长度加1
						k++;
					}
					else
						con=0;//S和T对应的字符不等，则将标记置为0
				}
				if(length1>*length)//如果一次比较结束，当前得到的公共子串长度大于length，则保持到length中
				{
					*index=i;
					*length=length1;
				}
				j+=k;//将T的第j+k个字符起继续与S的第i个字符比较
			}
			else
				j++;//从串T的下一个字符起与S的第i个字符比较
		}
		i++;//将串S的下一个字符开始与T进行比较
	}
}