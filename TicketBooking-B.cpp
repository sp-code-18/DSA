#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Structure for each seat (node)
struct Seat {
    int seatNo;         // Seat number (1–7)
    bool booked;        // true = booked, false = free
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
        newSeat->booked = rand() % 2;   // random booking at start
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

// Function to display only booked seats
void displayBooked(Seat* theater[], int rows) {
    cout << "\n--- Booked Seats (X = Booked) ---\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << (i + 1) << ": ";
        Seat* temp = theater[i];
        bool bookedFound = false;
        while (temp != NULL) {
            if (temp->booked) {
                cout << temp->seatNo << " ";
                bookedFound = true;
            }
            temp = temp->next;
        }
        if (!bookedFound)
            cout << "No booked seats";
        cout << endl;
    }
}

// Function to cancel booking
void cancelSeat(Seat* theater[]) {
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

    if (!temp->booked)
        cout << "Seat is not booked yet!\n";
    else {
        temp->booked = false;
        cout << "Booking cancelled for Seat " << seat << " in Row " << row << ".\n";
    }
}

int main() {
    srand(time(0));
    const int ROWS = 10;
    Seat* theater[ROWS];

    // Create 10 rows with random bookings
    for (int i = 0; i < ROWS; i++)
        theater[i] = createRow();

    int choice;
    do {
        cout << "\n===== CINEMAX BOOKING SYSTEM (B-5b) =====";
        cout << "\n1. Display Booked Seats";
        cout << "\n2. Cancel a Booking";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayBooked(theater, ROWS);
                break;
            case 2:
                cancelSeat(theater);
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

