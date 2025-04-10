#include <iostream>
using namespace std;

class Circle {
public:
    float radius;

    Circle(float r) {
        radius = r;
    }

    float area() {
        return 3.14 * radius * radius;
    }
};

void compare(Circle c1, Circle c2) {
    float a1 = c1.area();
    float a2 = c2.area();

    cout << "Area of Circle 1: " << a1 << endl;
    cout << "Area of Circle 2: " << a2 << endl;

    if (a1 > a2)
        cout << "Circle 1 is larger.\n";
    else if (a2 > a1)
        cout << "Circle 2 is larger.\n";
    else
        cout << "Both circles have the same area.\n";
}

int main() {
    float r1, r2;

    cout << "Enter radius of Circle 1: ";
    cin >> r1;

    cout << "Enter radius of Circle 2: ";
    cin >> r2;

    Circle c1(r1), c2(r2);
    compare(c1, c2);

    return 0;
}

