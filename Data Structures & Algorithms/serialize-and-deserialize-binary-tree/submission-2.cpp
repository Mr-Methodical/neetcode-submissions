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
    vector<string> tokens;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if (idx == 0) {
            stringstream ss(data);
            string token;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
        }
        if (tokens[idx] == "N") {
            idx++;
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(tokens[idx++]));
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};
