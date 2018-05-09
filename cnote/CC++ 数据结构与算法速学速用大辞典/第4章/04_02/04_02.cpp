#include<iostream.h>
#define MAX 255
void ftoa(double f,char s[]);
void main()
{
	double f;
	char s[MAX];
	cout<<"请输入一个浮点数:"<<endl;
	cin>>f;
	ftoa(f,s);
	cout<<"转换后的字符串为:"<<s<<endl;	
}
void ftoa(double f,char s[])
{
	int i,j,len,t,n;
	double sign;
	if((sign=f)<0) 
		f=-f;
	n=(int)f;
	i=0;
	do 
	{
		s[i++]=n%10+48;
	} while(n/=10);
	if(sign<0)
		s[i++]='-';
	len=i;
	for(i=0,j=len-1;i<len/2;i++,j--)
	{
		t=s[i];
		s[i]=s[j];
		s[j]=t;
	}
	f-=(int)f;
	s[len++]='.';
	for(i=0;i<4;i++)
	{
		f*=10;
		s[len++]=((int)f)%10+48;
	}
	while(s[len-1]=='0')
		len--;
	s[len]='\0';
}