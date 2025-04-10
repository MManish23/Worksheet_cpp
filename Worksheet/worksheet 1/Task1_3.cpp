#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ArraySorter {
private:
    vector<int> arr;

public:
    void getInput() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid input. The number of elements must be greater than 0." << endl;
            exit(0);
        }

        arr.resize(n);
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void sortArray() {
        sort(arr.begin(), arr.end());
    }

    void displayArray() {
        cout << "Sorted array in ascending order: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void process() {
        getInput();
        sortArray();
        displayArray();
    }
};

int main() {
    ArraySorter sorter;
    sorter.process();
    return 0;
}

