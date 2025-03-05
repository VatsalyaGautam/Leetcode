#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool DFS(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root->val == target->val) return true;
        if (DFS(root->left, target, path) || DFS(root->right, target, path)) 
            return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathOfP, pathOfQ;
        DFS(root, p, pathOfP);
        DFS(root, q, pathOfQ);
        TreeNode* lastCommon;
        for (int i = 0; i < min(pathOfP.size(), pathOfQ.size()); i++) {
            if (pathOfP[i]->val == pathOfQ[i]->val) {
                lastCommon = pathOfP[i];
            }
        }
        return lastCommon;
    }
};

// Driver program to test the solution
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << lca->val << endl;
    
    return 0;
}