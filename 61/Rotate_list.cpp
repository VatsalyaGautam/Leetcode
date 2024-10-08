#include <bits/stdc++.h>
using namespace std;
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *temp = head;
        int cnt = 1;

        // Count the total number of nodes
        while (temp->next != nullptr)
        {
            temp = temp->next;
            cnt++;
        }

        // Reduce k to within bounds of list length
        k = (k >= cnt) ? k % cnt : k;
        if (k == 0)
            return head;

        temp = head;
        cnt = cnt - k - 1;

        // Move to the node where rotation will happen
        while (cnt--)
        {
            temp = temp->next;
        }

        ListNode *nextnode = temp->next;
        temp->next = nullptr; // Break the link

        ListNode *newhead = nextnode;

        // Move to the end of the rotated part
        while (nextnode->next != nullptr)
        {
            nextnode = nextnode->next;
        }

        nextnode->next = head; // Link the rotated part to the original head
        head = newhead;

        return head;
    }
};

// Driver program to test above
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int k = 2;
    ListNode *result = solution.rotateRight(head, k);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}