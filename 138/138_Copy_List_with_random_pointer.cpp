#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *tempog = head;
        Node *dummy = new Node(-1);
        Node *tempcpy = dummy;
        unordered_map<Node *, Node *> mpp;

        // Create deep copies of the nodes without handling random pointers
        while (tempog != nullptr)
        {
            Node *newnode = new Node(tempog->val);
            tempcpy->next = newnode;
            tempcpy = tempcpy->next;
            mpp[tempog] = tempcpy;
            tempog = tempog->next;
        }

        // Reset pointers to the beginning
        tempog = head;
        tempcpy = dummy->next;

        // Assign random pointers in the copied list
        while (tempog != nullptr && tempcpy != nullptr)
        {
            tempcpy->random = mpp[tempog->random];
            tempcpy = tempcpy->next;
            tempog = tempog->next;
        }

        return dummy->next;
    }
};

// Driver program to test the solution
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->next = third;

    // Setting up random pointers
    head->random = third;   // Random of 1 points to 3
    second->random = head;  // Random of 2 points to 1
    third->random = second; // Random of 3 points to 2

    Solution solution;
    Node *copiedList = solution.copyRandomList(head);

    // Output copied list values and random pointers
    Node *temp = copiedList;
    while (temp != nullptr)
    {
        cout << "Node Val: " << temp->val;
        if (temp->random != nullptr)
        {
            cout << ", Random points to: " << temp->random->val << endl;
        }
        else
        {
            cout << ", No random pointer" << endl;
        }
        temp = temp->next;
    }

    return 0;
}