#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page) {
    Node* n = new Node;
    n->page = page;
    n->next = top;
    top = n;
}

void back() {
    if (top == NULL) {
        cout << "No history left" << endl;
    } else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void display() {
    if (top == NULL)
        cout << "Current page: None" << endl;
    else
        cout << "Current page: " << top->page << endl;
}

int main() {
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;

        cout << "\n1. Visit page\n";
        cout << "2. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string page;
            cout << "Enter page: ";
            cin >> page;

            visit(page);
        }
        else if (choice == 2) {
            back();
        }

        display();
    }

    return 0;
}