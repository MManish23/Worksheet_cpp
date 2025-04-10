#include <iostream>
#include <limits>
using namespace std;


class Cinema
{
private:
    char seats[5][5];

public:

    Cinema()
    {
        for (int i = 0; i < 5; ++i)
            {
            for (int j = 0; j < 5; ++j)
            {
                seats[i][j] = 'O';
            }
        }
    }

    void displaySeating()
    {
        cout << "\nCurrent Seating Arrangement:\n";
        for (int i = 0; i < 5; ++i)
            {
            for (int j = 0; j < 5; ++j)
            {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool bookSeat(int row, int col)
    {
        row -= 1;
        col -= 1;

        if (row < 0 || row >= 5 || col < 0 || col >= 5)
            {
            cout << "Error: Invalid seat number. Please enter row and column between 1 and 5.\n";
            return false;
        }

        if (seats[row][col] == 'X')
            {
            cout << "Error: This seat is already booked. Please choose a different seat.\n";
            return false;
        }

        seats[row][col] = 'X';
        return true;
    }
};


void Bookingsystem(Cinema &cinema)
{
    int row, col;
    bool bookingSuccessful;
    char exitOption;


    while (true)
        {
        cinema.displaySeating();

        cout << "Enter row (1-5) and column (1-5) to book a seat or enter 'e' to exit: ";


        if (!(cin >> row))
            {

            cin.clear();
            cin >> exitOption;
            if (exitOption == 'e')
            {
                cout << "Exiting the system.\n";
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }


        if (!(cin >> col))
            {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid input for column. Please enter valid numbers.\n";
            continue;
        }


        bookingSuccessful = cinema.bookSeat(row, col);


        if (bookingSuccessful)
            {
            cinema.displaySeating();
        }
    }
}

int main()
{

    Cinema cinema;


    Bookingsystem(cinema);

    return 0;
}

