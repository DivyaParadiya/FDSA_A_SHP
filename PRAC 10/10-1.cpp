
#include <iostream>
using namespace std;

int main() {
    int table[10];
    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n, id;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> id;

        int pos = id % 10;
        int count = 0;

        while (table[pos] != -1 && count < 10) {
            pos = (pos + 1) % 10;
            count++;
        }

        if (count == 10)
            cout << "Parking Full\n";
        else
            table[pos] = id;
    }

    cout << "Parking slots:\n";
    for (int i = 0; i < 10; i++)
        cout << i << ": " << table[i] << endl;

    return 0;
}
