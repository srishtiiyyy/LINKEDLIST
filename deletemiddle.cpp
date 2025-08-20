#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

/*
   Function: deleteMiddle
   -----------------------
   Deletes the middle node of a singly linked list.

   Approach:
   - Use two pointers: slow and fast.
   - Move fast by 2 steps and slow by 1 step.
   - When fast reaches the end, slow will be at the middle node.
   - Maintain a prev pointer to connect the node before slow to the node after slow.
   - Finally, delete the middle node to free memory.
*/
ListNode* deleteMiddle(ListNode* head) {
    // Edge case: if list is empty or has only one node, return NULL
    if (head == nullptr || head->next == nullptr) {
        delete head; 
        return nullptr;
    }

    ListNode* slow = head;     // moves 1 step at a time
    ListNode* fast = head;     // moves 2 steps at a time
    ListNode* prev = nullptr;  // keeps track of node before slow

    // Traverse until fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Now, 'slow' is at the middle node
    prev->next = slow->next;  // unlink middle node
    delete slow;              // free memory

    return head;
}

// Utility function to insert node at the end
void insertAtTail(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code
int main() {
    ListNode* head = nullptr;

    // Insert nodes into linked list
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    cout << "Original Linked List: ";
    printList(head);

    // Delete middle node
    head = deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printList(head);

    return 0;
}

