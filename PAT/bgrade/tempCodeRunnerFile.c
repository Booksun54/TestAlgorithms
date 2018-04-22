#include<stdio.h>

int main()
{
    int i ,count,a,b,c,e,f,g;
    char d[105];
    scanf("%d",&count);
    for(i=0;i<count;i++)
    {
        a=b=c=e=f=g=0;
        scanf("%s",d);
        for(i=0;d[i]!='\0';i++)
        {
            if(d[i]!='P' && d[i]!='A' && d[i]!='T')
            {
                a=b=c=0;
                continue;
            }
            if(d[i]=='P')
            {
                a=1;
                e=i;
            }
            if(a==1 && d[i]=='A'&&c==0)
            {
                b=1;
                f++;
            }
            if(a==1 && b==1 &&d[i]=='T')
            {
                c=1;
            }
            if(a==1 && b==1 && c==1&&d[i]=='A')
            {
                g++;
            }
        }
        if(a==1 && b==1 && c==1 && g==e*f)
        {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        //printf("%d %d %d",e,f,g);

    }
    return 0;
}