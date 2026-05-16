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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // let's do preorder with NULL stuff
        if (!root) return "N,";
        string retval = to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        return retval;
    }
    int idx = 0;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        // we need to
        // we might need a case for if idx is over data size but unlikely since we have N to counteract that
        if (data[idx] == 'N') {
            idx += 2; // skip over the comma
            return nullptr;
        }
        // now we need to figure out what number it is:
        int trav = idx + 1; // must be at least one digit long
        while (data[trav] != ',') {
            trav++;
        }
        int len_word = trav - idx;
        int multiplier = 1;
        int i = len_word;
        while (i > 1) {
            multiplier *= 10;
            i--;
        }
        int num = 0;
        for (int i = 0; i < len_word; ++i) {
            num += multiplier * (data[i + idx] - '0');
            multiplier /= 10;
        }
        idx = trav + 1; // to put us past the comma
        // now we have our number
        TreeNode *root = new TreeNode(num);
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};
