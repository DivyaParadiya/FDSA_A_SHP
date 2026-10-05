#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter stack capacity: ";
    cin >> n;

    string stack[n];
    int top = -1;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice;

        cout << "\n1. Place tray\n";
        cout << "2. Take tray\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string tray;
            cout << "Enter tray: ";
            cin >> tray;

            if (top == n - 1) {
                cout << "Error: Stack is full" << endl;
            } else {
                top++;
                stack[top] = tray;
            }
        }
        else if (choice == 2) {
            if (top == -1) {
                cout << "Error: Stack is empty" << endl;
            } else {
                cout << "Taken tray: " << stack[top] << endl;
                top--;
            }
        }

        if (top == -1)
            cout << "Top tray: None" << endl;
        else
            cout << "Top tray: " << stack[top] << endl;
    }

    return 0;
}