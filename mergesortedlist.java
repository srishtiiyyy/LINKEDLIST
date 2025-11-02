/*
------------------------------------------------------------------------------
🧾 Problem: Merge Two Sorted Lists (LeetCode #21)
------------------------------------------------------------------------------
You are given the heads of two sorted linked lists, `list1` and `list2`.
Merge the two lists into a single sorted linked list.
The merged list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

------------------------------------------------------------------------------
Example 1:
Input:
List1 = [1, 2, 4]
List2 = [1, 3, 4]
Output:
[1, 1, 2, 3, 4, 4]

Example 2:
Input:
List1 = []
List2 = []
Output:
[]

Example 3:
Input:
List1 = []
List2 = [0]
Output:
[0]

------------------------------------------------------------------------------
Constraints:
- The number of nodes in both lists is in the range [0, 50].
- -100 <= Node.val <= 100
- Both `list1` and `list2` are sorted in **non-decreasing** order.
------------------------------------------------------------------------------
💡 Approach:
- Use **recursion** to compare the heads of both lists.
- Whichever node has the smaller value becomes the head of the merged list.
- Recur for the rest of the nodes accordingly.
- Base cases:
    - If one list is null, return the other.
- This ensures sorted merging without extra space.

Time Complexity: O(n + m)
Space Complexity: O(n + m) (due to recursion stack)
------------------------------------------------------------------------------
*/

import java.util.*;

// Definition for singly-linked list node
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class mergesortedlist {

    // Recursively merges two sorted linked lists
    static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;   // If list1 is empty
        if (list2 == null) return list1;   // If list2 is empty

        if (list1.val <= list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }

    // Function to print the linked list
    static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " -> " : ""));
            head = head.next;
        }
        System.out.println();
    }

    // Function to create a linked list from user input
    static ListNode createList(Scanner sc, int n) {
        if (n == 0) return null;
        ListNode head = new ListNode(sc.nextInt());
        ListNode current = head;
        for (int i = 1; i < n; i++) {
            current.next = new ListNode(sc.nextInt());
            current = current.next;
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input for first list
        System.out.print("Enter number of nodes in List1: ");
        int n1 = sc.nextInt();
        System.out.println("Enter elements of List1 in sorted order:");
        ListNode list1 = createList(sc, n1);

        // Input for second list
        System.out.print("Enter number of nodes in List2: ");
        int n2 = sc.nextInt();
        System.out.println("Enter elements of List2 in sorted order:");
        ListNode list2 = createList(sc, n2);

        // Merge and print result
        ListNode mergedHead = mergeTwoLists(list1, list2);
        System.out.println("\nMerged Sorted List:");
        printList(mergedHead);
    }
}
