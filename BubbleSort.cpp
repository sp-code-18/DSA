#include <iostream>
using namespace std;

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(percentage, n);

    cout << "\nSorted Percentages (Bubble Sort): ";
    for (int i = 0; i < n; i++)
        cout << percentage[i] << " ";

    displayTopFive(percentage, n);

    return 0;
}

