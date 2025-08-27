#include <bits/stdc++.h>
using namespace std;

/**
 * 📝 QUESTION:
 * You are given the head of a singly linked list.
 * TASK:
 *   - Group all nodes with odd indices together, followed by nodes with even indices.
 *   - Indexing starts at 1 (head is position 1 → odd).
 *   - Return the reordered list.
 *
 * ✅ Example:
 *    Input:  1 -> 2 -> 3 -> 4 -> 5
 *    Odd-indexed nodes: 1, 3, 5
 *    Even-indexed nodes: 2, 4
 *    Output: 1 -> 3 -> 5 -> 2 -> 4
 *
 * IDEA:
 *   - Maintain two separate pointers:
 *        odd  = head (first node)
 *        even = head->next (second node)
 *   - Keep track of starting node of even list (evenStart).
 *   - Rearrange links such that odd nodes are connected together,
 *     and even nodes are connected together.
 *   - Finally, attach odd list's end to even list's head.
 *
 * ⏱ Time Complexity: O(N)   (each node visited once)
 * 📦 Space Complexity: O(1) (no extra space, just re-linking)
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
 * FUNCTION: Reorder linked list into odd-index nodes followed by even-index nodes
 */
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* odd = head;              // start of odd list
    ListNode* even = head->next;       // start of even list
    ListNode* evenStart = even;        // save starting point of even list

    // Rearrange links until we exhaust either odd or even list
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;        // connect odd -> next odd
        odd = odd->next;               // move odd pointer

        even->next = odd->next;        // connect even -> next even
        even = even->next;             // move even pointer
    }

    // Attach even list after odd list
    odd->next = evenStart;

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
    // 🔹 Manually create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Call function
    head = oddEvenList(head);

    cout << "Reordered List (Odd -> Even): ";
    printList(head);

    return 0;
}
