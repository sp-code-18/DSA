#include <iostream>
using namespace std;

void selectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        float temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void displayTopFive(float arr[], int n) {
    cout << "\nTop Five Scores:\n";
    int count = (n < 5) ? n : 5;
    for (int i = n - 1; i >= n - count; i--) {
        cout << arr[i] << "%  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    float percentage[n];
    cout << "Enter percentage of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cin >> percentage[i];
    }

    selectionSort(percentage, n);

    cout << "\nSorted Percentages (Selection Sort): ";
    for (int i = 0; i < n; i++)
        cout << percentage[i] << " ";

    displayTopFive(percentage, n);

    return 0;
}

