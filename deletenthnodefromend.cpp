#include <bits/stdc++.h>
using namespace std;

/**
 * 📝 QUESTION:
 * Given the head of a linked list, remove the n-th node from the end 
 * and return its head.
 *
 * Example:
 *   Input:  1 -> 2 -> 3 -> 4 -> 5,  n = 2
 *   Output: 1 -> 2 -> 3 -> 5
 *
 * ✅ Constraints:
 *   - 1 <= length of list <= 30
 *   - 1 <= n <= length
 *
 * IDEA (2-Pass Method):
 *   1️⃣ Traverse the list once to count total nodes (cnt).
 *   2️⃣ If cnt == n → we need to delete the head, so return head->next.
 *   3️⃣ Otherwise, move to (cnt-n)-th node (the node just before the one to be deleted).
 *   4️⃣ Adjust pointers: skip over the node to be deleted.
 *   5️⃣ Delete the node explicitly (good practice in C++).
 *
 * ⏱ Time Complexity: O(N)   (two passes)
 * 📦 Space Complexity: O(1) (constant extra space)
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
 * FUNCTION: Remove N-th node from end
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;

    // Step 1: Count length of list
    ListNode* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }

    // Step 2: Special case - delete head
    if (cnt == n) {
        ListNode* newHead = head->next;
        delete head;  // free memory
        return newHead;
    }

    // Step 3: Move to (cnt-n)-th node
    int res = cnt - n;
    temp = head;
    while (temp != nullptr) {
        res--;
        if (res == 0) break;
        temp = temp->next;
    }

    // Step 4: Delete target node
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;  // free memory

    return head;
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

    int n = 2; // remove 2nd node from end (node with value 4)
    head = removeNthFromEnd(head, n);

    cout << "After Removing " << n << "th Node From End: ";
    printList(head);

    return 0;
}
