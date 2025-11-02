/*
------------------------------------------------------------------------------
🧾 Problem: Linked List Cycle (LeetCode #141)
------------------------------------------------------------------------------
Given the head of a linked list, determine if the linked list contains a cycle.

A linked list cycle occurs when a node’s next pointer points back to one of the previous nodes,
causing an infinite loop when traversing the list.

------------------------------------------------------------------------------
Example 1:
Input:
5
3 2 0 -4
1
Output:
Cycle detected: true

Explanation:
The linked list is 3 → 2 → 0 → -4
The last node connects back to the node at position 1 (0-based index), forming a cycle.

Example 2:
Input:
3
1 2 3
0
Output:
Cycle detected: false
Explanation:
The linked list 1 → 2 → 3 has no cycle.

------------------------------------------------------------------------------
Constraints:
- The number of nodes is in the range [0, 10^4].
- -10^5 <= Node.val <= 10^5
- Use O(1) extra space
------------------------------------------------------------------------------
Approach:
- Use Floyd’s Tortoise and Hare algorithm.
- Keep two pointers:
  - `slow` moves one step at a time.
  - `fast` moves two steps at a time.
- If they meet, a cycle exists.
- If `fast` reaches null, no cycle exists.
------------------------------------------------------------------------------
*/

import java.util.*;

// Definition for singly-linked list node
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class linklistcycle {

    // Detects if the linked list has a cycle
    static boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;        // Move 1 step
            fast = fast.next.next;   // Move 2 steps

            if (slow == fast) {      // Pointers meet → cycle found
                return true;
            }
        }

        return false; // Fast reached null → no cycle
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n == 0) {
            System.out.println("Empty list — no cycle.");
            return;
        }

        // Create linked list
        System.out.println("Enter node values:");
        ListNode head = new ListNode(sc.nextInt());
        ListNode current = head;
        ListNode[] nodes = new ListNode[n];
        nodes[0] = head;

        for (int i = 1; i < n; i++) {
            nodes[i] = new ListNode(sc.nextInt());
            current.next = nodes[i];
            current = current.next;
        }

        // Ask user for cycle position (0 means no cycle)
        System.out.print("Enter position (0-based) to connect tail to (-1 for no cycle): ");
        int pos = sc.nextInt();

        if (pos >= 0 && pos < n) {
            current.next = nodes[pos]; // Create cycle
        }

        // Detect cycle
        boolean result = hasCycle(head);
        System.out.println("Cycle detected: " + result);
    }
}
