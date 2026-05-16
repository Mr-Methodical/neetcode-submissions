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
    int cnt_bnd(TreeNode *root, int lower_bound) {
        if (!root) return 0;
        if (root->val >= lower_bound) return 1 + cnt_bnd(root->left, root->val) + cnt_bnd(root->right, root->val);
        return cnt_bnd(root->left, lower_bound) + cnt_bnd(root->right, lower_bound);
    }
    int goodNodes(TreeNode* root) {
        // it is good if nothing above it is bigger basically
        // so we can push down some value
        return cnt_bnd(root, INT_MIN);
    }
};
