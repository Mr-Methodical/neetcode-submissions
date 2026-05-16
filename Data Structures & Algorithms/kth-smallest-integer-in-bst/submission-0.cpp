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
    int count(TreeNode *root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        // we could have a funcion that finds the depth of the left and make decision based on
        // that but I could see that repeating a lot of work honestly
        // we could go all the way down the left side
        // you know what let/s just go with this brute force way first
        int l = count(root->left);
        if (k <= l) return kthSmallest(root->left, k);
        if (k == l + 1) return root->val;
        return kthSmallest(root->right, k - l - 1);
    }
};
