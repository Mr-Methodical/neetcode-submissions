/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode *root) {
        if (!root) return 0;
        int hl = height(root->left);
        int hr = height(root->right);
        if (hl == -1 || hr == -1) return -1;
        if (abs(hr - hl) > 1) return -1;
        return 1 + max(hr, hl);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
