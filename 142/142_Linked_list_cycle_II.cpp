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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        else if (head->next == NULL)
            return NULL;
        set<ListNode *> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (st.find(temp) != st.end())
            {
                return temp; // Cycle detected
            }
            st.insert(temp);
            temp = temp->next;
        }
        return NULL; // No cycle
    }
};

// Driver program
int main()
{
    Solution sol;

    // Creating a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 2 (cycle starts at node 2)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle at node 2

    ListNode *cycleNode = sol.detectCycle(head);

    if (cycleNode != NULL)
    {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }

    return 0;
}