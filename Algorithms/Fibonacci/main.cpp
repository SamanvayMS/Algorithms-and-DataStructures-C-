//
//  main.cpp
//  fibonacci with memoisation
//
//  Created by Samanvay M S on 10/1/22.
//

#include <iostream>
#include "fibonnacci.h"
using namespace std;
int main() {
    int N;
    cout << "length of sequence:" << endl;
    cin >> N;
    Fibonacci F;
    int answer = F.solve(N);
    cout<< " fibonacci number at " << N << "th position is " << answer <<endl;
    
    return 0;
}
