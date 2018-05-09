#define MaxLen 255
typedef struct
{
    char str[MaxLen];
    int length;
}SeqString;
void StrAssign(SeqString *S,char cstr[]) 
/*串的赋值操作*/
{
	int i=0;
	for(i=0;cstr[i]!='\0';i++)	/*将常量cstr中的字符赋值给串S*/
		S->str[i]=cstr[i];
	S->length=i;
}
int StrEmpty(SeqString S)   
/*判断串是否为空，串为空返回1，否则返回0*/
{
    if(S.length==0)			/*如果串的长度等于0*/
        return 1;			/*返回1*/
    else                    /*否则*/
        return 0;            /*返回0*/
}
int StrLength(SeqString S) 
/*求串的长度*/
{
	return S.length;
}
void StrCopy(SeqString *T,SeqString S) 
/*串的复制操作.*/
{
	int i;
	for(i=0;i<S.length;i++)		/*将串S的字符赋值给串T*/
		T->str[i]=S.str[i];
	T->length=S.length; 		/*将串S的长度赋值给串T*/
}
int StrCompare(SeqString S,SeqString T)
/*串的比较操作*/
{
	int i;
	for(i=0;i<S.length&&i<T.length;i++)	/*从第一个字符开始比较两个串中的字符*/
		if(S.str[i]!=T.str[i]) 			/*如果有不相等的字符*/
			return (S.str[i]-T.str[i]);      /*返回两个字符的差值*/
		return (S.length-T.length); 			/*如果比较完毕，返回两个串的长度的差值*/
}
int StrInsert(SeqString *S,int pos,SeqString T)
/*串的插入。在S中第pos个位置插入T分为三种情况*/
{
	int i;
	if(pos<0||pos-1>S->length) 		/*插入位置不正确，返回0*/
	{
		printf("插入位置不正确");
		return 0;
	}
	if(S->length+T.length<=MaxLen)/*第1种情况，插入子串后串长≤MaxLen，子串T完整地插入到串S中*/
	{
		/*在插入子串T前，将S中pos后的字符向后移动len个位置*/
		for(i=S->length+T.length-1;i>=pos+T.length-1;i--)
			S->str[i]=S->str[i-T.length];
		/*将串插入到S中*/
		for(i=0;i<T.length;i++)
			S->str[pos+i-1]=T.str[i];
		S->length=S->length+T.length;
		return 1;
	}
	/*第2种情况，子串可以完全插入到S中，但是S中的字符将会被截掉*/
	else if(pos+T.length<=MaxLen)
	{
		for(i=MaxLen-1;i>T.length+pos-1;i--)	/*将S中pos以后的字符整体移动到数组的最后*/
			S->str[i]=S->str[i-T.length];
		for(i=0;i<T.length;i++)					/*将T插入到S中*/
			S->str[i+pos-1]=T.str[i];
		S->length=MaxLen;
		return 0;
	}
	/*第3种情况，子串T不能被完全插入到S中，T中将会有字符被舍弃*/
	else
	{
		for(i=0;i<MaxLen-pos;i++)			/*将T直接插入到S中，插入之前不需要移动S中的字符*/
			S->str[i+pos-1]=T.str[i];
		S->length=MaxLen;
		return 0;
	}
}
int StrDelete(SeqString *S,int pos,int len)
/*在串S中删除pos开始的len个字符*/
{
	int i;
	if(pos<0||len<0||pos+len-1>S->length)		/*如果参数不合法，则返回0*/
	{
		printf("删除位置不正确，参数len不合法");
		return 0;
	}
	else
	{
		for(i=pos+len;i<=S->length-1;i++)		/*将串S的第pos个位置以后的len个字符覆盖掉*/
			S->str[i-len]=S->str[i];
		S->length=S->length-len; 				/*修改串S的长度*/
		return 1;
	}
}
int StrConcat(SeqString *T,SeqString S)
/*将串S连接在串T的末尾*/
{
	int i,flag;
	/*第1种情况，连接后的串长小于等于MaxLen，将S直接连接在串T末尾*/
	if(T->length+S.length<=MaxLen)
	{
		for(i=T->length;i<T->length+S.length;i++)	/*串S直接连接在T的末尾*/
			T->str[i]=S.str[i-T->length];
		T->length=T->length+S.length; 			/*修改串T的长度*/
		flag=1; 							/*修改标志，表示S完整连接到T中*/
	}
	/*第2种情况，连接后串长大于MaxLen，S部分被连接在串T末尾*/
	else if(T->length<MaxLen)
	{
		for(i=T->length;i<MaxLen;i++)			/*将串S部分连接在T的末尾*/
			T->str[i]=S.str[i-T->length];
		T->length=MaxLen; 				     /*修改串T的长度*/
		flag=0; 							/*修改标志，表示S部分被连接在T中*/
	}
	return flag;
}
void StrClear(SeqString *S) 
/*清空串，只需要将串的长度置为0即可*/
{
	S->length=0;
}