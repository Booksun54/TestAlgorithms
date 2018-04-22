#include<stdio.h>
#include<string.h>

/*

 数学水题 判断P之前A有a个 P、T之间A有b个 T之后的A有c个
 c = a * b
 且满足三个条件
 
 */
int main()
{
    char s[1001];
    int i,n,a,b,c;
    char *p;
    scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
        scanf("%s",&s);
        if(!strcmp(s,"PAT")){printf("YES\n");continue;}   //条件一
  
                a=b=c=0;
                p=s;
                while(*p=='A'){a++;p++;}   //a为第一个p前a的个数
                if(*p=='P'){
                        p++;
                        while(*p=='A'){b++;p++;}   //b为夹在p和t之间的a的个数
                        if(*p=='T'){
                                p++;
                                while(*p=='A'){c++;p++;}   //c为t之后的a的个数
                                if(!(*p) && b>0 && c==a*b){printf("YES\n");continue;}  //条件三
                        }
                }
                printf("NO\n");
          
    }
    return 0;
}