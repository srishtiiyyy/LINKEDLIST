#include <bits/stdc++.h>
using namespace std;

/**
 * 📝 QUESTION:
 * You are given the head of a linked list.
 * TASK:
 *   - If there is a cycle in the linked list, return the node
 *     where the cycle begins.
 *   - If no cycle, return NULL.
 *
 * ✅ Example:
 *    Input:  head = [3,2,0,-4], where tail connects to node index 1 (value 2)
 *    Output: Node with value 2
 *
 * IDEA (Floyd’s Tortoise and Hare Algorithm):
 *   1. Use two pointers: slow and fast.
 *   2. Move slow by 1 step and fast by 2 steps.
 *   3. If slow == fast → cycle detected.
 *   4. To find cycle start:
 *         - Put one pointer at head, keep the other at meeting point.
 *         - Move both one step at a time.
 *         - The point they meet again = start of cycle.
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
 * FUNCTION: Detects cycle and returns the node where cycle begins.
 */
ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect if cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;  // cycle found
    }

    if (slow != fast) return nullptr;  // no cycle

    // Step 2: Find the starting node of cycle
    ListNode* start = head;
    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }

    return slow;  // node where cycle begins
}

/**
 * MAIN FUNCTION
 */
int main() {
    // 🔹 Example 1: Create list with a cycle
    // List: 3 -> 2 -> 0 -> -4
    // Tail connects to node with value 2
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: last node -> node with value 2
    head->next->next->next->next = head->next;

    ListNode* cycleNode = detectCycle(head);
    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // 🔹 Example 2: List without cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    ListNode* cycleNode2 = detectCycle(head2);
    if (cycleNode2) {
        cout << "Cycle detected at node with value: " << cycleNode2->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
