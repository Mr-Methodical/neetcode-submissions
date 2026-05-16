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
    bool isValidBST_worker(TreeNode *root, int low_bnd, int upp_bnd) {
        if (!root) return true;
        if (low_bnd < root->val && root->val < upp_bnd) return isValidBST_worker(root->left, low_bnd, root->val) &&
                                                               isValidBST_worker(root->right, root->val, upp_bnd);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST_worker(root, INT_MIN, INT_MAX);
    }
};
