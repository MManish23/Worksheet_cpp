#include <iostream>
using namespace std;

// Max of two integers
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

// Max of two floats
float findMax(float a, float b) {
    return (a > b) ? a : b;
}

// Max of three integers
int findMax(int a, int b, int c) {
    return max(a, max(b, c)); // Using built-in max
}

// Max of int and float
float findMax(int a, float b) {
    return (a > b) ? a : b;
}

int main() {
    int a, b, c;
    float x, y;

    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Max: " << findMax(a, b) << endl;

    cout << "Enter two number in floats: ";
    cin >> x >> y;
    cout << "Max: " << findMax(x, y) << endl;

    cout << "Enter three integers: ";
    cin >> a >> b >> c;
    cout << "Max: " << findMax(a, b, c) << endl;

    cout << "Enter one integer and one float: ";
    cin >> a >> x;
    cout << "Max: " << findMax(a, x) << endl;

    return 0;
}

