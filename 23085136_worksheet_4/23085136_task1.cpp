#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void addPerson(map<string, int>& people, vector<string>& names) {
    string name;
    int age;

    cout << "Enter name: ";
    cin.ignore(); // Clear leftover input
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    people[name] = age;
    names.push_back(name);
}

void showPeopleAboveAge(const map<string, int>& people, int limit) {
    bool found = false;
    cout << "People older than " << limit << ":\n";
    for (auto& person : people) {
        if (person.second > limit) {
            cout << person.first << " (" << person.second << ")\n";
            found = true;
        }
    }
    if (!found) cout << "No one found above that age.\n";
}

void showSortedNames(const vector<string>& names) {
    if (names.empty()) {
        cout << "No names to display.\n";
        return;
    }

    vector<string> sortedNames = names;
    sort(sortedNames.begin(), sortedNames.end());

    cout << "Names in alphabetical order:\n";
    for (const string& name : sortedNames) {
        cout << name << endl;
    }
}

int main() {
    map<string, int> people;
    vector<string> names;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add person\n";
        cout << "2. Show people above a certain age\n";
        cout << "3. Show sorted names\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addPerson(people, names);
                break;
            case 2: {
                int age;
                cout << "Enter age limit: ";
                cin >> age;
                showPeopleAboveAge(people, age);
                break;
            }
            case 3:
                showSortedNames(names);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
