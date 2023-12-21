#include <iostream>
using namespace std;

int getMin (int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int getMax (int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

void getMinMax (int numbers[], int size, int* min, int* max) {
    *min = numbers[0];
    *max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < *min) {
            *min = numbers[i];
        }
        if (numbers[i] > *max) {
            *max = numbers[i];
        }
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Min: " << getMin(numbers, size) << endl;
    cout << "Max: " << getMax(numbers, size) << endl;
    int min, max;
    getMinMax(numbers, size, &min, &max);
    cout << "Min with pass by reference: " << min << endl;
    cout << "Max with pass by reference: " << max << endl;
    return 0;
}