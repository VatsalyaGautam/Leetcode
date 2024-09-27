#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *back = NULL;
        ListNode *current = head;
        ListNode *front = head->next;
        while (current != NULL)
        {
            ListNode *temp = front;
            current->next = back;
            back = current;
            current = front;
            if (front != NULL)
            {
                front = front->next;
            }
        }
        return back;
    }
};

// Driver program
int main()
{
    Solution sol;

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reversing the list
    ListNode *reversedHead = sol.reverseList(head);

    // Output reversed list
    ListNode *temp = reversedHead;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}