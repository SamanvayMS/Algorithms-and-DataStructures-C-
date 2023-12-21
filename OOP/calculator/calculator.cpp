#include <iostream>
using namespace std;

// Abstract class for operations
class Operation {
public:
    // Pure virtual function example for Abstract class - it will execute this if not defined in the derived class 
    // also cannot be called as an instance but can be referenced as a pointer
    virtual double execute(double a, double b) = 0; 
    virtual ~Operation() {}
};

// Addition operation
class Addition : public Operation {
public:
    double execute(double a, double b){
        return a + b;
    }
};

// Subtraction operation
class Subtraction : public Operation {
public:
    double execute(double a, double b){
        return a - b;
    }
};

// Multiplication operation
class Multiplication : public Operation {
public:
    double execute(double a, double b){
        return a * b;
    }
};

// Division operation
class Division : public Operation {
public:
    double execute(double a, double b){
        if (b == 0) {
            cerr << "Error: Division by zero" << endl;
            return 0;
        }
        return a / b;
    }
};

// Calculator class
class Calculator {
private:
    Operation* operation; // Pointer to Operation class

public:
    void setOperation(Operation* op) {
        operation = op;
    }

    double calculate(double a, double b) {
        return operation->execute(a, b);
    }
};

int main() {
    Calculator calc;
    Addition add;
    Subtraction sub;
    Multiplication mul;
    Division div;
    double a;
    double b;

    cout << "enter two numbers to test operation on:- " << endl;
    cin >> a >> b;
    // Example usage
    calc.setOperation(&add);
    cout << "Addition: " << calc.calculate(a, b) << endl;

    calc.setOperation(&sub);
    cout << "Subtraction: " << calc.calculate(a, b) << endl;

    calc.setOperation(&mul);
    cout << "Multiplication: " << calc.calculate(a, b) << endl;

    calc.setOperation(&div);
    cout << "Division: " << calc.calculate(a, b) << endl;

    return 0;
};
