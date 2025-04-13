#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 1) {
            insertAtStart(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; ++i) temp = temp->next;

        if (!temp) {
            cout << "Position out of range.\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void findNthFromEnd(int n) {
        Node *main = head, *ref = head;
        for (int i = 0; i < n; ++i) {
            if (!ref) {
                cout << "Position too big.\n";
                return;
            }
            ref = ref->next;
        }
        while (ref) {
            main = main->next;
            ref = ref->next;
        }
        cout << n << "th node from end: " << main->data << endl;
    }

    void reverseInGroups(int k) {
        head = reverseK(head, k);
    }

    Node* reverseK(Node* node, int k) {
        Node *prev = nullptr, *curr = node, *next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) node->next = reverseK(next, k);
        return prev;
    }

    void detectAndRemoveLoop() {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                removeLoop(slow);
                cout << "Loop removed.\n";
                return;
            }
        }
        cout << "No loop detected.\n";
    }

    void removeLoop(Node* loopNode) {
        Node* ptr1 = head;
        while (ptr1->next != loopNode->next) {
            ptr1 = ptr1->next;
            loopNode = loopNode->next;
        }
        loopNode->next = nullptr;
    }

    void createLoop(int pos) {
        if (pos <= 0) return;
        Node *loopNode = nullptr, *temp = head;
        int count = 1;
        while (temp->next) {
            if (count == pos) loopNode = temp;
            temp = temp->next;
            count++;
        }
        if (loopNode) temp->next = loopNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList ll;

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.display();

    ll.insertAtStart(5);
    ll.insertAtPosition(15, 3);
    ll.display();

    ll.findNthFromEnd(3);

    ll.reverseInGroups(2);
    cout << "After reversing in groups of 2:\n";
    ll.display();

    ll.createLoop(3);
    ll.detectAndRemoveLoop();
    ll.display();

    return 0;
}

