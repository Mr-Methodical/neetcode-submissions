class PrefixTree {
    PrefixTree *arr[26] = {};
    bool is_end = false;
public:
    PrefixTree() {
    }
    
    void insert(string word) {
        PrefixTree *curr = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->arr[idx]) {
                curr->arr[idx] = new PrefixTree();
            }
            curr = curr->arr[idx];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        PrefixTree *curr = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->arr[idx]) return false;
            curr = curr->arr[idx];
        }
        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        PrefixTree *curr = this;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->arr[idx]) return false;
            curr = curr->arr[idx];
        }
        return true;
    }
};
