/* 
猴子吃桃问题
一只猴子摘了一堆苹果，原计划15天吃完。它第一天吃了总数的一半多一个。
第二天吃了剩下的苹果的一半多一个。到第10天发现只剩下一个苹果了。问：一共有多少苹果
f(n) = f(n-1) - (f(n-1)/2 + 1))

f(n-1) = 2f(n) + 2

f(10) = 1

求f(1)
 */
import java.util.*;
class monkey {
    private static int f(int n){
        if(n == 10){
            return 1;
        }else{
            return 2 * f(n + 1) + 2;
        }
    }

    public static void main(String[] args) {
        System.out.println("一共有:"+f(1)+"个苹果"); 

	}
}

