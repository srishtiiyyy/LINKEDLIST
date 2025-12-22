/*
====================================================
Problem: Linked List Cycle II (Detect Cycle Start)
====================================================

Given the head of a singly linked list, return the node
where the cycle begins. If there is no cycle, return null.

IMPORTANT:
- Do NOT modify the linked list.
- Use O(1) extra space.

Example:
----------------------------------------------------
Input:
3 -> 2 -> 0 -> -4
     ^           |
     |___________|

Output:
Node with value 2 (cycle starts here)

Approach (Floyd’s Algorithm):
----------------------------------------------------
1. Use two pointers:
   - slow moves 1 step
   - fast moves 2 steps

2. If slow and fast meet → cycle exists

3. Place one pointer at head and move both pointers
   one step at a time until they meet again.
   The meeting point is the start of the cycle.

Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/

public class linklistcycle2 {

    // Definition for singly-linked list node
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Method to detect cycle and return starting node
    public static ListNode detectCycle(ListNode head) {

        // Edge case: empty list or single node
        if (head == null || head.next == null) return null;

        ListNode slow = head;
        ListNode fast = head;

        // Step 1: Detect cycle
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) break; // Cycle detected
        }

        // If no cycle found
        if (slow != fast) return null;

        // Step 2: Find cycle start
        ListNode p = head;
        while (p != slow) {
            p = p.next;
            slow = slow.next;
        }

        return p; // Cycle starting node
    }

    // Main method (NO object of Solution class used)
    public static void main(String[] args) {

        // Creating nodes
        ListNode head = new ListNode(3);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(0);
        ListNode node4 = new ListNode(-4);

        // Linking nodes: 3 -> 2 -> 0 -> -4
        head.next = node2;
        node2.next = node3;
        node3.next = node4;

        // Creating cycle: -4 -> 2
        node4.next = node2;

        // Detect cycle start
        ListNode cycleStart = detectCycle(head);

        if (cycleStart != null) {
            System.out.println("Cycle detected at node with value: " + cycleStart.val);
        } else {
            System.out.println("No cycle detected");
        }
    }
}
