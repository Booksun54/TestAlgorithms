#include <stdio.h>
const int leapYear[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int noLeapYear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int isLeapYear( int iYear )
{//判断是否为闰年
	if( iYear < 0 )
		return 0;	
	if( !(iYear % 400) )
		return 1;
	if( !( iYear % 100 ))
		return 0;
	if( !( iYear % 4 ) )
		return 1;
	return 0;
}
int GetDayInYear( int iYear, int iMonth, int iDay )
{//计算某年某月某日是一年中的第几天
	int i;
	int iCurMonth = iMonth - 1;
	int iIndex = 0;
	if( iYear < 0 )
		return -1;
	if( iMonth > 13 || iMonth < 1 )
		return -1;
	if( isLeapYear( iYear ) )//闰年
	{
		for( i = 0; i < iCurMonth; i++ )
		{
			iIndex += leapYear[i];
		}
		if( iDay > leapYear[i] || iDay < 1 )
			return -1;
		iIndex += iDay;
	}
	else//不是闰年
	{
		for( i = 0; i < iCurMonth; i++ )
		{
			iIndex += noLeapYear[i];
		}
		if( iDay > noLeapYear[i] || iDay < 1 )
			return -1;
		iIndex += iDay;
	}
	return iIndex;
}
void main( )
{
	int year,month,day;
	printf("请输入年、月、日:");
	scanf("%d%d%d",&year,&month,&day);
	printf( "%d年%d月%d日是这年的第%d天.\n" ,year,month,day,GetDayInYear( year, month, day ) );
}