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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p); // so p is always smaller
        if (!root) return nullptr;
        TreeNode *lr = lowestCommonAncestor(root->left, p, q);
        TreeNode *rr = lowestCommonAncestor(root->right, p, q);
        // idea is if they are both nullptrs and are current thing is not either return nullptr
        // if both are not null then we found what we wanted and we return our current root
        // if only one is them is not null we will just return the not null one
        if ((lr && rr) || (root->val == p->val || root->val == q->val)) return root;
        if (!lr && !rr) return nullptr;
        if (lr) return lr;
        // only other option is rr returned something good
        return rr;
    }
};
