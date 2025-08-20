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
  if (head == NULL) return head;   // case 1: empty list

if (k == 1) {                    // case 2: deleting head
    ListNode* temp = head;
    head = head->next;
    delete temp;                 // free memory of old head
    return head;
}

int cnt = 0;
ListNode* temp = head;
ListNode* prev = NULL;

while (temp != NULL) {           // traverse the list
    cnt++;
    if (cnt == k) {              // found the k-th node
        prev->next = prev->next->next;  // unlink it
        delete temp;             // free memory
        break;                   // done, stop loop
    }
    prev = temp;                 // move prev forward
    temp = temp->next;           // move temp forward
}
return head;                     // return possibly updated head
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
