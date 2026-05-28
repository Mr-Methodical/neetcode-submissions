/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *>& seen) {
        Node *curr = new Node(node->val);
        seen.insert({node, curr});
        vector<Node *> curr_ns;
        for (auto const& n : node->neighbors) {
            Node *ret = (seen.contains(n)) ? seen[n] : dfs(n, seen);
            curr_ns.push_back(ret);
        }
        curr->neighbors = curr_ns;
        return curr;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        // we need some way to detect cycles, like we need to make sure it is a new node:
        unordered_map<Node *, Node *> seen; // mapping actual to new
        return dfs(node, seen);
    }
};
