#include <bits/stdc++.h>
using namespace std;

// -------------------- Definition of ListNode --------------------
// A single node of the Linked List
struct ListNode {
    int val;          // data stored in node
    ListNode* next;   // pointer to next node

    // constructor for easy node creation
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// -------------------- Linked List Traversal --------------------
// Function that traverses the linked list and returns the values in a vector
vector<int> LLTraversal(ListNode* head) {
    ListNode* temp = head;   // start from head node
    vector<int> ans;         // store values of nodes

    while (temp != nullptr) {     // traverse till end
        ans.push_back(temp->val); // add current node's value
        temp = temp->next;        // move to next node
    }
    return ans;   // return all values collected
}

// -------------------- Main Function --------------------
int main() {
    // Step 1: Create nodes of the linked list manually
    ListNode* head = new ListNode(10);   // first node with value 10
    head->next = new ListNode(20);       // second node with value 20
    head->next->next = new ListNode(30); // third node with value 30
    head->next->next->next = new ListNode(40); // fourth node with value 40

    // Step 2: Call traversal function
    vector<int> result = LLTraversal(head);

    // Step 3: Print the traversal result
    cout << "Linked List Traversal: ";
    for (int val : result) {
        cout << val << " -> ";
    }
    cout << "NULL" << endl;

    // Step 4: Free dynamically allocated memory (Good Practice)
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
