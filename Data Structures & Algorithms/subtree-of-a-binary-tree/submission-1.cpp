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
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) return false;
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // we could just check every single node to see if it is the same tree
        if (!subRoot) return true;
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        /*
        // only when we see a match do we use && else use ||
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        } else {
            // they are equal
            return isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right);
        }
        // the only case that I am missing is kind of what happens if there are same values then there might still 
        // be a subtree further down so we would have to bring the subtree with us somehow actually
        */
    }
};
