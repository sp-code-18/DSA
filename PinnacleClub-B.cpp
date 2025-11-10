#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

// Function to delete President
Node* deletePresident(Node* head) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "President deleted!\n";
    return head;
}

// Function to delete Secretary
Node* deleteSecretary(Node* head) {
    if (head == NULL || head->next == NULL) {
        cout << "Not enough members to delete secretary!\n";
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
    cout << "Secretary deleted!\n";
    return head;
}

// Function to delete a Member (by PRN)
Node* deleteMember(Node* head) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return NULL;
    }

    int prn;
    cout << "Enter PRN of member to delete: ";
    cin >> prn;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->prn != prn) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Member not found!\n";
        return head;
    }

    if (prev != NULL)
        prev->next = temp->next;
    else
        head = temp->next;

    delete temp;
    cout << "Member deleted!\n";
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
        cout << "No members in the club!\n";
        return;
    }

    cout << "\n--- Club Members ---\n";
    Node* temp = head;
    while (temp != NULL) {
        cout << "PRN: " << temp->prn << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    Node* club = NULL;
    int choice;

    do {
        cout << "\n===== Pinnacle Club Menu (Delete) =====\n";
        cout << "1. Delete President\n2. Delete Member\n3. Delete Secretary\n4. Display Members\n5. Count Members\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: club = deletePresident(club); break;
            case 2: club = deleteMember(club); break;
            case 3: club = deleteSecretary(club); break;
            case 4: display(club); break;
            case 5: countMembers(club); break;
            case 6: cout << "Exiting..."; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

