#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;
};

Node* shead = NULL;
Node* dhead = NULL;

void singlyAdd(string name) {
    Node* n = new Node{name, NULL, NULL};

    if (shead == NULL) {
        shead = n;
        n->next = shead;
        return;
    }

    Node* temp = shead;

    while (temp->next != shead)
        temp = temp->next;

    temp->next = n;
    n->next = shead;
}

void singlyRemove(string name) {
    if (shead == NULL)
        return;

    Node* temp = shead;
    Node* prev = NULL;

    do {
        if (temp->name == name)
            break;

        prev = temp;
        temp = temp->next;
    } while (temp != shead);

    if (temp->name != name)
        return;

    if (temp == shead) {
        if (shead->next == shead) {
            delete shead;
            shead = NULL;
        } else {
            Node* last = shead;

            while (last->next != shead)
                last = last->next;

            shead = shead->next;
            last->next = shead;
            delete temp;
        }
    } else {
        prev->next = temp->next;
        delete temp;
    }
}

void singlyDisplay() {
    if (shead == NULL) {
        cout << "Empty";
        return;
    }

    Node* temp = shead;

    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != shead);
}

void doublyAdd(string name) {
    Node* n = new Node{name, NULL, NULL};

    if (dhead == NULL) {
        dhead = n;
        n->next = n;
        n->prev = n;
        return;
    }

    Node* last = dhead->prev;

    n->next = dhead;
    n->prev = last;
    last->next = n;
    dhead->prev = n;
}

void doublyRemove(string name) {
    if (dhead == NULL)
        return;

    Node* temp = dhead;

    do {
        if (temp->name == name)
            break;

        temp = temp->next;
    } while (temp != dhead);

    if (temp->name != name)
        return;

    if (temp->next == temp) {
        delete temp;
        dhead = NULL;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == dhead)
        dhead = temp->next;

    delete temp;
}

void doublyDisplay() {
    if (dhead == NULL) {
        cout << "Empty";
        return;
    }

    Node* temp = dhead;

    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != dhead);
}

int main() {
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\n1. Join\n";
        cout << "2. Leave\n";
        cout << "3. Display\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter student name: ";
            cin >> name;

            singlyAdd(name);
            doublyAdd(name);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter student name: ";
            cin >> name;

            singlyRemove(name);
            doublyRemove(name);
        }

        cout << "Singly Circular: ";
        singlyDisplay();

        cout << "\nDoubly Circular: ";
        doublyDisplay();

        cout << endl;
    }

    return 0;
}