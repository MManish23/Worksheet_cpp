#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
protected:
    string regNo, color;
public:
    Vehicle(string r, string c) : regNo(r), color(c) {}

    virtual void writeToFile(ofstream& file) {
        file << "Registration Number: " << regNo << "\nColor: " << color << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int seats;
public:
    Car(string r, string c, int s) : Vehicle(r, c), seats(s) {}

    void writeToFile(ofstream& file) override {
        Vehicle::writeToFile(file);
        file << "Seats: " << seats << "\n---\n";
    }
};

class Bike : public Vehicle {
    int engineCC;
public:
    Bike(string r, string c, int cc) : Vehicle(r, c), engineCC(cc) {}

    void writeToFile(ofstream& file) override {
        Vehicle::writeToFile(file);
        file << "Engine: " << engineCC << " CC\n---\n";
    }
};

int main() {
    int choice;
    string reg, color;
    ofstream file("vehicle_details.txt", ios::app);

    if (!file) {
        cout << "File error.\n";
        return 1;
    }

    cout << "1 for Car\n2 for Bike\nChoose: ";
    cin >> choice;
    cin.ignore();

    cout << "Registration Number: ";
    getline(cin, reg);
    cout << "Color: ";
    getline(cin, color);

    if (choice == 1) {
        int seats;
        cout << "Seating Capacity: ";
        cin >> seats;
        Car c(reg, color, seats);
        c.writeToFile(file);
    } else if (choice == 2) {
        int cc;
        cout << "Engine (CC): ";
        cin >> cc;
        Bike b(reg, color, cc);
        b.writeToFile(file);
    } else {
        cout << "Invalid choice.\n";
    }

    cout << "Details saved.\n";
    file.close();
    return 0;
}

