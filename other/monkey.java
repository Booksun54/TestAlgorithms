/* 
���ӳ�������
һֻ����ժ��һ��ƻ����ԭ�ƻ�15����ꡣ����һ�����������һ���һ����
�ڶ������ʣ�µ�ƻ����һ���һ��������10�췢��ֻʣ��һ��ƻ���ˡ��ʣ�һ���ж���ƻ��
f(n) = f(n-1) - (f(n-1)/2 + 1))

f(n-1) = 2f(n) + 2

f(10) = 1

��f(1)
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
        System.out.println("һ����:"+f(1)+"��ƻ��"); 

	}
}

