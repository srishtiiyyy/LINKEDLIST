/*
====================================================
Problem: Convert Sorted List to Binary Search Tree
====================================================

Given the head of a singly linked list where elements
are sorted in ascending order, convert it to a
height-balanced Binary Search Tree (BST).

A height-balanced BST is defined as:
- The depth of the two subtrees of every node never
  differs by more than 1.

Example:
----------------------------------------------------
Input:
-10 -> -3 -> 0 -> 5 -> 9

Output:
        0
       / \
     -3   9
     /   /
   -10  5

Approach:
----------------------------------------------------
1. Use slow and fast pointers to find the middle node.
2. The middle node becomes the root of BST.
3. Left part of the list forms left subtree.
4. Right part of the list forms right subtree.
5. Recursively apply the same logic.

Why this works:
----------------------------------------------------
- Middle element ensures height balance.
- Linked list is already sorted → BST property holds.

Time Complexity:
----------------------------------------------------
O(n log n)  (each recursive call scans part of list)

Space Complexity:
----------------------------------------------------
O(log n) recursion stack
====================================================
*/

public class sortedListToBST {

    // Definition for singly-linked list node
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Definition for binary tree node
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
            this.left = this.right = null;
        }
    }

    // Convert sorted linked list to height-balanced BST
    public static TreeNode sortedListToBST(ListNode head) {

        // Base case: empty list
        if (head == null) return null;

        // Base case: single node
        if (head.next == null) {
            return new TreeNode(head.val);
        }

        ListNode slow = head;
        ListNode fast = head;
        ListNode prevSlow = null;

        // Find middle node using slow & fast pointers
        while (fast != null && fast.next != null) {
            prevSlow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // slow is middle node → root
        TreeNode root = new TreeNode(slow.val);

        // Cut the list to form left subtree
        prevSlow.next = null;

        // Recursively build left and right subtrees
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(slow.next);

        return root;
    }

    // Inorder traversal (should print sorted order)
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    // Main method (NO object of Solution class used)
    public static void main(String[] args) {

        // Create sorted linked list: -10 -> -3 -> 0 -> 5 -> 9
        ListNode head = new ListNode(-10);
        head.next = new ListNode(-3);
        head.next.next = new ListNode(0);
        head.next.next.next = new ListNode(5);
        head.next.next.next.next = new ListNode(9);

        // Convert to BST
        TreeNode root = sortedListToBST(head);

        // Print inorder traversal of BST
        System.out.println("Inorder Traversal of BST:");
        inorder(root);   // Output should be sorted
    }
}
