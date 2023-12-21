#include <iostream>
using namespace std;

int main(){

    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int* numbers = new int[size]; // new allocates memory when needed 
    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }
    cout << "Numbers: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    delete[] numbers; // delete deallocates memory when needed
    numbers = nullptr; // set pointer to null to avoid dangling pointer
    return 0;
}