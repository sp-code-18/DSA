#include <iostream>
using namespace std;
#define SIZE 10   // size of hash table

int hashFunction(int key) {
    return key % SIZE;
}

// Quadratic Probing
void insertQuadratic(int table[], int key) {
    int index = hashFunction(key);
    int i = 0;

    while (table[(index + i * i) % SIZE] != -1 && i < SIZE) {
        i++;
    }

    if (i == SIZE) {
        cout << "Table Full!\n";
        return;
    }

    int pos = (index + i * i) % SIZE;
    table[pos] = key;
    cout << key << " inserted at index " << pos << " (Quadratic Probing)\n";
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
        insertQuadratic(table, key);
    }

    display(table);
    return 0;
}

