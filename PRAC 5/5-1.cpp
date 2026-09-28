#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void addBeginning(string song) {
    Node* n = new Node{song, NULL, head};

    if (head == NULL)
        head = tail = n;
    else {
        head->prev = n;
        head = n;
    }
}

void addEnd(string song) {
    Node* n = new Node{song, tail, NULL};

    if (tail == NULL)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }
}

void insertAfter(string oldSong, string newSong) {
    Node* temp = head;

    while (temp != NULL && temp->song != oldSong)
        temp = temp->next;

    if (temp == NULL)
        return;

    Node* n = new Node{newSong, temp, temp->next};

    if (temp->next != NULL)
        temp->next->prev = n;
    else
        tail = n;

    temp->next = n;
}

void removeFirst() {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

int countSongs() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\n1. Add Beginning\n";
        cout << "2. Add End\n";
        cout << "3. Insert After\n";
        cout << "4. Remove First\n";
        cout << "5. Count\n";
        cout << "6. Display\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string song;
            cout << "Enter song: ";
            cin >> song;
            addBeginning(song);
        }
        else if (choice == 2) {
            string song;
            cout << "Enter song: ";
            cin >> song;
            addEnd(song);
        }
        else if (choice == 3) {
            string oldSong, newSong;
            cout << "Enter existing song: ";
            cin >> oldSong;
            cout << "Enter new song: ";
            cin >> newSong;
            insertAfter(oldSong, newSong);
        }
        else if (choice == 4) {
            removeFirst();
        }
        else if (choice == 5) {
            cout << "Number of songs: " << countSongs() << endl;
        }
        else if (choice == 6) {
            display();
        }

        cout << "Playlist: ";
        display();
    }

    return 0;
}