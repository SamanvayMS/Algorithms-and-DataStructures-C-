#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows]; //initialise a list of pointers to int , each of these pointers is going to reference a separate list 
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]; // initialise a list of ints for each pointer in the list of pointers
    }

    for (int i = 0; i < rows; i++) { // fill the matrix with values
        for (int j = 0; j < cols; j++) {
            cout << "Enter value for row " << i + 1 << " and column " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix: " << endl;

    for (int i = 0; i < rows; i++) { // print the matrix
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "accessing first element: **matrix : " << **matrix << endl;
    cout << "accessing second element: *(*matrix + 1) " << *(*matrix + 1) << endl;
    cout << "accessing first element of second row: *(*(matrix + 1)) " << *(*(matrix + 1)) << endl;
    cout << "accessing second element of second row: *(*(matrix + 1) + 1) " << *(*(matrix + 1) + 1) << endl;

    cout << "Iterating through the matrix by passing via reference and incrementing adresses: " << endl;
    for (int i = 0; i < rows; i++) { // delete the list of pointers
        for (int j = 0; j < cols; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++) { // delete the matrix
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}