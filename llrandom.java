/*
====================================================
Problem: Linked List Random Node
====================================================

Given a singly linked list, return a random node's value
from the list. Each node must have the SAME probability
of being chosen.

You will be given the head of the linked list.
The linked list can be very large, so you should NOT
store all node values in extra space.

Example:
----------------------------------------------------
Input:
1 -> 2 -> 3

Possible Outputs:
1 or 2 or 3 (each with probability 1/3)

Approach: Reservoir Sampling
----------------------------------------------------
- Traverse the list once
- For the i-th node, replace the answer with
  probability 1/i
- This guarantees uniform randomness

Why it works:
----------------------------------------------------
Each node has an equal chance of being selected
without knowing the length of the list in advance.

Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/

public class llrandom {

    // Definition for singly-linked list node
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Head of the linked list
    private ListNode head;

    // Constructor receives the head of the list
    public Solution(ListNode head) {
        this.head = head;
    }

    // Returns a random node value
    public int getRandom() {

        ListNode current = head;
        int chosenValue = 0;
        int i = 1;

        // Reservoir Sampling
        while (current != null) {

            // Replace chosenValue with probability 1/i
            if (Math.random() * i < 1) {
                chosenValue = current.val;
            }

            current = current.next;
            i++;
        }

        return chosenValue;
    }

    // Main method (for testing & GitHub demo)
    public static void main(String[] args) {

        // Create linked list: 10 -> 20 -> 30 -> 40
        ListNode head = new ListNode(10);
        head.next = new ListNode(20);
        head.next.next = new ListNode(30);
        head.next.next.next = new ListNode(40);

        // Create Solution object (required by problem)
        Solution solution = new Solution(head);

        // Call getRandom multiple times
        System.out.println("Random node values:");
        for (int i = 0; i < 5; i++) {
            System.out.println(solution.getRandom());
        }
    }
}
