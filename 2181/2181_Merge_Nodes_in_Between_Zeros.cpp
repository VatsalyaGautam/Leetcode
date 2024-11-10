#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* current = head;
        
        while (temp) {
            int sum = 0;
            while (temp && temp->val != 0) {
                sum += temp->val;
                temp = temp->next;
            }
            current->val = sum;
            if (temp && temp->next) {
                current->next = current->next->next;
                current = current->next;
            } else {
                current->next = nullptr;
            }
            if (temp) temp = temp->next;
        }
        
        return head;
    }
};

// Driver Program
int main() {
    Solution sol;
    vector<int> values = {0, 3, 1, 0, 4, 5, 2, 0}; // Example input
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    for (int i = 1; i < values.size(); i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    head = sol.mergeNodes(head);
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}