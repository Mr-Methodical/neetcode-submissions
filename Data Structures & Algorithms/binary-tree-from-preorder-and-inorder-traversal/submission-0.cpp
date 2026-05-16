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
    int pre_idx = 0;
    unordered_map<int, int> indices;
    TreeNode *build_tree_worker(vector<int>& preorder, int l, int r) {
        // our new node that we are creating is at the idx_pre
        // we need a base case where we return nullptr
        if (l > r) return nullptr;
        int root_val = preorder[pre_idx++];
        TreeNode *root = new TreeNode(root_val);
        int mid = indices[root_val];
        root->left = build_tree_worker(preorder, l, mid - 1);
        root->right = build_tree_worker(preorder, mid + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // maybe we have a hash_map value to idx for inorder
        for (int i = 0; i < inorder.size(); ++i) {
            indices[inorder[i]] = i;
        }
        return build_tree_worker(preorder, 0, inorder.size() - 1);
    }
};
