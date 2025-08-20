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
Node* deletetail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;   // free memory if single node
        return nullptr;
    }

    Node* temp = head;
    // Traverse until second last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;     // delete last node
    temp->next = nullptr;  // now last node points to NULL
    return head;
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
    head = deletetail(head);

    cout << "After deleting tail: ";
    printList(head);

    return 0;
}
