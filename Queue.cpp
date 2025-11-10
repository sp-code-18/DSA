#include <iostream>
#define SIZE 10   // Maximum number of jobs in queue
using namespace std;

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is full
bool isFull() {
    return (rear == SIZE - 1);
}

// Function to check if queue is empty
bool isEmpty() {
    return (front == -1 || front > rear);
}

// Function to add a job to the queue (Enqueue)
void addJob() {
    int jobID;
    cout << "Enter Job ID to add: ";
    cin >> jobID;

    if (isFull()) {
        cout << "Queue is FULL! Cannot add new job.\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = jobID;
    cout << "Job " << jobID << " added successfully!\n";
}

// Function to delete a job from the queue (Dequeue)
void deleteJob() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! No job to delete.\n";
        return;
    }

    cout << "Job " << queue[front] << " deleted successfully!\n";
    front++;

    if (front > rear)
        front = rear = -1;  // Reset queue
}

// Function to display current jobs in queue
void displayJobs() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! No jobs to display.\n";
        return;
    }

    cout << "\nCurrent Jobs in Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << "\n";
}

// Main function
int main() {
    int choice;

    cout << "         JOB QUEUE SIMULATION        \n";
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addJob();
                break;
            case 2:
                deleteJob();
                break;
            case 3:
                displayJobs();
                break;
            case 4:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

