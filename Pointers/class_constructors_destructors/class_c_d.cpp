#include <iostream>
#include <memory>

using namespace std;

class MyClass{
    public:
        MyClass(){
            cout << "Constructor called" << endl;
        }
        ~MyClass(){
            cout << "Destructor called" << endl;
        }
};

int main(){
    unique_ptr<MyClass> u_ptr1(new MyClass);
    return 0;
}