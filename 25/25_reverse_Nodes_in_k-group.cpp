#include <iostream>
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
    void reverse(ListNode *start)
    {
        ListNode *back = NULL;
        ListNode *temp = start;
        ListNode *nextn = temp->next;
        while (temp != NULL)
        {
            temp->next = back;
            back = temp;
            temp = nextn;
            if (temp != NULL)
                nextn = temp->next;
        }
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *temp = head;
        ListNode *kthnode = head;
        ListNode *previousEndnode = nullptr;

        for (int i = 0; i < k - 1; i++)
        {
            if (kthnode->next == nullptr)
                return head;
            kthnode = kthnode->next;
        }

        ListNode *nextnode = kthnode->next;
        while (kthnode != nullptr)
        {
            kthnode->next = nullptr;
            reverse(temp);

            if (previousEndnode != nullptr)
                previousEndnode->next = kthnode;
            if (temp == head)
                head = kthnode;

            previousEndnode = temp;
            temp->next = nextnode;
            temp = nextnode;
            kthnode = temp;

            for (int i = 0; i < k - 1 && kthnode != nullptr; i++)
                kthnode = kthnode->next;

            if (kthnode != nullptr)
                nextnode = kthnode->next;
        }
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
    ListNode *result = solution.reverseKGroup(head, k);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}