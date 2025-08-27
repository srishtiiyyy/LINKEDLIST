#include <bits/stdc++.h>
using namespace std;

/**
 * 📝 QUESTION:
 * You are given two non-empty linked lists l1 and l2,
 * where each node contains a single digit. 
 * The digits are stored in reverse order (least significant digit first).
 *
 * TASK:
 *   - Add the two numbers and return the sum as a new linked list.
 *   - Each node of the result should also contain a single digit.
 *   - You may assume both numbers do not contain leading zeros,
 *     except the number 0 itself.
 *
 * ✅ Example:
 *    l1 = [2 -> 4 -> 3]  (represents 342)
 *    l2 = [5 -> 6 -> 4]  (represents 465)
 *    Output = [7 -> 0 -> 8] (represents 807)
 *
 * IDEA:
 *   - Traverse both lists simultaneously.
 *   - At each step, compute:
 *        sum = (digit from l1) + (digit from l2) + carry
 *   - Create a new node with value (sum % 10).
 *   - Update carry = sum / 10.
 *   - If one list ends before the other, continue with remaining list.
 *   - At the end, if carry > 0, add a new node for carry.
 *
 * ⏱ Time Complexity: O(max(N, M)) 
 * 📦 Space Complexity: O(1) extra (output list only)
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
 * FUNCTION: Adds two numbers represented by linked lists
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);  // dummy node to simplify result list handling
    ListNode* curr = dummy;              // pointer to build the result list
    int carry = 0;

    // Traverse both lists
    while (l1 != nullptr || l2 != nullptr) {
        int sum = carry;  // start with carry

        if (l1) { 
            sum += l1->val; 
            l1 = l1->next; 
        }
        if (l2) { 
            sum += l2->val; 
            l2 = l2->next; 
        }

        // Create new node for current digit
        curr->next = new ListNode(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }

    // If carry remains, add a new node
    if (carry) {
        curr->next = new ListNode(carry);
    }

    return dummy->next;  // skip dummy node
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
    // 🔹 Example: l1 = [2 -> 4 -> 3], l2 = [5 -> 6 -> 4]
    // Represents: 342 + 465 = 807

    // Create first list: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    // Call function
    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Sum List: ";
    printList(result); // Expected: 7 -> 0 -> 8

    return 0;
}
