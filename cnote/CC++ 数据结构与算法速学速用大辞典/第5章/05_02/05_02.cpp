#include<iostream.h>
#include<iomanip.h>	
#define MAX 100							
void SplitArray(int c[],int n);	
void PrintArray(int a[],int n);	
void main()
{
	int n;			
	int c[]={29,54,68,32,49,21,396,207,181};
	n=sizeof(c)/sizeof(c[0]);
	cout<<"数组c中的元素:"<<endl;
	PrintArray(c,n);
	cout<<"数组c调整后(左边元素为奇数,右边元素为偶数):"<<endl;
	SplitArray(c,n);					/*调整数组中的元素*/
	PrintArray(c,n);
}
void SplitArray(int c[],int n)
/*将数组a分成两个部分：左边是奇数，右边是偶数*/
{
	int i,j,t;					/*定义两个指示器i和j*/
	i=0,j=n-1;		/*指示器i和j分别指示顺序表的左端和右端元素*/
	while(i<j)		
	{
		while(c[i]%2!=0)	/*i遇到奇数元素*/
			i++;				/*略过*/
		while(c[j]%2==0)		/*j遇到偶数元素*/
			j--;				/*略过*/
		if(i<j)					/*交换i和j指向的元素*/
		{
			t=c[i];
			c[i]=c[j];
			c[j]=t;
		}	
	}
}
void PrintArray(int a[],int n)
//输出数组a中的元素
{
	int i;
	for(i=0;i<n;i++)
		cout<<setw(4)<<a[i];
	cout<<endl;
}