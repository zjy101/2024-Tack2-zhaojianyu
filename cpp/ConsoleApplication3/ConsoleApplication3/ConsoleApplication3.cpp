//输入若干个整数，以0结束，计算这些非0数据的平均值。
#include <iostream>
using namespace std;
int main()
{
    double a, b, c = 0, i = 0;
    while (1)
    {
        cin >> b;
        if (b == 0)
        {
            break;
        }
        c = c + b;
        i++;
    }
    c = c / i;
    cout << c;
}
