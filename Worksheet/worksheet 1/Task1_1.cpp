#include <iostream>
using namespace std;

void convertTemperature() {
    double temp, converted_temp;
    char choice;

    cout << "Enter the temperature value: ";
    if (!(cin >> temp)) {
        cout << "Invalid input. Please enter a numeric value for temperature." << endl;
        return;
    }

    cout << "Convert to Celsius or Fahrenheit? \n Enter C for Celsius or F for Fahrenheit : ";
    cin >> choice;

    choice = toupper(choice);

    if (choice == 'C') {
        converted_temp = (temp - 32) * 5 / 9;
        cout << temp << " Fahrenheit is equal to " << converted_temp << " Celsius." << endl;
    } else if (choice == 'F') {
        converted_temp = (temp * 9 / 5) + 32;
        cout << temp << " Celsius is equal to " << converted_temp << " Fahrenheit." << endl;
    } else {
        cout << "Invalid choice. Please enter 'C' or 'F'." << endl;
    }
}

int main() {
    convertTemperature();
    return 0;
}

