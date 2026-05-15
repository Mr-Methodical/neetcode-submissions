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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // we could use a queue feels most natural here
        queue<TreeNode *> q;
        vector<vector<int>> result;
        if (root) q.push(root);
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> curr;
            for (int i = 0; i < level_size; ++i) {
                TreeNode *n = q.front();
                q.pop();
                curr.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            result.push_back(curr);
        }
        return result;
    }
};
