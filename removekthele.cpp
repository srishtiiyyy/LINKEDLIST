#include <bits/stdc++.h>
using namespace std;

// ---------------- Node structure ----------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data1) : val(data1), next(nullptr) {}
};

// ---------------- Delete k-th node ----------------
ListNode* deleteKthNode(ListNode* head, int k) {
    if (head == nullptr) return nullptr;  // empty list
    if (k <= 0) return head;              // invalid k

    // Case 1: delete head
    if (k == 1) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Traverse to (k-1)th node
    ListNode* temp = head;
    for (int i = 1; temp != nullptr && i < k - 1; i++) {
        temp = temp->next;
    }

    // If k > length of list
    if (temp == nullptr || temp->next == nullptr) return head;

    // Delete k-th node
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

// ---------------- Print list ----------------
void printLL(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ---------------- Main ----------------
int main() {
    vector<int> arr = {12, 5, 8, 7};

    // Build linked list using while loop
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int i = 0;
    while (i < arr.size()) {
        ListNode* newNode = new ListNode(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        i++;
    }

    cout << "Original list: ";
    printLL(head);

    int k = 2; // delete 2nd node
    head = deleteKthNode(head, k);

    cout << "List after deleting " << k << "th node: ";
    printLL(head);

    return 0;
}
