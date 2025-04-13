#include <iostream>
using namespace std;

class Stack {
private:
    int stack[10];
    int top;

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
            return;
        }
        stack[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Popped value: " << stack[top--] << endl;
    }

    void findMiddle() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Middle element: " << stack[top / 2] << endl;
    }

    void reverseBottomHalf() {
        if (top < 1) {
            cout << "Not enough elements to reverse bottom half!" << endl;
            return;
        }

        int mid = top / 2;
        for (int i = 0; i <= mid / 2; i++) {
            swap(stack[i], stack[mid - i]);
        }

        cout << "Bottom half reversed." << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    int spaceLeft() {
        return 9 - top;
    }
};

int main() {
    Stack s;
    int choice, value, count;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push up to 5 numbers\n";
        cout << "2. Pop\n";
        cout << "3. Find Middle\n";
        cout << "4. Reverse Bottom Half\n";
        cout << "5. Display Stack\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "How many numbers do you want to push (max 5)? ";
                cin >> count;

                if (count < 1 || count > 5) {
                    cout << "Please enter a number between 1 and 5." << endl;
                    break;
                }

                if (count > s.spaceLeft()) {
                    cout << "Not enough space in stack. You can push up to " << s.spaceLeft() << " more." << endl;
                    break;
                }

                cout << "Enter " << count << " number(s): ";
                for (int i = 0; i < count; ++i) {
                    cin >> value;
                    s.push(value);
                }
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.findMiddle();
                break;

            case 4:
                s.reverseBottomHalf();
                break;

            case 5:
                s.display();
                break;

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}
