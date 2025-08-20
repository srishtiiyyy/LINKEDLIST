#include <bits/stdc++.h>
using namespace std;

// -------------------- Definition of Node --------------------
// Each node of the Linked List
struct Node {
    int val;       // data value
    Node* next;    // pointer to next node

    // Constructor for creating a new node
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

// -------------------- Delete Head Node --------------------
// Function to delete the first node (head) of the linked list
Node* deleteHead(Node* head) {
    if (head == nullptr) return head; // if list is empty, nothing to delete

    Node* temp = head;   // store current head
    head = head->next;   // move head to next node
    delete temp;         // free memory of old head
    return head;         // return new head
}

// -------------------- Traversal Function --------------------
// Utility function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// -------------------- Main Function --------------------
int main() {
    // Step 1: Create a simple linked list manually
    Node* head = new Node(10);       // head -> 10
    head->next = new Node(20);       // 10 -> 20
    head->next->next = new Node(30); // 10 -> 20 -> 30
    head->next->next->next = new Node(40); // 10 -> 20 -> 30 -> 40

    cout << "Original Linked List: ";
    printList(head);

    // Step 2: Delete head node
    head = deleteHead(head);

    cout << "After deleting head: ";
    printList(head);

    return 0;
}
