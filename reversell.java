/*
------------------------------------------------------------------------------
🧾 Problem: Reverse Linked List
LeetCode #206

📘 Description:
Given the head of a singly linked list, reverse the list and return its new head.

💡 Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation:
We reverse the links between nodes such that the head becomes the tail and vice versa.
------------------------------------------------------------------------------
*/

import java.util.*;

// Definition for singly-linked list
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class reversell {

    // Function to reverse a linked list iteratively
    static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode temp = head;

        while (temp != null) {
            ListNode front = temp.next;  // store next node
            temp.next = prev;            // reverse link
            prev = temp;                 // move prev forward
            temp = front;                // move temp forward
        }

        return prev; // new head of reversed list
    }

    // Function to print the linked list
    static void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // Main function for user input
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input size of linked list
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n == 0) {
            System.out.println("Empty list!");
            return;
        }

        // Build the linked list
        System.out.println("Enter elements:");
        ListNode head = new ListNode(sc.nextInt());
        ListNode current = head;

        for (int i = 1; i < n; i++) {
            current.next = new ListNode(sc.nextInt());
            current = current.next;
        }

        System.out.println("Original list:");
        printList(head);

        // Reverse the list
        head = reverseList(head);

        System.out.println("Reversed list:");
        printList(head);
    }
}
