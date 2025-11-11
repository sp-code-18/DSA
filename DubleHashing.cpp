#include <iostream>
using namespace std;
#define SIZE 10  
 
int hashFunction(int key) {
    return key % SIZE;
}

int hashFunction2(int key) {
    return 7 - (key % 7);  
}

void insertDoubleHash(int table[], int key) {
    int index1 = hashFunction(key);    
    int index2 = hashFunction2(key);    
    int i = 0;                        

    
    while (i < SIZE) {
        int newIndex = (index1 + i * index2) % SIZE;  

        if (table[newIndex] == -1) {               
            table[newIndex] = key;
            cout << key << " inserted at index " << newIndex << " (Double Hashing)\n";
            return;
        }

        i++;  
    }

    cout << "Table Full! Cannot insert " << key << endl;
}


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
        insertDoubleHash(table, key);
    }

    display(table);
    return 0;
}
