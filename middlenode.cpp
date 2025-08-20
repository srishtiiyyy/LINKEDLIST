#include <bits/stdc++.h>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;           // value stored in the node
    ListNode* next;    // pointer to the next node
    ListNode(int x) {  // constructor to initialize a node
        val = x;
        next = nullptr;
    }
};

// Function to find the middle node of a linked list
// Approach: Slow and Fast Pointer
// - Slow pointer moves 1 step at a time
// - Fast pointer moves 2 steps at a time
// When fast reaches the end, slow will be at the middle
ListNode* middleNode(ListNode* head) {
    // Edge cases: empty list or single node
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast by 2 steps and slow by 1 step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow is now pointing to the middle node
    return slow;
}

// Utility function to insert a node at the end (tail insertion)
void insertAtTail(ListNode*& head, int data) {
    ListNode* newNode = new ListNode(data);
    if (head == nullptr) { // if list is empty
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code (main function) for testing
int main() {
    ListNode* head = nullptr;

    // Insert nodes into the linked list
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    cout << "Original Linked List: ";
    printList(head);

    // Find and print the middle node
    ListNode* mid = middleNode(head);
    cout << "Middle Node Value: " << mid->val << endl;

    return 0;
}
