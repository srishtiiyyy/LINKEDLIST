/*
-----------------------------------------------------------------------------------------
🧮 Problem: Add Two Numbers (LeetCode #2)
-----------------------------------------------------------------------------------------
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in *reverse order*, and each node contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
---------
Input:  (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807

Constraints:
-------------
- The number of nodes in each linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number without leading zeros.

-----------------------------------------------------------------------------------------
💡 Approach (Using Linked List Traversal):
-----------------------------------------------------------------------------------------
1️⃣ Use two pointers (l1 and l2) to traverse both linked lists simultaneously.  
2️⃣ Maintain a variable `carry` to handle sums greater than 9.  
3️⃣ Use a dummy node to simplify result list creation.  
4️⃣ While either list has nodes left OR carry > 0:
      - Sum the current digits + carry.
      - Update carry = sum / 10.
      - Append new node with value = sum % 10.
5️⃣ Return dummy.next as the resulting linked list.  
-----------------------------------------------------------------------------------------
*/

import java.util.*;

// Definition for singly-linked list
class ListNode {
    int val;
    ListNode next;

    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class addtwonumbers {

    // 🔹 Static method to add two numbers represented as linked lists
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode ans = dummy;
        int carry = 0;

        // Traverse both linked lists
        while (l1 != null || l2 != null || carry != 0) {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;
            int sum = x + y + carry;

            carry = sum / 10;
            ans.next = new ListNode(sum % 10);
            ans = ans.next;

            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        return dummy.next;
    }

    // 🔹 Helper: Create linked list from array
    public static ListNode createList(int[] arr) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        for (int num : arr) {
            current.next = new ListNode(num);
            current = current.next;
        }
        return dummy.next;
    }

    // 🔹 Helper: Print linked list
    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val);
            if (node.next != null) System.out.print(" -> ");
            node = node.next;
        }
        System.out.println();
    }

    // 🔹 Helper: Read linked list input from user
    public static ListNode readListFromUser(Scanner sc) {
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " digits (in reverse order, least significant first):");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        return createList(arr);
    }

    // 🔹 MAIN FUNCTION (No object creation)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter first linked list:");
        ListNode l1 = readListFromUser(sc);

        System.out.println("Enter second linked list:");
        ListNode l2 = readListFromUser(sc);

        System.out.println("\nInput List 1:");
        printList(l1);
        System.out.println("Input List 2:");
        printList(l2);

        ListNode result = addTwoNumbers(l1, l2);

        System.out.println("\nResult (Sum List):");
        printList(result);
    }
}
