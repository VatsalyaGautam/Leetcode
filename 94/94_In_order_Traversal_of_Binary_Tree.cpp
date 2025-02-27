#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(ans, root);
        return ans;
    }

    void inOrder(vector<int>& vec, TreeNode* node) {
        if (node == nullptr) return;
        inOrder(vec, node->left);
        vec.push_back(node->val);
        inOrder(vec, node->right);
    }
};

// Driver program
int main() {
    // Creating a sample tree:
    //        1
    //         \
    //          2
    //         /
    //        3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Output the inorder traversal
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}