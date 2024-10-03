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
    ListNode *sortList(ListNode *head)
    {
        vector<int> vec;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            vec.emplace_back(temp->val);
            temp = temp->next;
        }
        sort(vec.begin(), vec.end());
        temp = head;
        int i = 0;
        while (temp != nullptr && i < vec.size())
        {
            temp->val = vec[i];
            i++;
            temp = temp->next;
        }
        return head;
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