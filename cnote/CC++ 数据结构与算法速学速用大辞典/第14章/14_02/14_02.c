#include<stdio.h>
const int COCKPRICE = 3; /*一只公鸡的价格*/ 
const int HENPRICE = 5;  /*一只母鸡的价格*/ 
const int CHICKS = 3;   /*一元钱能买的小鸡数量*/ 
void Scheme(int money, int chooks);/*计算并输出购买方案*/
void main()
{
	int money = 100;/*钱的总数*/
	int chooks = 100;/*鸡的总数*/
	printf("购买方案如下:\n");
	Scheme(money, chooks);/*计算并输出购买方案*/     
}
void Scheme(int money, int chooks) 
/*计算并输出购买方案*/
{
	int maxCock = money / COCKPRICE;    
	int maxHen = money / HENPRICE;    
	int maxChick = chooks;        
	int cock, hen, chick;
	for (cock=0; cock<maxCock; ++cock)/*枚举公鸡的可能数量*/
	{
		for (hen=0; hen<maxHen; hen++)/*枚举母鸡的可能数量*/
		{
			for (chick=0; chick<maxChick; chick++)/*枚举小鸡的可能数量*/
			{
				/*约束条件*/
				if (0 == chick%CHICKS && cock + hen + chick == chooks 
					&& COCKPRICE*cock + HENPRICE*hen + chick/CHICKS == money) 
				{
					printf("公鸡: %2d, 母鸡: %2d, 小鸡: %2d\n", cock, hen, chick);
				}
			}
		}
	}
}
