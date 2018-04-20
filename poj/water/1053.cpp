    #include<stdio.h>  
    #include<string.h>  
    /* 大数相加 */
    int main()  
    {  
        char sum[103]={0};  
        char s[101];  
        int i,j,len,c;  
        scanf("%s", s);  
        while(1)  
        {  
            //结束条件   
            if(s[0]=='0' && strlen(s)==1) break;  
              
            len = strlen(s);  
            c=0;  
            //将本次输入 累加进结果中   
            for(i=len-1,j=0; i>=0; i--,j++)  
            {  
                sum[j] += s[i]-'0' + c;  
                c = sum[j]/10;  
                sum[j]=sum[j]%10;     
            }  
            //处理累加结束后遗留的进位   
            while(c>0)  
            {  
                sum[j]+=c;  
                c=sum[j]/10;  
                sum[j]=sum[j]%10;  
                j++;  
            }  
      
            scanf("%s", s);  
        }  
        i=102;  
        //去掉前导0   
        while(sum[i]==0) i--;  
        //打印结果   
        if(i<0) printf("%d\n",0);  
        else  
        {  
         while(i>=0) printf("%d", sum[i--]);  
         printf("\n");  
        }  
        return 0;  
    }  