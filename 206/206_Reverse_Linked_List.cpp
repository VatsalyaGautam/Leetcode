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
        if (head == NULL)
            return NULL;
        ListNode *temp = head;

        stack<int> vec;
        while (temp != NULL)
        {
            vec.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            temp->val = vec.top();
            vec.pop();
            temp = temp->next;
        }

        return head;
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