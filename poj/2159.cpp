#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
/*判断字母出现的次数相同就行了*/
int main()
{
    string input;
    int a[26] = {0} ,  b[26] = {0};
    cin>>input;
    for(int i = 0; i < input.length();i++)
        a[input[i]-'A']++;
    cin>>input;
     for(int i = 0; i < input.length();i++)
        b[input[i]-'A']++;
    sort(a,a+26);
    sort(b,b+26);
    int i;
    for(i = 0; i<26;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}