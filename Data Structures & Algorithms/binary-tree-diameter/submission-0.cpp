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
    int result = 0;
    int maxdepth(TreeNode *root) {
        if (!root) return 0;
        int ml = maxdepth(root->left);
        int mr = maxdepth(root->right);
        result = max(result, ml + mr);
        return max(1 + ml, 1 + mr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return result;
    }
};
