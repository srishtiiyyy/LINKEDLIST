#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert at head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to insert at tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert at kth position (1-indexed)
// Example: k = 3 means insert at position 3
void insertAtK(Node*& head, int val, int k) {
    if (k <= 1 || head == nullptr) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        cout << "Position greater than length, inserting at tail" << endl;
        insertAtTail(head, val);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert before kth position (1-indexed)
// Example: k = 3 means insert before node at position 3
void insertBeforeK(Node*& head, int val, int k) {
    if (k <= 1 || head == nullptr) {
        insertAtHead(head, val);
        return;
    }
    insertAtK(head, val, k); // just call insertAtK with same k
}

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 10);
    insertAtHead(head, 5);
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    cout << "After insertions at head and tail:" << endl;
    printList(head);

    insertAtK(head, 15, 3);
    cout << "After insertion at 3rd position:" << endl;
    printList(head);

    insertBeforeK(head, 25, 5);
    cout << "After insertion before 5th position:" << endl;
    printList(head);

    return 0;
}
