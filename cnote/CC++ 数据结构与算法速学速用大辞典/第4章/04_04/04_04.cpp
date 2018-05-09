#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include"SeqString.h"
void InputString(char str[]);
void MaxEqSubStr(SeqString S,SeqString *T);
void SubString(SeqString S,SeqString *T,int s,int length);
void StrPrint(SeqString S);
void main()
{
	char str[MaxLen];
	SeqString S,T;
	cout<<"请输入一个字符串："<<endl;
	InputString(str);
	StrAssign(&S,str);
	MaxEqSubStr(S,&T);
	cout<<"请输入一个字符串"<<endl;
	InputString(str);
	StrAssign(&S,str);
	MaxEqSubStr(S,&T);
}
void InputString(char str[])
//接受输入的字符
{
	char ch;
	int i=0;
	while((ch=getchar())!='\n')
	{
		str[i++]=ch;
	}
	str[i]='\0';
}
void MaxEqSubStr(SeqString S,SeqString *T)
//求最大等值子串
{
	int i=0,start1=0,start2=0,length1=1,length2=1;//start1,start2存放最大等值子串的起始位置
	while(i<S.length)
	{
		i++;
		if(S.str[i]==S.str[start2])//若当前字符与起始位置字符相等，则长度加1
			length2++;
		else
		{
			if(length2>length1)//若当前最大子串长度较大，则保存之
			{
				start1=start2;
				length1=length2;
			}
			start2=i;//从当前位置重新比较
			length2=1;//恢复长度到原始状态
		}
	}
	if(length1<2)
		cout<<"无等值子串！"<<endl;
	else
	{
		SubString(S,T,start1,length1);
		StrPrint(*T);
	}
}
void SubString(SeqString S,SeqString *T,int s,int length)
//取出S中等长子串到T中
{
	int j=0,i;
	for(i=s;i<s+length;i++)
		T->str[j++]=S.str[i];
	T->length=length;
}
void StrPrint(SeqString S)
{
	int i;
	for(i=0;i<S.length;i++)
		cout<<S.str[i];
	cout<<endl;
}