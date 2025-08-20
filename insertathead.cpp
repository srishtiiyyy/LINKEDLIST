#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Insert new node at the head
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val); // create new node
    newNode->next = head;          // point newNode->next to current head
    head = newNode;                // move head to newNode
    return head;                   // return new head
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL; // initially empty list

    // Insertion at head
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);

    // Print the list
    printList(head); // Output: 30 -> 20 -> 10 -> NULL

    return 0;
}
