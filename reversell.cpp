#include <bits/stdc++.h>
using namespace std;

/**
 * 📝 QUESTION:
 * Given the head of a singly linked list, reverse the list, 
 * and return the new head.
 *
 * Example:
 *   Input:  1 -> 2 -> 3 -> 4 -> 5
 *   Output: 5 -> 4 -> 3 -> 2 -> 1
 *
 * ✅ Constraints:
 *   - The number of nodes in the list is in the range [0, 5000].
 *   - -5000 <= Node.val <= 5000
 *
 * IDEA (Iterative 3-Pointer Method):
 *   1️⃣ Use three pointers → prev, curr (temp), next (front).
 *   2️⃣ Traverse through the list and reverse the links one by one.
 *   3️⃣ Finally, prev will point to the new head.
 *
 * ⏱ Time Complexity: O(N)
 * 📦 Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * FUNCTION: Reverse a linked list
 */
ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;   // current node
    ListNode* prev = nullptr; // previous node

    while (temp != nullptr) {
        ListNode* front = temp->next; // save next node
        temp->next = prev;            // reverse link
        prev = temp;                  // move prev forward
        temp = front;                 // move temp forward
    }

    return prev; // new head
}

/**
 * Helper: Print linked list
 */
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/**
 * MAIN FUNCTION
 */
int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
