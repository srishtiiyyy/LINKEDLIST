/*
====================================================
Problem: Odd Even Linked List
====================================================

Given the head of a singly linked list, group all the
nodes with odd indices together followed by the nodes
with even indices.

NOTE:
- Indexing is based on POSITION (1-based), not values.
- The relative order inside odd and even groups must remain same.

Examples:
----------------------------------------------------
Example 1:
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 3 -> 5 -> 2 -> 4

Example 2:
Input:  2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7
Output: 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4

Approach:
----------------------------------------------------
- Maintain two pointers:
  - odd  → tracks odd-positioned nodes
  - even → tracks even-positioned nodes
- Store the starting node of even list
- Rearrange pointers without changing node values
- Finally attach even list after odd list

Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/

class oddeven {

    // Definition for singly-linked list node
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Function to rearrange nodes by odd and even positions
    public static ListNode oddEvenList(ListNode head) {

        // If list is empty or has only one node
        if (head == null || head.next == null) {
            return head;
        }

        // Initialize odd and even pointers
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenStart = even; // Store start of even list

        // Rearranging nodes
        while (even != null && even.next != null) {
            odd.next = even.next;   // Link odd to next odd
            odd = odd.next;

            even.next = odd.next;  // Link even to next even
            even = even.next;
        }

        // Attach even list after odd list
        odd.next = evenStart;

        return head;
    }

    // Helper method to print linked list
    public static void printList(ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.next != null) System.out.print(" -> ");
            curr = curr.next;
        }
        System.out.println();
    }

    // Main method (NO object of Solution class used)
    public static void main(String[] args) {

        // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.println("Original List:");
        printList(head);

        // Rearranging odd and even nodes
        head = oddEvenList(head);

        System.out.println("After Odd-Even Arrangement:");
        printList(head);
    }
}
