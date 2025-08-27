#include <bits/stdc++.h>
using namespace std;

/*
====================================================================
💡 Problem: Insert Greatest Common Divisors in Linked List (LeetCode 2807)

📝 Statement:
You are given the head of a linked list of integers.
Between every two adjacent nodes, insert a new node whose value is
the GCD (Greatest Common Divisor) of those two nodes.

Return the modified linked list.

--------------------------------------------------------------------
🔹 Example:
Input:  head = [18,6,10,3]
Process:
- GCD(18,6) = 6 → insert between 18 and 6
- GCD(6,10) = 2 → insert between 6 and 10
- GCD(10,3) = 1 → insert between 10 and 3
Output: [18,6,6,2,10,1,3]

--------------------------------------------------------------------
🔹 Approach:
1. Traverse the linked list with two pointers: curr and nextnode.
2. For each adjacent pair (curr->val, nextnode->val), compute gcd.
3. Create a new node with this gcd and insert it between them.
4. Continue until the end of the list.

--------------------------------------------------------------------
⏱️ Time Complexity: O(N * log(min(a,b)))
- N = number of nodes
- Each gcd takes log(min(a,b)) in worst case

💾 Space Complexity: O(1)
- We only insert nodes in-place without extra storage

====================================================================
*/

// ------------------- Definition for singly-linked list -------------------
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// ------------------- Solution Class -------------------
class Solution {
public:
    /*
    Function: insertGreatestCommonDivisors
    Inserts gcd nodes between every pair of adjacent nodes
    */
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* nextnode = head->next;

        while (nextnode != NULL) {
            // Compute gcd of current and next node values
            int gcdVal = __gcd(curr->val, nextnode->val);
            // };

// ------------------- Custom GCD Function -------------------
// int myGCD(int a, int b) {
//     // Euclidean Algorithm
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }


            // Create new node with gcd value
            ListNode* gcdnode = new ListNode(gcdVal);

            // Insert gcdnode between curr and nextnode
            curr->next = gcdnode;
            gcdnode->next = nextnode;

            // Move forward
            curr = nextnode;
            nextnode = nextnode->next;
        }
        return head;
    }
};

// ------------------- Helper Functions -------------------

// Function to create linked list from vector
ListNode* createLinkedList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// ------------------- Main Function -------------------
int main() {
    /*
    Example Input: [18, 6, 10, 3]
    Expected Output: [18, 6, 6, 2, 10, 1, 3]
    */

    vector<int> arr = {18, 6, 10, 3};

    // Create linked list
    ListNode* head = createLinkedList(arr);
    cout << "Original List: ";
    printLinkedList(head);

    // Apply solution
    Solution sol;
    head = sol.insertGreatestCommonDivisors(head);

    // Print modified list
    cout << "Modified List: ";
    printLinkedList(head);

    return 0;
}
