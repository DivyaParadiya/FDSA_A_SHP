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

void deleteByValue(int token) {
    if (head == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }

    if (head->token == token) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient deleted successfully." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->token != token) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Patient token not found!" << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;

    cout << "Patient deleted successfully." << endl;
}

void forwardPrint() {
    Node* temp = head;

    cout << "Queue from front to back: ";

    while (temp != NULL) {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reversePrint(Node* temp) {
    if (temp == NULL)
        return;

    reversePrint(temp->next);
    cout << temp->token << " ";
}

int main() {
    int n;

    cout << "Enter number of insertion operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice, token, position;

        cout << "\nInsertion Operation " << i + 1 << endl;
        cout << "1. Insert at front" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cout << "Enter patient token: ";
        cin >> token;

        if (choice == 1) {
            insertFront(token);
        }
        else if (choice == 2) {
            insertEnd(token);
        }
        else if (choice == 3) {
            cout << "Enter position: ";
            cin >> position;
            insertAtPosition(token, position);
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        forwardPrint();
    }

    int choice;

    cout << "\nWhat operation do you want to perform?" << endl;
    cout << "1. Delete patient by token" << endl;
    cout << "2. Forward traversal" << endl;
    cout << "3. Reverse printing" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int token;

        cout << "Enter patient token to delete: ";
        cin >> token;

        deleteByValue(token);
        forwardPrint();
    }
    else if (choice == 2) {
        forwardPrint();
    }
    else if (choice == 3) {
        cout << "Queue from last to first: ";
        reversePrint(head);
        cout << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}