#include<iostream>
#include<string>
using namespace std;
//任意进制之间的转换

/**
* s1  转换之前的数
* s2  转换之后的数
* d1  原进制数
* d2  需要转到的进制数
*     高于9的位数用大写'A'～'Z'表示，2～16位进制通过验证
*/
void conversion(string s1,string &s2,long d1,long d2){

    //思路，还是将原数转换成十进制数 -> 再由十进制数转换成目标进制的数
    long i, j, t, num;
    char c;
    num = 0;
    //先转换成十进制数
    for ( i = 0; i < s1.size(); i++){
        if (s1[i] >= '0'&&s1[i] <= '9'){
            t = s1[i] - '0';
        }
        else t = s1[i] - 'A' + 10;
        //参考十进制的方式
        num = num*d1 + t;
     }
    i = 0;
    s2 = "";
    while (1){

        t = num%d2;
        num /= d2;
        if (t <= 9)s2 = to_string(t)+ s2;
        else s2 = (char)((t - 10 + 'A')) + s2;
        if (num == 0)break;
    }

}

//测试函数
int main(){

    string str1, str2;
    long d1, d2;
    while (cin >> str1 >> d1 >> d2){

        conversion(str1, str2,d1, d2);
        cout << str2 << endl;
    }


    return 0;
}