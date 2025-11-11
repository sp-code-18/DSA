#include <iostream>
using namespace std;
#define SIZE 10   // size of hash table

int hashFunction(int key) {
    return key % SIZE;
}

// ✅ Quadratic Probing (Simplified and Correct)
void insertQuadratic(int table[], int key) {
    int index = hashFunction(key);   // Initial index
    int i = 0;                       // Collision counter

    // Try up to SIZE times (to avoid infinite loop)
    while (i < SIZE) {
        int newIndex = (index + i * i) % SIZE;  // Quadratic probing formula

        if (table[newIndex] == -1) {            // Empty slot found
            table[newIndex] = key;
            cout << key << " inserted at index " << newIndex << " (Quadratic Probing)\n";
            return;
        }

        i++;   // Increase the probe count
    }

    cout << "Table Full! Cannot insert " << key << endl;
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
        table[i] = -1;   // Initialize table with -1 (empty)

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
