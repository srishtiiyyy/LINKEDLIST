#include <bits/stdc++.h>
using namespace std;

// ---------------- Node structure ----------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data1) : val(data1), next(nullptr) {}
};

// ---------------- Delete node with value X ----------------
ListNode* deleteNodeWithValueX(ListNode* head, int X) {
    if (head == nullptr) return head;

    // Case 1: if head node itself holds X
    if (head->val == X) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Case 2: traverse the list to find X
    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (temp != nullptr) {
        if (temp->val == X) {
            prev->next = temp->next;  // unlink node
            delete temp;              // free memory
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// ---------------- Print linked list ----------------
void printLL(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ---------------- Main ----------------
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Empty list" << endl;
        return 0;
    }

    cout << "Enter " << n << " elements: ";
    int val;
    cin >> val;

    // Create head
    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    // Build list using loop
    for (int i = 1; i < n; i++) {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    cout << "Original list: ";
    printLL(head);

    int X;
    cout << "Enter value to delete: ";
    cin >> X;

    head = deleteNodeWithValueX(head, X);

    cout << "List after deleting value " << X << ": ";
    printLL(head);

    return 0;
}
