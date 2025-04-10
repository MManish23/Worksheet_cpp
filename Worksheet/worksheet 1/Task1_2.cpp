#include <iostream>

using namespace std;

class guessgame {
private:
    int randomnumber;
    int maximumnumber;
public:

    void numberGuessingGame (){
        int difficulty, range, number, guess;

        cout << "Select difficulty level:\n";
        cout << "1. Beginner (1-8)\n";
        cout << "2. Moderate (1-30)\n";
        cout << "3. Standard (1-50)\n";
        cout << "Enter your choice (1-3): ";
        cin >> difficulty;

        if (difficulty == 1) {
            range = 8;
        } else if (difficulty == 2) {
            range = 30;
        } else if (difficulty == 3) {
            range = 50;
        } else {
            cout << "Invalid selection. Please choose between the range." << endl;
            return;
        }

        srand(time(0));
        number = rand() % range + 1;

        cout << "Guess the number between 1 and " << range << ": ";
        while (true) {
            cin >> guess;
            if (guess < 1 || guess > range) {
                cout << "Out of range! Please guess between 1 and " << range << "." << endl;
                continue;
            }
            if (guess == number) {
                cout << "Congratulations! You guessed the correct number." << endl;
                break;
            } else if (guess < number) {
                cout << "Your guess is too low! Try again: ";
            } else {
                cout << "Your guess if too high! Try again: ";
            }
        }
    }
};
int main() {
    guessgame Game;
    Game.numberGuessingGame();
    return 0;
}

