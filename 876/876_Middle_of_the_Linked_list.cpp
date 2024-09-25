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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *mover = head;
        int n = 1;
        while (mover->next != NULL)
        {
            mover = mover->next;
            n++;
        }
        mover = head;
        int i = (n / 2);
        while (i--)
        {
            mover = mover->next;
        }
        return mover;
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

    ListNode *middle = sol.middleNode(head);

    cout << "Middle node value: " << middle->val << endl;

    return 0;
}