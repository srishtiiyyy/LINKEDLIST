/*
===============================================================================
Problem: Delete Node in a Linked List (LeetCode 237)
===============================================================================

You are given a node from a singly linked list.
You do NOT have access to the head of the list.

Your task is to delete this node from the linked list.

⚠️ Important Constraints:
- The given node is NOT the last node.
- You cannot traverse backwards.
- You cannot access the head of the list.

Example:
Input Linked List: 4 -> 5 -> 1 -> 9
Node to delete: 5
Output Linked List: 4 -> 1 -> 9

Approach:
- Copy the value of the next node into the current node
- Change the next pointer to skip the next node
- This effectively removes the given node

Time Complexity: O(1)
Space Complexity: O(1)
===============================================================================
*/

import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class deletenode{

    // Function to delete the given node (NO head access)
    static void deleteNode(ListNode node) {
        // Copy value of next node into current node
        node.val = node.next.val;

        // Skip the next node
        node.next = node.next.next;
    }

    // Helper function to print linked list
    static void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // Helper function to create linked list from array
    static ListNode createList(int[] arr) {
        ListNode head = new ListNode(arr[0]);
        ListNode curr = head;
        for (int i = 1; i < arr.length; i++) {
            curr.next = new ListNode(arr[i]);
            curr = curr.next;
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input size
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.print("Enter linked list elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Create linked list
        ListNode head = createList(arr);

        System.out.print("Enter value of node to delete: ");
        int delVal = sc.nextInt();

        // Find node to delete
        ListNode temp = head;
        while (temp != null && temp.val != delVal) {
            temp = temp.next;
        }

        if (temp == null || temp.next == null) {
            System.out.println("Invalid node (cannot delete last node)");
            return;
        }

        // Delete the node
        deleteNode(temp);

        System.out.print("Linked List after deletion: ");
        printList(head);
    }
}

// class Solution {
//     public void deleteNode(ListNode node) {
//         node.val = node.next.val;      // Copy next node's value
//         node.next = node.next.next;    // Skip the next node
//     }
// }