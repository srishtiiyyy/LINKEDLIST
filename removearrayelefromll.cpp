#include <bits/stdc++.h>
using namespace std;

/**
 * 📝 QUESTION:
 * You are given:
 *   1. A singly linked list.
 *   2. An array `nums`.
 *
 * TASK:
 *   - Remove all nodes from the linked list whose values are present in `nums`.
 *   - Return the new head of the modified linked list.
 *
 * ✅ Example:
 *    Linked List:  1 -> 2 -> 3 -> 4 -> 5
 *    nums = {2, 4}
 *    Output Linked List: 1 -> 3 -> 5
 *
 * IDEA:
 *   - Put all elements of nums into a hash set for O(1) lookup.
 *   - First, check if head itself needs to be removed.
 *   - Then iterate and skip all nodes whose values exist in nums.
 *
 * Time Complexity: O(N + M)
 * Space Complexity: O(M)
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
 * FUNCTION: Removes nodes from linked list if their value exists in nums
 */
ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> st(begin(nums), end(nums)); // store nums in hash set

    // STEP 1: Remove nodes from the front if head itself is unwanted
    while (head != nullptr && st.find(head->val) != st.end()) {
        head = head->next; // move head forward
    }

    // STEP 2: Traverse and skip nodes
    ListNode* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (st.find(curr->next->val) != st.end()) {
            curr->next = curr->next->next; // unlink the node
        } else {
            curr = curr->next; // move forward
        }
    }
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

    // nums array = {2, 4}
    vector<int> nums = {2, 4};

    cout << "Original List: ";
    printList(head);

    // Call function directly
    head = modifiedList(nums, head);

    cout << "Modified List (after removing nums): ";
    printList(head);

    return 0;
}
