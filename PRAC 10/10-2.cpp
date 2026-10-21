
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> table[10];
    int n, id;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> id;
        table[id % 10].push_back(id);
    }

    cout << "Shelf contents:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        for (int x : table[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
