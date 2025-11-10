#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

// Function to add President
Node* addPresident(Node* head) {
    Node* newNode = new Node;
    cout << "Enter PRN of President: ";
    cin >> newNode->prn;
    cout << "Enter Name of President: ";
    cin >> newNode->name;
    newNode->next = head;
    head = newNode;
    cout << "President added!\n";
    return head;
}

// Function to add Member
Node* addMember(Node* head) {
    if (head == NULL) {
        cout << "Add President first!\n";
        return head;
    }

    Node* newNode = new Node;
    cout << "Enter PRN of Member: ";
    cin >> newNode->prn;
    cout << "Enter Name of Member: ";
    cin >> newNode->name;

    newNode->next = head->next;
    head->next = newNode;
    cout << "Member added!\n";
    return head;
}

// Function to add Secretary
Node* addSecretary(Node* head) {
    Node* newNode = new Node;
    cout << "Enter PRN of Secretary: ";
    cin >> newNode->prn;
    cout << "Enter Name of Secretary: ";
    cin >> newNode->name;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        cout << "Secretary added!\n";
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    cout << "Secretary added!\n";
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
        cout << "\n===== Pinnacle Club Menu (Add) =====\n";
        cout << "1. Add President\n2. Add Member\n3. Add Secretary\n4. Display Members\n5. Count Members\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
				club = addPresident(club); 
				break;
            case 2: 
				club = addMember(club); 
				break;
            case 3: 
				club = addSecretary(club); 
				break;
            case 4: 
				display(club); 
				break;
            case 5: 
				countMembers(club); 
				break;
            case 6: 
				cout << "Exiting..."; 
				break;
            default: 
				cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

