#include <bits/stdc++.h>
using namespace std;

/**
 * 📝 QUESTION:
 * You are given the head of a linked list where each node's value is either:
 *   - 0
 *   - 1
 *   - 2
 *
 * TASK:
 *   Sort the linked list so that all 0s come first, then 1s, and then 2s.
 *   Return the head of the sorted linked list.
 *
 * ✅ Example:
 *    Input:  1 -> 2 -> 0 -> 1 -> 2 -> 0
 *    Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2
 *
 * IDEA:
 *   - Instead of counting and rewriting values, we rearrange nodes into
 *     three separate lists:
 *        - One for 0s
 *        - One for 1s
 *        - One for 2s
 *   - Finally, connect them together in order: 0-list → 1-list → 2-list.
 *
 * WHY `zero = temp; one = temp; two = temp;`?
 *   - When we add a node to one of the lists, we must update the "tail pointer"
 *     of that list so the next insertion happens at the right place.
 *   - Example: 
 *        If we do `zero->next = temp;` → we attach the node after "zero".
 *        Then we must move `zero = temp;` → so that "zero" always points to the
 *        last node of the 0-list.
 *   - Without updating `zero = temp;`, multiple nodes would not get linked
 *     correctly, and we’d lose parts of the list.
 *
 * ⏱ Time Complexity: O(N)  (traverses list once)
 * 📦 Space Complexity: O(1) (no extra data structures, only dummy heads)
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
 * FUNCTION: Sorts a linked list of 0s, 1s, and 2s
 */
ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // Dummy heads for 0s, 1s, 2s
    ListNode* zeroHead = new ListNode(-1);
    ListNode* oneHead  = new ListNode(-1);
    ListNode* twoHead  = new ListNode(-1);

    // Tail pointers (point to the end of each list)
    ListNode* zero = zeroHead;
    ListNode* one  = oneHead;
    ListNode* two  = twoHead;

    // Traverse original list
    ListNode* temp = head;
    while (temp != nullptr) {
        if (temp->val == 0) {
            zero->next = temp;  // attach current node to 0s list
            zero = temp;        // move tail pointer of 0s
        }
        else if (temp->val == 1) {
            one->next = temp;   // attach current node to 1s list
            one = temp;         // move tail pointer of 1s
        }
        else {
            two->next = temp;   // attach current node to 2s list
            two = temp;         // move tail pointer of 2s
        }
        temp = temp->next;
    }

    // Connect the three lists together
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next  = twoHead->next;
    two->next  = nullptr;

    // New head of sorted list
    ListNode* newHead = zeroHead->next;

    // Delete dummy nodes (avoid memory leaks)
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
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
    // Example: 1 -> 2 -> 0 -> 1 -> 2 -> 0
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
