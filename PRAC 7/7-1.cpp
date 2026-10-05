#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;

    int q[n];
    int front = 0, rear = 0, count = 0;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice, token;

        cout << "Enter 1 for Join, 2 for Serve: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter token: ";
            cin >> token;

            if (count == n) {
                cout << "Error: Queue is full\n";
            } else {
                q[rear] = token;
                rear = (rear + 1) % n;
                count++;

                if (count > 0)
                    cout << "Front token: " << q[front] << endl;
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "Error: Queue is empty\n";
            } else {
                front = (front + 1) % n;
                count--;

                if (count > 0)
                    cout << "Front token: " << q[front] << endl;
                else
                    cout << "Queue is empty\n";
            }
        }
    }

    return 0;
}