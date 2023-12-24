#include <iostream>
#include <memory>
using namespace std;

int main(){

    unique_ptr<int> u_ptr1(new int(5));
    cout << u_ptr1 << endl;
    cout << *u_ptr1 << endl;
    unique_ptr<int> u_ptr2 = std::move(u_ptr1);
    cout << u_ptr1 << endl;
    cout << u_ptr2 << endl;
    cout << *u_ptr2 << endl;
    cout << endl;
    return 0;
}