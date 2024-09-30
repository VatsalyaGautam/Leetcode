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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return nullptr;
        if (head->next->next == NULL)
        {
            head->next = NULL;
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next->next != NULL && fast->next->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return head;
    }
};

// Driver program
int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode *newHead = solution.deleteMiddle(head);

    // Print the modified list
    ListNode *temp = newHead;
    while (temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Clean up the linked list
    while (newHead != NULL)
    {
        ListNode *toDelete = newHead;
        newHead = newHead->next;
        delete toDelete;
    }

    return 0;
}