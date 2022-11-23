#include <iostream>
#include <vector>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    if (n % 2 != 0)
        return x * myPow(x, n - 1);
    else
        return myPow(x * x, n / 2);
}
int main()
{

    double x, n;
    cout << "Enter x , n  : ";
    cin >> x >> n;
    cout << myPow(x, n);

    return 0;
}