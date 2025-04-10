#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    void input() {
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter name: ";
        cin.ignore(); // clear buffer
        getline(cin, name);
        cout << "Enter marks (0-100): ";
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Invalid marks!\n";
            marks = 0;
        }
    }

    void display() const {
        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

class StudentManager {
    vector<Student> students;
    string filename = "students.txt";

public:
    void load() {
        ifstream file(filename);
        if (!file) {
            cout << "No existing data.\n";
            return;
        }

        Student s;
        while (file >> s.roll) {
            file.ignore();
            getline(file, s.name);
            file >> s.marks;
            students.push_back(s);
        }

        file.close();
    }

    void add() {
        Student s;
        s.input();
        students.push_back(s);
    }

    void view() const {
        if (students.empty()) {
            cout << "No records found.\n";
            return;
        }
        for (const auto& s : students)
            s.display();
    }

    void save() {
        ofstream file(filename);
        for (const auto& s : students)
            file << s.roll << "\n" << s.name << "\n" << s.marks << "\n";
        file.close();
        cout << "Data saved!\n";
    }
};

int main() {
    StudentManager manager;
    manager.load();

    int choice;
    do {
        cout << "\n1. Add student\n2. View students Detail\n3. Save & Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            manager.add();
        else if (choice == 2)
            manager.view();
        else if (choice == 3)
            manager.save();
        else
            cout << "Invalid choice!\n";

    } while (choice != 3);

    return 0;
}

