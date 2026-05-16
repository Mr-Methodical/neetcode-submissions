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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> result;
        if (root) q.push(root);
        while (!q.empty()) {
            int level_size = q.size();
            int val = 0;
            for (int i = 0; i < level_size; ++i) {
                TreeNode *n = q.front();
                q.pop();
                val = n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            result.push_back(val);
        }
        return result;
    }
};
