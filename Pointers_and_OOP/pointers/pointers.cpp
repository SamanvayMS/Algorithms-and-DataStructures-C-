#include <iostream>
using namespace std;

int main()
{

    int a = 5;
    cout << "a = " << a << endl;
    cout << "address of a (&a) = " << &a << endl;
    int* p = &a;
    cout << "p = " << p << endl;
    cout << "address of p (&p) = " << &p << endl;
    cout << "value of p (*p) = " << *p << endl;

    int** x = &p;
    cout << "x = " << x << endl;
    cout << "address of x (&x) = " << &x << endl;
    cout << "value of x (*x) = " << *x << endl;
    cout << "value of x accessed twice (**x) = " << **x << endl;
    return 0;    
}
