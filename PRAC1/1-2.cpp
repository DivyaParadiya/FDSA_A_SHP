#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of records: ";
    cin >> n;

    int a[n];

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Books borrowed more than once: ";

    bool found = false;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (a[i] == a[j])
                count++;
        }

        if (count > 1) {
            bool printed = false;

            for (int j = 0; j < i; j++) {
                if (a[i] == a[j])
                    printed = true;
            }

            if (!printed) {
                cout << a[i] << " ";
                found = true;
            }
        }
    }

    if (!found)
        cout << "None";

    return 0;
}