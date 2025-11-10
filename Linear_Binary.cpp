#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}

int main() {
    int choice;
    int n, key;

    cout << "Enter number of students who attended the training: ";
    cin >> n;

    int roll[n];
    cout << "Enter roll numbers of students:\n";
    for (int i = 0; i < n; i++) {
        cin >> roll[i];
    }

    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Linear Search (Random Order)";
        cout << "\n2. Binary Search (Sorted Order)";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nEnter roll number to search: ";
            cin >> key;
            int pos = linearSearch(roll, n, key);
            if (pos != -1)
                cout << "Student with roll number " << key << " attended the training program.\n";
            else
                cout << "Student with roll number " << key << " did NOT attend the training program.\n";
            break;
        }

        case 2: {
            
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (roll[j] > roll[j + 1]) {
                        int temp = roll[j];
                        roll[j] = roll[j + 1];
                        roll[j + 1] = temp;
                    }
                }
            }

            cout << "\nSorted Roll Numbers: ";
            for (int i = 0; i < n; i++)
                cout << roll[i] << " ";

            cout << "\n\nEnter roll number to search: ";
            cin >> key;
            int pos = binarySearch(roll, n, key);
            if (pos != -1)
                cout << "Student with roll number " << key << " attended the training program.\n";
            else
                cout << "Student with roll number " << key << " did NOT attend the training program.\n";
            break;
        }

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

