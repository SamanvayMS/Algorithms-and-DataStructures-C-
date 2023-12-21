#include <iostream>
using namespace std;


void printNumber(int* numberptr){
    cout << *numberptr << endl;
}

void printLetter(char* letterptr){
    cout << *letterptr << endl;
}

void print(void* ptr, char type){
    switch (type)
    {
    case 'i':
        cout << *((int*)ptr) << endl; // adding (int*) before ptr will cast it to an int pointer
        break;
    case 'c':
        cout << *((char*)ptr) << endl; // adding (char*) before ptr will cast it to a char pointer
        break;
    default:
        break;
    }
}

int main()
{
    int number = 5;
    char letter = 'a';  
    printNumber(&number);
    printLetter(&letter);

    print(&number, 'i');
    print(&letter, 'c');
    return 0;
}