/* 判断水仙花数 判断Armstrong数(阿姆斯壮数)
Armstrong 数，就是n位数的各位数的n次方之和等于该数，如：
153=1^3+5^3+3^3
1634=1^4+6^4+3^4+4^4
 */
#include <stdio.h>
int main()
{
    int number, originalNumber, remainder, result = 0;
 
    printf("输入三位数: ");
    scanf("%d", &number);
 
    originalNumber = number;
 
    while (originalNumber != 0)
    {
        remainder = originalNumber%10;
        result += remainder*remainder*remainder;
        originalNumber /= 10;
    }
 
    if(result == number)
        printf("%d 是 Armstrong 数",number);
    else
        printf("%d 不是 Armstrong 数",number);
 
    return 0;
}

