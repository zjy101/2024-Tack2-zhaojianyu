//输入一个正整数n，输出[2,n]之间所有的素数及素数个数。
#include <iostream>

using namespace std;

int main()
{
    int a, b = 2, c = 0, d, i;
    for (cin >> a; a >= b; b++)
    {
        //cout<<b<<" ";
        i = 2;
        for (1; b >= i; i++)
        {
            if (b / i == 1)
            {
                cout << b << " ";
                c = c + 1;
                break;
            }
            else if (b % i == 0)
            {
                break;
            }
        }

    }
    cout << endl;
    cout << c;
    return 0;
}

