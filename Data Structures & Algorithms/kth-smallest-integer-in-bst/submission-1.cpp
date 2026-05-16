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
    int result = -1;
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        kthSmallest(root->left, k);
        if (++count == k) result = root->val;
        kthSmallest(root->right, k);
        return result;
    }
};
