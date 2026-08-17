#include <iostream>
using namespace std;

int main() {
    int n, h;

    cout << "Enter the number of items: ";
    cin >> n;

    int a[n];

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the number of hours: ";
    cin >> h;

    h = h % n;

    for (int i = h; i < n; i++) {
        cout << a[i] << " ";
    }

    for (int i = 0; i < h; i++) {
        cout << a[i] << " ";
    }

    return 0;
}