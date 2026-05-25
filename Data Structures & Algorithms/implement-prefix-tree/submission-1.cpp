struct TrieNode {
    TrieNode *arr[26];
    bool is_end;
    TrieNode() {
        is_end = false;
        for (int i = 0; i < 26; ++i) arr[i] = nullptr;
    }
};

class PrefixTree {
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();       
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->arr[idx]) {
                curr->arr[idx] = new TrieNode();
            }
            curr = curr->arr[idx];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->arr[idx]) return false;
            curr = curr->arr[idx];
        }
        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->arr[idx]) return false;
            curr = curr->arr[idx];
        }
        return true;
    }
};
