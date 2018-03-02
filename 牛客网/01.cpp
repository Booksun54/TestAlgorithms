#include <iostream>
#include <string>

using namespace std;
int main()
{
    string a[100], tmp;
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
            {

                if (a[j] + a[j + 1] > a[j + 1] + a[j])
                {
                    tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
            }
        for (int i = n - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
}