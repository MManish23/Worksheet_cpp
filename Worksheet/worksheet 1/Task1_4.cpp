#include <iostream>
using namespace std;

class DayOfWeek
{
public:
    void getWeekDay(int day)
    {
        switch (day)
        {
            case 1:
                cout << "Its Sunday" << endl;
            break;
            case 2:
                cout << "Its Monday" << endl;
            break;
            case 3:
                cout << "Its Tuesday" << endl;
            break;
            case 4:
                cout << "Its Wednesday" << endl;
            break;
            case 5:
                cout << "Its Thursday" << endl;
            break;
            case 6:
                cout << "Its Friday" << endl;
            break;
            case 7:
                cout << "Its Saturday" << endl;
            break;
            default:
                cout << "Invalid input. Please select between 1 and 7." << endl;
            break;
        }
    }
};

void getInput() {
    int day;
    cout << "Enter a number between 1 and 7 to know the corresponding day of the week: ";
    cin >> day;

    DayOfWeek d;
    d.getWeekDay(day);
}

int main() {
    getInput();
    return 0;
}
