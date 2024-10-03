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
    ListNode *findMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left != nullptr)
            temp->next = left;
        if (right != nullptr)
            temp->next = right;

        return dummy->next;
    }

    ListNode *mergeSort(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *middle = findMiddle(head);
        ListNode *secondHead = middle->next;
        middle->next = nullptr;

        ListNode *left = mergeSort(head);
        ListNode *right = mergeSort(secondHead);

        return merge(left, right);
    }

    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};

// Driver program
int main()
{
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;
    ListNode *sortedHead = solution.sortList(head);

    // Print the sorted linked list
    ListNode *temp = sortedHead;
    while (temp != nullptr)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Clean up the linked list
    while (sortedHead != nullptr)
    {
        ListNode *toDelete = sortedHead;
        sortedHead = sortedHead->next;
        delete toDelete;
    }

    return 0;
}