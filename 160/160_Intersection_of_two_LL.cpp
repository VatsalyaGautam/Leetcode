#include <iostream>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        // Traverse both lists, if one pointer reaches the end, switch to the other list
        while (tempA != tempB)
        {
            tempA = (tempA == nullptr) ? headB : tempA->next;
            tempB = (tempB == nullptr) ? headA : tempB->next;
        }
        return tempA; // Either the intersection node or nullptr
    }
};

// Driver program
int main()
{
    // Create two linked lists that intersect
    ListNode *common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(headA, headB);

    if (intersection)
    {
        std::cout << "Intersection at node with value: " << intersection->val << std::endl;
    }
    else
    {
        std::cout << "No intersection." << std::endl;
    }

    return 0;
}