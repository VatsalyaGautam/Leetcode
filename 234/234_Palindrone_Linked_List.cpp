#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *reverse(ListNode *ptr)
    {
        ListNode *back = NULL;
        ListNode *current = ptr;
        ListNode *front = NULL;
        if (current != NULL)
        {
            front = ptr->next;
        }

        while (current != NULL)
        {
            current->next = back;
            back = current;
            current = front;
            if (front != NULL)
            {
                front = front->next;
            }
        }
        return back;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        // Find the middle of the list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *newhead = reverse(slow);
        ListNode *temphead = newhead;

        // Compare the two halves
        ListNode *oldhead = head;
        while (temphead != NULL)
        {
            if (temphead->val != oldhead->val)
            {
                reverse(newhead); // Revert the list back
                return false;
            }
            oldhead = oldhead->next;
            temphead = temphead->next;
        }

        // Revert the second half back to original
        reverse(newhead);
        return true;
    }
};

// Driver program
int main()
{
    Solution sol;

    // Create a linked list: 1 -> 2 -> 2 -> 1
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Check if the linked list is a palindrome
    if (sol.isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}