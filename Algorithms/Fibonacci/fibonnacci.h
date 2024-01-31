//
//  fibonnacci class.h
//  fibonacci with memoisation
//
//  Created by Samanvay M S on 10/1/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Fibonacci {
    vector<int> temp; // Using vector for automatic memory management
    
public:
    Fibonacci() {} // Constructor

    int fibonacci_memo(int n) {
        if (n <= 1) {
            temp[n] = n;
            return temp[n];
        }
        if (temp[n] != -1) {
            return temp[n];
        }
        temp[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
        return temp[n];
    }

    int solve(int n) {
        if (n <= 0) {
            return 0;
        }
        temp.resize(n + 1, -1);
        cout << endl;
        int last_number = fibonacci_memo(n);
        cout << "sequence is :- " << endl;
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
        return last_number;
    }
};

