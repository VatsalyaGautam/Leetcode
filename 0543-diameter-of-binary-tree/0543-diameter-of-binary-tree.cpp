/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        int lh = depth(root->left);
        int rh = depth(root->right);
        return 1 + max(lh, rh);
    }
    void dfs(TreeNode* root, int& maxi) {
        if (!root)
            return;
        maxi = max(maxi,  depth(root->left) + depth(root->right));
        dfs(root->left, maxi);
        dfs(root->right, maxi);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};