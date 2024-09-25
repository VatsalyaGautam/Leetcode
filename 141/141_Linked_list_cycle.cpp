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
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        else if (head->next == NULL)
            return false;
        ListNode *tortoise = head->next;
        ListNode *hare = head->next->next;
        while (tortoise != NULL && hare != NULL)
        {
            if (tortoise == hare)
                return true;
            tortoise = tortoise->next;
            hare = hare->next;
            if (hare == NULL)
                return false;
            hare = hare->next;
        }
        return false;
    }
};

// Driver program
int main()
{
    Solution sol;

    // Creating a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 2 (cycle)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle

    if (sol.hasCycle(head))
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }

    // Free allocated memory (not required if there's a cycle)
    // Note: In a real scenario, you would need to break the cycle to free the nodes properly.

    return 0;
}