#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Base class
class Person {
protected:
    int roll;
    string name;

public:
    Person() : roll(0), name("") {}
    Person(int r, string n) : roll(r), name(n) {}

    virtual void input() {
        cout << "Roll No: ";
        cin >> roll;
        cout << "Name: ";
        cin >> name;
    }

    virtual void display() const {
        cout << roll << " " << name;
    }

    int getRoll() const { return roll; }
    string getName() const { return name; }
};

// Derived class
class Student : public Person {
    int marks;

public:
    Student() : Person(), marks(0) {}
    Student(int r, string n, int m) : Person(r, n), marks(m) {}

    void input() override {
        Person::input();
        cout << "Marks (0–100): ";
        cin >> marks;

        while (marks < 0 || marks > 100) {
            cout << "Invalid marks! Enter again (0–100): ";
            cin >> marks;
        }
    }

    void display() const override {
        Person::display();
        cout << " " << marks << endl;
    }

    int getMarks() const { return marks; }

    // File I/O
    static void loadFromFile(const string& filename, vector<Student>& students) {
        ifstream inFile(filename);
        int r, m;
        string n;

        while (inFile >> r >> n >> m) {
            students.push_back(Student(r, n, m));
        }

        inFile.close();
    }

    static void saveToFile(const string& filename, const vector<Student>& students) {
        ofstream outFile(filename);
        for (const auto& s : students) {
            outFile << s.getRoll() << " " << s.getName() << " " << s.getMarks() << endl;
        }
        outFile.close();
    }
};

int main() {
    string filename = "students.txt";
    vector<Student> students;

    Student::loadFromFile(filename, students);

    int choice;
    do {
        cout << "\n1. Add Student\n2. Save & Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.input();
            students.push_back(s);
            cout << "Student added.\n";
        } else if (choice == 2) {
            Student::saveToFile(filename, students);
            cout << "Records saved. Exiting...\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 2);

    return 0;
}
