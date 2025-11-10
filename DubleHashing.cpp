#include <iostream>
using namespace std;
#define SIZE 10   // size of hash table

int hashFunction(int key) {
    return key % SIZE;
}

int hash2(int key) {   // secondary hash function
    return 7 - (key % 7);
}

// Double Hashing
void insertDouble(int table[], int key) {
    int index1 = hashFunction(key);
    int index2 = hash2(key);
    int i = 0;

    while (table[(index1 + i * index2) % SIZE] != -1 && i < SIZE) {
        i++;
    }

    if (i == SIZE) {
        cout << "Table Full!\n";
        return;
    }

    int pos = (index1 + i * index2) % SIZE;
    table[pos] = key;
    cout << key << " inserted at index " << pos << " (Double Hashing)\n";
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
        insertDouble(table, key);
    }

    display(table);
    return 0;
}

