#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
} sqStack;

/*
栈初始化过程
*/
void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base)
    {
        printf("分配失败!");
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

//入栈
void Push(sqStack *s, ElemType e)
{
    if (s->top - s->base > s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
        {
            exit(0);
        }
    }
    *(s->top) = e;
    s->top++;
}

//出栈
void Pop(sqStack *s, ElemType *e)
{
    if (s->top == s->base)
    {
        return;
    }

    *e = *--(s->top);
}

//得到栈中的元素
int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    ElemType c;
    sqStack s;
    int len, i, sum = 0;

    InitStack(&s);

    printf("请输入二进制数，#结束!\n");
    scanf("%c", &c);
    while (c != '#')
    {
        Push(&s, c);
        scanf("%c", &c);
    }

    getchar(); //过滤 把'\n'从缓冲区去掉
    len = StackLen(s);
    printf("栈的当前容量是: %d\n", len);

    for (i = 0; i < len; i++)
    {
        Pop(&s, &c);
        sum = sum + (c - 48) * pow(2, i); //将字符转换成数字
    }
    printf("转化为十进制数是: %d\n",sum);
    return 0;
}