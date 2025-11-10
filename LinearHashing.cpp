#include <iostream>
using namespace std;
#define SIZE 10   // size of hash table

int hashFunction(int key) {
    return key % SIZE;
}

// Linear Probing
void insertLinear(int table[], int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index] != -1) {     // if slot already filled
        index = (index + 1) % SIZE;  // move to next slot
        if (index == start) {
            cout << "Table Full!\n";
            return;
        }
    }
    table[index] = key;
    cout << key << " inserted at index " << index << " (Linear Probing)\n";
}

// Display table
void display(int table[]) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            cout << i << " : Empty\n";
        else
            cout << i << " : " << table[i] << endl;
    }
}

int main() {
    int table[SIZE];
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n, key;
    cout << "Enter number of clients: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter telephone number (as key): ";
        cin >> key;
        insertLinear(table, key);
    }

    display(table);
    return 0;
}

