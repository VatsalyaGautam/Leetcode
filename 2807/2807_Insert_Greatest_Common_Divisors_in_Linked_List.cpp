#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
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
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        if (a >= b)
        {
            return gcd(a % b, b);
        }
        return gcd(a, b % a);
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;
        while (temp->next != nullptr)
        {
            ListNode *newnode = new ListNode(gcd(temp->val, temp->next->val));
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        return head;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;

    // Creating a sample linked list: 12 -> 15 -> 10 -> nullptr
    ListNode *head = new ListNode(12);
    head->next = new ListNode(15);
    head->next->next = new ListNode(10);

    cout << "Original list: ";
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;

    head = solution.insertGreatestCommonDivisors(head);

    cout << "List after inserting GCDs: ";
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;

    return 0;
}