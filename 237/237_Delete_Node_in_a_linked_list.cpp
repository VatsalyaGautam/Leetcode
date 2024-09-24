#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        int next_val = node->next->val;
        ListNode *ptr = node->next->next;
        node->val = next_val;
        node->next = ptr;
    }
};

// Helper function to print the linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main()
{
    // Creating a linked list: 4 -> 5 -> 1 -> 9
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original list: ";
    printList(head);

    // Node to be deleted: 5
    Solution sol;
    sol.deleteNode(head->next); // Deleting node with value 5

    cout << "After deletion: ";
    printList(head);

    return 0;
}