/*
====================================================
Problem: Delete the Middle Node of a Linked List
====================================================

You are given the head of a singly linked list.
Delete the middle node, and return the head of the modified linked list.

Definition of middle:
- If the list has odd length, delete the exact middle node.
- If the list has even length, delete the second middle node.

Examples:
----------------------------------------------------
Example 1:
Input:  1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
Output: 1 -> 3 -> 4 -> 1 -> 2 -> 6

Example 2:
Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 2 -> 4

Example 3:
Input:  2 -> 1
Output: null

Constraints:
- The number of nodes is in the range [1, 10^5]
- Node values are integers

Approach:
----------------------------------------------------
Use two pointers:
- slow pointer moves 1 step
- fast pointer moves 2 steps

When fast reaches the end,
slow will be at the middle node.

We also keep a `prev` pointer to unlink the middle node.

Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/

class deletemiddle {

    // Definition for singly-linked list node
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Method to delete the middle node
    public static ListNode deleteMiddle(ListNode head) {

        // If list is empty or has only one node
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        // Move slow by 1 and fast by 2
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Remove the middle node
        prev.next = slow.next;

        return head;
    }

    // Helper method to print the linked list
    public static void printList(ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.next != null) System.out.print(" -> ");
            curr = curr.next;
        }
        System.out.println();
    }

    // Main method (no object of Solution class used)
    public static void main(String[] args) {

        // Creating linked list: 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
        ListNode head = new ListNode(1);
        head.next = new ListNode(3);
        head.next.next = new ListNode(4);
        head.next.next.next = new ListNode(7);
        head.next.next.next.next = new ListNode(1);
        head.next.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next.next = new ListNode(6);

        System.out.println("Original List:");
        printList(head);

        // Deleting middle node
        head = deleteMiddle(head);

        System.out.println("After Deleting Middle Node:");
        printList(head);
    }
}
