
#include <iostream>
using namespace std;

int main() {
    int table[10];
    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n, id;
    cout << "Enter number of student IDs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int count = 0;
        int pos = h1;

        while (table[pos] != -1 && count < 10) {
            count++;
            pos = (h1 + count * h2) % 10;
        }

        if (count == 10)
            cout << "Hash table Full\n";
        else
            table[pos] = id;
    }

    cout << "Hash table:\n";
    for (int i = 0; i < 10; i++)
        cout << i << ": " << table[i] << endl;

    return 0;
}
