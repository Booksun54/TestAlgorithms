#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqString.h"
#include<iostream.h>
#include<iomanip.h>
int B_FIndex(SeqString S,int pos,SeqString T,int *count);
int KMP_Index(SeqString S,int pos,SeqString T,int next[],int *count);
void GetNext(SeqString T,int next[]);
void PrintArray(SeqString T,int next[],int length);
void main()
{
	SeqString S,T;
	int count1=0,count2=0,find;
	int next[40];
    /*第1个例子*/
	StrAssign(&S,"bcdamnbacabaabaabacababafabacabababab");		/*给主串S赋值*/
	StrAssign(&T,"abaabacababa");				/*给模式串T赋值*/
	GetNext(T,next);					/*求next函数值*/
	cout<<"模式串T的next和改进后的next值:"<<endl;
	PrintArray(T,next,StrLength(T));	/*输出模式串T的next值*/
	find=B_FIndex(S,1,T,&count1);				/*Brute-Force模式串匹配*/
	if(find>0)
		cout<<"Brute-Force算法的比较次数为:"<<count1<<endl;
	find=KMP_Index(S,1,T,next,&count2);
	if(find>0)
		cout<<"利用next的KMP算法的比较次数为:"<<count2<<endl;
    /*第2个例子*/
	StrAssign(&S,"bcdabcacbdaacabcabaacaabcabcabcbccbcabccbdcabcb");		/*给主串S赋值*/
	StrAssign(&T,"abcabcbc");						/*给模式串T赋值*/
	GetNext(T,next);							/*求next函数值*/
	PrintArray(T,next,StrLength(T));			/*输出模式串T的next值*/
	find=B_FIndex(S,1,T,&count1);					/*Brute-Force模式串匹配*/
	if(find>0)
		cout<<"Brute-Force算法的比较次数为:"<<count1<<endl;
	find=KMP_Index(S,1,T,next,&count2);
	if(find>0)
		cout<<"利用next的KMP算法的比较次数为:"<<count2<<endl;
}
void PrintArray(SeqString T,int next[],int length)
/*模式串T的next值输出函数*/
{
	int j;
	cout<<"j:\t\t";
	for(j=0;j<length;j++)
		cout<<setw(3)<<j;
	cout<<endl;
	cout<<"模式串:\t\t";
	for(j=0;j<length;j++)
		cout<<setw(3)<<T.str[j];
	cout<<endl;
	cout<<"next[j]:\t";
	for(j=0;j<length;j++)
		cout<<setw(3)<<next[j];
	cout<<endl;
}
int B_FIndex(SeqString S,int pos,SeqString T,int *count) 
/*在主串S中的第pos个位置开始查找子串T，如果找到返回子串在主串的位置；否则，返回-1*/
{
	int i,j;
	i=pos-1;
	j=0;
	*count=0;						/*count保存主串与模式串的比较次数*/
	while(i<S.length&&j<T.length)
	{
		if(S.str[i]==T.str[j]) 		/*若串S和串T中对应位置字符相等，则继续比较下一个字符*/
		{
			i++;
			j++;
		}
		else		/*若当前对应位置的字符不相等，则从串S的下一个字符开始，T的第0个字符开始比较*/
		{
			i=i-j+1;
			j=0;
		}
		(*count)++;
	}
	if(j>=T.length) 				/*如果在S中找到串T，则返回子串T在主串S的位置*/
		return i-j+1;
	else
		return -1;
}
int KMP_Index(SeqString S,int pos,SeqString T,int next[],int *count)
/*KMP模式匹配算法。利用模式串T的next函数在主串S中的第pos个位置开始查找子串T，如果找到返回子串在主串的位置；否则，返回-1*/
{
    int i,j;
    i=pos-1;
    j=0;
	*count=0;								/*count保存主串与模式串的比较次数*/
    while(i<S.length&&j<T.length)
    {
        if(j==-1||S.str[i]==T.str[j])		/*如果j=-1或当前字符相等，则继续比较后面的字符*/
        {
            i++;
            j++;
        }
        else						/*如果当前字符不相等，则将模式串向右移动*/
            j=next[j];
		(*count)++;
    }
    if(j>=T.length) 					/*匹配成功，返回子串在主串中的位置。否则返回-1*/
        return i-T.length+1;
    else
        return -1;
}
void GetNext(SeqString T,int next[])
/*求模式串T的next函数值并存入数组next*/
{
    int j,k;
    j=0;
	k=-1;
    next[0]=-1;
    while(j<T.length)
    {
        if(k==-1||T.str[j]==T.str[k])		/*如果k=-1或当前字符相等，则继续比较后面的字符并将函数值存入到next数组*/
        {
            j++;
            k++;
            next[j]=k;
        }
        else						/*如果当前字符不相等，则将模式串向右移动继续比较*/
            k=next[k];
    }
}
