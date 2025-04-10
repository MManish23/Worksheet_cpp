#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int m1, m2, m3;

    void input() {
        cout << "Enter student's name: ";
        cin >> name;

        cout << "Enter marks for 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }

    int total() {
        return m1 + m2 + m3;
    }

    float average() {
        return total() / 3.0;
    }

    char grade() {
        float avg = average();
        if (avg >= 90) return 'A';
        else if (avg >= 80) return 'B';
        else if (avg >= 70) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }

    void display() {
        cout << "\nName: " << name << endl;
        cout << "Total: " << total() << endl;
        cout << "Average: " << average() << endl;
        cout << "Grade: " << grade() << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.display();
    return 0;
}
