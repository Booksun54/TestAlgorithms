# BF算法(字符串匹配暴力算法)

```
int index(const string &Tag,const string &Ptn,int pos)  
{  
    int i = pos;  //主串当前正待比较的位置，初始为pos  
    int j = 0;   //子串当前正待比较的位置，初始为0  
    int Tlen = Tag.size();  //主串长度  
    int Plen = Ptn.size();  //子串长度  
    
    while(i<Tlen && j<plen)
    {
        //用now_pos表示每次重新进行匹配时开始比较的位置，则  
        //i=now_pos+后移量
        //j=0+后移量  
        //则i-j+1=now_pos+1,即为Tag中下一轮开始比较的位置  
        //则j就是后移量
        if(Tag[i]==Ptn[j])
        {
            i++;
            j++;
        }
        else //如果当前字符不同则回退
        {
            i = i - j + 1;//重新匹配的下一个字符
            j = 0;
        }
    }
```
