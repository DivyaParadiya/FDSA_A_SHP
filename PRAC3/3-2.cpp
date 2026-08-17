#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of buckets: ";
    cin >> n;

    int a[n];

    cout << "Enter colour codes (0, 1, 2): ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Sorted colours: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}