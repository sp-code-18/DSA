#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

// Function to add a member
Node* addMember(Node* head) {
    Node* newNode = new Node;
    cout << "Enter PRN: ";
    cin >> newNode->prn;
    cout << "Enter Name: ";
    cin >> newNode->name;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to count members
void countMembers(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "Total Members: " << count << endl;
}

// Function to display members
void display(Node* head) {
    if (head == NULL) {
        cout << "No members in this division!\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << "PRN: " << temp->prn << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}

// Function to concatenate two club lists
Node* concatenate(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    cout << "\nTwo divisions merged successfully!\n";
    return head1;
}

int main() {
    Node* divA = NULL;
    Node* divB = NULL;
    Node* merged = NULL;
    int choice;

    do {
        cout << "\n===== Pinnacle Club Menu (Concatenate) =====\n";
        cout << "1. Add Members in Division A\n";
        cout << "2. Add Members in Division B\n";
        cout << "3. Display Division A\n";
        cout << "4. Display Division B\n";
        cout << "5. Concatenate A + B\n";
        cout << "6. Count Members (Merged)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: divA = addMember(divA); break;
            case 2: divB = addMember(divB); break;
            case 3: display(divA); break;
            case 4: display(divB); break;
            case 5:
                merged = concatenate(divA, divB);
                cout << "\n--- Combined Club Members ---\n";
                display(merged);
                break;
            case 6: countMembers(merged); break;
            case 7: cout << "Exiting..."; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

