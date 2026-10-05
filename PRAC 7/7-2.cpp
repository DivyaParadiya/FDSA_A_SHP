#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int q[n];
    int front = 0, rear = 0, count = 0;

    int op;
    cout << "Enter number of operations: ";
    cin >> op;

    while (op--) {
        int choice;
        cout << "1. Join  2. Serve: ";
        cin >> choice;

        if (choice == 1) {
            int token;
            cout << "Enter token: ";
            cin >> token;

            if (count == n)
                cout << "Error: Queue Full\n";
            else {
                q[rear] = token;
                rear = (rear + 1) % n;
                count++;
                cout << "Front: " << q[front] << endl;
            }
        }
        else if (choice == 2) {
            if (count == 0)
                cout << "Error: Queue Empty\n";
            else {
                front = (front + 1) % n;
                count--;

                if (count > 0)
                    cout << "Front: " << q[front] << endl;
                else
                    cout << "Queue Empty\n";
            }
        }
    }

    return 0;
}