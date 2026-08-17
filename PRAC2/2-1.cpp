#include <iostream>
using namespace std;

int searchIterative(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target)
            return i;
    }
    return -1;
}

int searchRecursive(int a[], int n, int target, int i) {
    if (i == n)
        return -1;

    if (a[i] == target)
        return i;

    return searchRecursive(a, n, target, i + 1);
}

int main() {
    int n, target;

    cout << "Enter number of vehicles: ";
    cin >> n;

    int a[n];

    cout << "Enter license plates: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target plate: ";
    cin >> target;

    int x = searchIterative(a, n, target);
    int y = searchRecursive(a, n, target, 0);

    cout << "Iterative search position: " << x << endl;
    cout << "Recursive search position: " << y << endl;

    return 0;
}