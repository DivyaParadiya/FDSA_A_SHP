#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;
};

Node* head = NULL;

void insertFront(int token) {
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int token) {
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(int token, int position) {
    if (position <= 1) {
        insertFront(token);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    Node* temp = head;

    cout << "Current Queue: ";

    while (temp != NULL) {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int choice, token, position;

        cout << "\nOperation " << i + 1 << endl;
        cout << "1. Insert patient at front" << endl;
        cout << "2. Insert patient at end" << endl;
        cout << "3. Insert patient at specific position" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient token: ";
            cin >> token;

            insertFront(token);
        }
        else if (choice == 2) {
            cout << "Enter patient token: ";
            cin >> token;

            insertEnd(token);
        }
        else if (choice == 3) {
            cout << "Enter patient token: ";
            cin >> token;

            cout << "Enter position: ";
            cin >> position;

            insertAtPosition(token, position);
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        display();
    }

    return 0;
}