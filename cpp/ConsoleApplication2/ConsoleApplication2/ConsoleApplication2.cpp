//输入一个正整数n，输出[1, n]之间的所有完数。
//完数的定义：除自身外的因子之和等于它本身。
//例如：6 = 1 + 2 + 3，因此6是完数。
#include <iostream>
using namespace std;
int main()
{
    int a, b = 0;
    cin >> a;
    for (int i = 1; a >= i; i++)
    {
        b = 0;
        for (int i1 = 1; i > i1; i1++)
        {

            if (i % i1 == 0)
            {
                b = b + i1;
            }
            if (b == i && i / (i1 + 1) == 1)
            {
                cout << i << " ";
                break;
            }
        }
    }
}

