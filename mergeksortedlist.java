/*
💡 PROBLEM: Merge K Sorted Linked Lists
----------------------------------------

📝 QUESTION:
You are given an array of `k` linked-lists, where each linked-list is sorted in ascending order.
Your task is to merge all the linked-lists into one sorted linked-list and return its head.

----------------------------------------
📥 INPUT:
- The first line contains an integer `k`, the number of linked lists.
- For each list:
  - An integer `n` (the number of elements in that list)
  - Followed by `n` sorted integers (elements of that list)

📤 OUTPUT:
- Print the merged sorted linked list.

----------------------------------------
💬 EXAMPLE:

Input:
3
3 1 4 5
3 1 3 4
2 2 6

Output:
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

----------------------------------------
🔍 EXPLANATION:
List 1: 1 -> 4 -> 5
List 2: 1 -> 3 -> 4
List 3: 2 -> 6

Merging all these sorted lists gives:
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

----------------------------------------
⏱️ TIME COMPLEXITY: O(N log N)
(N = total number of nodes across all lists)
🧮 SPACE COMPLEXITY: O(N)
----------------------------------------
*/

import java.util.*;

// ------------------------------------------------------------
// Definition for singly-linked list node
// ------------------------------------------------------------
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { 
        this.val = val; 
    }
    ListNode(int val, ListNode next) { 
        this.val = val; 
        this.next = next; 
    }
}

// ------------------------------------------------------------
// Main class containing mergeKLists() and main()
// ------------------------------------------------------------
public class mergeksortedlist {

    /**
     * Function to merge k sorted linked lists.
     * Uses a Min-Heap (PriorityQueue) to collect all elements,
     * then builds a single sorted linked list.
     */
    public static ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // Step 1: Push all node values into minHeap
        for (ListNode list : lists) {
            while (list != null) {
                minHeap.add(list.val);
                list = list.next;
            }
        }

        // Step 2: Build new sorted linked list
        ListNode dummy = new ListNode(-1);
        ListNode merged = dummy;

        while (!minHeap.isEmpty()) {
            merged.next = new ListNode(minHeap.remove());
            merged = merged.next;
        }

        // Step 3: Return head of merged list
        return dummy.next;
    }

    // ------------------------------------------------------------
    // Utility function to build a linked list from array
    // ------------------------------------------------------------
    public static ListNode buildList(int[] arr) {
        if (arr.length == 0) return null;
        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        for (int i = 1; i < arr.length; i++) {
            current.next = new ListNode(arr[i]);
            current = current.next;
        }
        return head;
    }

    // ------------------------------------------------------------
    // Utility function to print linked list
    // ------------------------------------------------------------
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }

    // ------------------------------------------------------------
    // Main function: takes user input and calls mergeKLists()
    // ------------------------------------------------------------
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of linked lists: ");
        int k = sc.nextInt();
        ListNode[] lists = new ListNode[k];

        // Input each linked list
        for (int i = 0; i < k; i++) {
            System.out.print("Enter number of elements in list " + (i + 1) + ": ");
            int n = sc.nextInt();
            int[] arr = new int[n];
            System.out.print("Enter elements (sorted): ");
            for (int j = 0; j < n; j++) arr[j] = sc.nextInt();
            lists[i] = buildList(arr);
        }

        // Merge and print final linked list
        System.out.println("\nMerged Sorted Linked List:");
        ListNode merged = mergeKLists(lists);
        printList(merged);

        sc.close();
    }
}
/*
====================================================
Problem: Merge K Sorted Linked Lists
Approach: Iterative Divide & Conquer (Bottom-Up)
====================================================

Time Complexity: O(N log K)
Space Complexity: O(1)  (excluding output list)

N = total number of nodes
K = number of linked lists
====================================================
*/

class Solution {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    // Merge two sorted linked lists
    private static ListNode mergeTwo(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }

        tail.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }

    // Merge K lists using iterative divide & conquer
    public static ListNode mergeKLists(ListNode[] lists) {

        int k = lists.length;
        if (k == 0) return null;

        // Interval doubles each iteration
        for (int interval = 1; interval < k; interval *= 2) {
            for (int i = 0; i + interval < k; i += interval * 2) {
                lists[i] = mergeTwo(lists[i], lists[i + interval]);
            }
        }
        return lists[0];
    }
}
