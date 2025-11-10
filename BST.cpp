#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to find the number of nodes in the longest path (height)
int height(Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum data value in the tree
int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Function to mirror the tree
void mirror(Node* root) {
    if (root == NULL)
        return;
    // Swap left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

// Function to search a value
bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder Traversal (to verify tree structure)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function
int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of elements to insert initially: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder traversal of BST: ";
    inorder(root);
    cout << endl;

    // i. Insert new node
    cout << "\nEnter value to insert: ";
    cin >> value;
    root = insert(root, value);

    cout << "Inorder after insertion: ";
    inorder(root);
    cout << endl;

    // ii. Longest path (height)
    cout << "\nNumber of nodes in longest path (Height): " << height(root) << endl;

    // iii. Minimum data value
    cout << "Minimum value in BST: " << findMin(root) << endl;


     // v. Search a value
    cout << "\nEnter value to search: ";
    cin >> value;
    if (search(root, value))
        cout << value << " found in BST!" << endl;
    else
        cout << value << " not found in BST!" << endl;
        
    // iv. Mirror the tree
    mirror(root);
    cout << "Inorder traversal after mirroring: ";
    inorder(root);
    cout << endl;

    return 0;
}

