#include <iostream>
using namespace std;

int EuclideanGCD(int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    else
    {
        return EuclideanGCD(b, r);
    }
}

int main()
{
    int a,b;
    cout << "Enter two numbers: " << endl;
    cout << "Enter the larger number: " << endl;
    cin >> a;
    cout << "Enter the smaller number: " << endl;
    cin >> b;
    cout << "GCD of " << a << " and " << b << " is " << EuclideanGCD(a, b) << endl;
}