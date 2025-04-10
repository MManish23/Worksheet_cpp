#include <iostream>
#include <vector>
using namespace std;

class BouncyNumber
{
public:
    bool isBouncy(int number)

    {
        vector<int> digits = getDigits(number);

        if (digits.size() < 3)
        {
            return false;
        }

        bool increasing = false;
        bool decreasing = false;

        for (size_t i = 1; i < digits.size(); ++i)
        {
            if (digits[i] > digits[i - 1])
            {
                increasing = true;
            } else if (digits[i] < digits[i - 1])
            {
                decreasing = true;
            }

            if (increasing && decreasing)
            {
                return true;
            }
        }


        return false;
    }

private:

    vector<int> getDigits(int number)
    {
        vector<int> digits;
        while (number > 0)
        {
            digits.insert(digits.begin(), number % 10);
            number /= 10;
        }
        return digits;
    }
};

int main()
{
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    BouncyNumber bouncyChecker;

    if (bouncyChecker.isBouncy(number))
    {
        cout << number << " is a bouncy number." << endl;
    }
    else
    {
        cout << number << " is not a bouncy number." << endl;
    }

    return 0;
}


