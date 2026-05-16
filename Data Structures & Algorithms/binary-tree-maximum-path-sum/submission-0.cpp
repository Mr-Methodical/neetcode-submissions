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
    int result = INT_MIN;
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));
        result = max(l + r + root->val, result);
        return max(l + root->val, r + root->val);
    }    
    int maxPathSum(TreeNode* root) {
        int res = dfs(root);
        return max(result, res);
    }
};
