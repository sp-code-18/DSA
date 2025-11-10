#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Structure for each seat (node)
struct Seat {
    int seatNo;         // Seat number (1–7)
    bool booked;        // false = free, true = booked
    Seat* next;
    Seat* prev;
};

// Function to create one row (with random bookings)
Seat* createRow() {
    Seat* head = NULL;
    Seat* tail = NULL;

    for (int i = 1; i <= 7; i++) {
        Seat* newSeat = new Seat;
        newSeat->seatNo = i;
        newSeat->booked = rand() % 2;   // random booking
        newSeat->next = NULL;
        newSeat->prev = tail;

        if (head == NULL)
            head = newSeat;
        else
            tail->next = newSeat;

        tail = newSeat;
    }
    return head;
}

// Function to display only available seats
void displayAvailable(Seat* theater[], int rows) {
    cout << "\n--- Available Seats (O = Free) ---\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << (i + 1) << ": ";
        Seat* temp = theater[i];
        bool freeFound = false;
        while (temp != NULL) {
            if (!temp->booked) {
                cout << temp->seatNo << " ";
                freeFound = true;
            }
            temp = temp->next;
        }
        if (!freeFound)
            cout << "No free seats";
        cout << endl;
    }
}

// Function to book a seat
void bookSeat(Seat* theater[]) {
    int row, seat;
    cout << "Enter Row (1–10): ";
    cin >> row;
    cout << "Enter Seat (1–7): ";
    cin >> seat;

    if (row < 1 || row > 10 || seat < 1 || seat > 7) {
        cout << "Invalid input!\n";
        return;
    }

    Seat* temp = theater[row - 1];
    for (int i = 1; i < seat; i++)
        temp = temp->next;

    if (temp->booked)
        cout << "Seat already booked!\n";
    else {
        temp->booked = true;
        cout << "Seat " << seat << " in Row " << row << " booked successfully!\n";
    }
}

int main() {
    srand(time(0));
    const int ROWS = 10;
    Seat* theater[ROWS];

    // Create 10 rows (each with random booking)
    for (int i = 0; i < ROWS; i++)
        theater[i] = createRow();

    int choice;
    do {
        cout << "\n===== CINEMAX BOOKING SYSTEM (B-5a) =====";
        cout << "\n1. Display Available Seats";
        cout << "\n2. Book a Seat";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailable(theater, ROWS);
                break;
            case 2:
                bookSeat(theater);
                break;
            case 3:
                cout << "Thank you!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

