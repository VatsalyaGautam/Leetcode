#include <bits/stdc++.h>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        int sum = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            ListNode *newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next;
        }

        return dummy->next;
    }
};

// Driver program
int main()
{
    // First linked list: 2 -> 4 -> 3
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Second linked list: 5 -> 6 -> 4
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Print the result: Expected output is 7 -> 0 -> 8
    std::cout << "Result: ";
    while (result != nullptr)
    {
        std::cout << result->val;
        if (result->next != nullptr)
            std::cout << " -> ";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;
}