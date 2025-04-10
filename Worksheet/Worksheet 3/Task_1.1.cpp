#include <iostream>
using namespace std;

class Time {
    int hours, minutes;

public:
    Time(int h = 0, int m = 0) {
        if (h < 0 || h >= 24 || m < 0 || m >= 60) {
            throw "Invalid time! Hours (0-23), Minutes (0-59)";
        }
        hours = h;
        minutes = m;
    }

    void display() const {
        cout << hours << " hrs " << minutes << " mins\n";
    }

    Time operator+(const Time& t) const {
        int total = (hours + t.hours) * 60 + (minutes + t.minutes);
        return Time((total / 60) % 24, total % 60);
    }

    bool operator>(const Time& t) const {
        return (hours * 60 + minutes) > (t.hours * 60 + t.minutes);
    }
};

int main() {
    try {
        int h1, m1, h2, m2;
        cout << "Enter first time in hour and minute): ";
        cin >> h1 >> m1;
        cout << "Enter second time in hour and minute): ";
        cin >> h2 >> m2;

        Time t1(h1, m1), t2(h2, m2), sum = t1 + t2;

        cout << "First : "; t1.display();
        cout << "Second: "; t2.display();
        cout << "Sum of time: "; sum.display();

        cout << (t1 > t2 ? "First is greater.\n" : "Second is greater or equal.\n");

    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
