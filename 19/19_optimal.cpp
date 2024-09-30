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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return nullptr;
        if (head->next == NULL && n == 1)
            return nullptr;

        ListNode *fast = head;
        while (n--)
        {
            fast = fast->next;
            if (fast == NULL)
            {
                head = head->next;
                return head;
            }
        }

        ListNode *slow = head;
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;
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
    int n = 2; // Remove the 2nd node from the end
    ListNode *newHead = solution.removeNthFromEnd(head, n);

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