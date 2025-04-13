#include <iostream>
using namespace std;

class Queue {
private:
    int queue[10];
    int front, rear, size;

public:
    Queue() {
        front = rear = size = 0;
    }

    void enqueue(int value) {
        if (size == 10) {
            cout << "Queue is full!\n";
            return;
        }
        queue[rear] = value;
        rear = (rear + 1) % 10;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int val = queue[front];
        front = (front + 1) % 10;
        size--;
        return val;
    }

    void reverseFirstK(int k) {
        if (k > size || k < 1) {
            cout << "Invalid value of K.\n";
            return;
        }

        int temp[10];
        for (int i = 0; i < k; i++) temp[i] = dequeue();
        for (int i = k - 1; i >= 0; i--) enqueue(temp[i]);
    }

    void interleave() {
        if (size % 2 != 0) {
            cout << "Queue size must be even to interleave.\n";
            return;
        }

        int half = size / 2;
        int first[5], second[5];

        for (int i = 0; i < half; i++) first[i] = dequeue();
        for (int i = 0; i < half; i++) second[i] = dequeue();

        for (int i = 0; i < half; i++) {
            enqueue(first[i]);
            enqueue(second[i]);
        }
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        int index = front;
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << queue[index] << " ";
            index = (index + 1) % 10;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value, k;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Reverse First K Elements\n";
        cout << "4. Interleave Halves\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1) cout << "Dequeued: " << value << endl;
                break;
            case 3:
                cout << "Enter K: ";
                cin >> k;
                q.reverseFirstK(k);
                break;
            case 4:
                q.interleave();
                break;
            case 5:
                q.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}

