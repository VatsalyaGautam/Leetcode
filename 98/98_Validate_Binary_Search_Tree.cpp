#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool validate(TreeNode* root, long long smaller, long long greater) {
        if (!root) return true;
        if (root->val > smaller && root->val < greater)
            return validate(root->left, smaller, root->val) && validate(root->right, root->val, greater);
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

// Driver program to test the solution
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    Solution sol;
    cout << (sol.isValidBST(root) ? "true" : "false") << endl;
    
    return 0;
}
