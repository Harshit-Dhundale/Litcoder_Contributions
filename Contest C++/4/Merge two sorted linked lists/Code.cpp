#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* headX, ListNode* headY) {
    if (!headX) return headY;
    if (!headY) return headX;

    ListNode* mergedHead = nullptr;
    if (headX->val < headY->val) {
        mergedHead = headX;
        headX = headX->next;
    } else {
        mergedHead = headY;
        headY = headY->next;
    }

    ListNode* mergedTail = mergedHead;
    while (headX && headY) {
        if (headX->val < headY->val) {
            mergedTail->next = headX;
            headX = headX->next;
        } else {
            mergedTail->next = headY;
            headY = headY->next;
        }
        mergedTail = mergedTail->next;
    }

    mergedTail->next = headX ? headX : headY;
    return mergedHead;
}

int main() {
    int n, m, val;

    // Read and create first linked list
    cin >> n;
    ListNode *headX = nullptr, *tailX = nullptr;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (!headX) headX = tailX = new ListNode(val);
        else {
            tailX->next = new ListNode(val);
            tailX = tailX->next;
        }
    }

    // Read and create second linked list
    cin >> m;
    ListNode *headY = nullptr, *tailY = nullptr;
    for (int i = 0; i < m; ++i) {
        cin >> val;
        if (!headY) headY = tailY = new ListNode(val);
        else {
            tailY->next = new ListNode(val);
            tailY = tailY->next;
        }
    }

    // Merge and print the merged linked list
    ListNode *mergedHead = mergeTwoLists(headX, headY);
    while (mergedHead) {
        cout << mergedHead->val << endl;
        mergedHead = mergedHead->next;
    }

    return 0;
}
