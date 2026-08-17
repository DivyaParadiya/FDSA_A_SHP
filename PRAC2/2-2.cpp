#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == target)
            return mid;
        else if (target < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int binarySearchRecursive(int a[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == target)
        return mid;
    else if (target < a[mid])
        return binarySearchRecursive(a, low, mid - 1, target);
    else
        return binarySearchRecursive(a, mid + 1, high, target);
}

int main() {
    int n, target;

    cout << "Enter number of books: ";
    cin >> n;

    int a[n];

    cout << "Enter book codes in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target code: ";
    cin >> target;

    cout << "Loop search position: "
         << binarySearch(a, n, target) << endl;

    cout << "Recursive search position: "
         << binarySearchRecursive(a, 0, n - 1, target);

    return 0;
}