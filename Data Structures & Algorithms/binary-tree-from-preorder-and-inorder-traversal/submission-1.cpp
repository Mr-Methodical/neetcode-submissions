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
    int idx_pre = 0;
    int idx_in = 0;
    TreeNode *dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (idx_pre >= preorder.size()) return nullptr; // it's gone past the end
        if (inorder[idx_in] == limit) {
            idx_in++; // we should only go forward with idx_in when we do hit a limit
            return nullptr;
        } // then we have gotten up to a point that we hit it, so new branch
        // we can kind of go down it left and then do inorder
        TreeNode *root = new TreeNode(preorder[idx_pre++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // let's redo this from scratch no hash map approach we will do limit idea:
        return dfs(preorder, inorder, INT_MAX); // none will have the int_min
    }
};
