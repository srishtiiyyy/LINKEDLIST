#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete a node when only that node is given (not the head)
void deleteNode(ListNode* node) {
    ListNode* prev = NULL;
    while (node != NULL && node->next != NULL) {
        node->val = node->next->val;  // Copy value of next node
        prev = node;                  // Keep track of previous node
        node = node->next;            // Move forward
    }
    prev->next = NULL;  // Disconnect the last node
    delete node;        // Free memory
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List: ";
    for (ListNode* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    // Delete node "3" (we pass pointer to node with value 3)
    deleteNode(head->next->next);

    cout << "After deleting node 3: ";
    for (ListNode* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    return 0;
}
/*
DETAILED EXPLANATION:

The problem is: Delete a node from a singly linked list when you are only given
access to that node (not the head). This is a common interview question.

➡ Approach:
1. Instead of removing the given node directly, we copy the data of the *next*
   node into the current node.
2. Then we move forward until the last node, repeating this "copy forward" process.
3. At the end, the last node becomes redundant, so we unlink it and free its memory.

Example:
Original List: 4 -> 5 -> 1 -> 9
Delete node: (5)
Step 1: copy 1 into 5 → 4 -> 1 -> 1 -> 9
Step 2: copy 9 into 1 → 4 -> 1 -> 9 -> 9
Step 3: remove last 9 → 4 -> 1 -> 9

Result: 4 -> 1 -> 9 ✅

⚠ Limitation:
This method cannot delete the last node, since there's no "next node" to copy from.
*/