struct TrieNode {
    TrieNode *arr[26];
    bool is_end;
    TrieNode() {
        is_end = false;
        for (int i = 0; i < 26; ++i) arr[i] = nullptr;
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->arr[idx]) curr->arr[idx] = new TrieNode();
            curr = curr->arr[idx];
        }
        curr->is_end = true;
    }
    
    bool helper_search(string& word, TrieNode *curr, int idx) {
        if (idx == word.size()) return curr->is_end;
        if (word[idx] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (curr->arr[i] && helper_search(word, curr->arr[i], idx + 1)) {
                    return true;
                }
            }
            return false;
        }
        // other case it is a normal letter
        int idx_next = word[idx] - 'a';
        if (!curr->arr[idx_next]) return false;
        return helper_search(word, curr->arr[idx_next], idx + 1);
    }

    bool search(string word) {
        return helper_search(word, root, 0);
    }
};
