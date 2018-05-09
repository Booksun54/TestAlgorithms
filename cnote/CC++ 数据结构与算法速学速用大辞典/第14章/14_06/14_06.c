#include<stdio.h>
void main()
{
	int a,b,c;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
			{
				if(a==0)
					if(b==1)
						if(c==0)
							if(a==1&&b==1)
								printf("%3d,%3d,%3d\n",a,b,c);
							if(b==0)
								if(a==1&&c==1)
									if(a==1||b==1)
										printf("%3d,%3d,%3d\n",a,b,c);
									if(c==0)
										if(a==1&&b==1)
											if(b==0)
												printf("%3d,%3d,%3d\n",a,b,c);
			}
}