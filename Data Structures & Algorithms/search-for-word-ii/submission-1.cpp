struct TrieNode {
    TrieNode *arr[26];
    bool is_end;
    TrieNode() {
        is_end = false;
        for (int i = 0; i < 26; ++i) arr[i] = nullptr;
    }
};
class Solution {
public:
    void insert(const string& word, TrieNode *root) {
        TrieNode *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->arr[idx]) curr->arr[idx] = new TrieNode;
            curr = curr->arr[idx];
        }
        curr->is_end = true;
    }

    void backtrack(vector<string>& result, vector<vector<char>>& board, 
                   TrieNode *curr, int r, int c, string curr_w) {
        // we have already decided the curr is valid
        if (curr->is_end) {
            result.push_back(curr_w);
            curr->is_end = false;
            // don't return as there could be longer words
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int cr = dr[i] + r;
            int cc = dc[i] + c;
            int m = board.size();
            int n = board[0].size();
            if (cr >= 0 && cc >= 0 && cr < m && cc < n && board[cr][cc] != '#' &&
                curr->arr[board[cr][cc] - 'a']) {
                    // the next one would have to exist
                    char repl = board[cr][cc];
                    board[cr][cc] = '#';
                    backtrack(result, board, curr->arr[repl - 'a'],
                              cr, cc, curr_w + repl);
                    board[cr][cc] = repl;
                }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode;
        // our first goal is to add all the words to the list
        for (const auto& word : words) {
            insert(word, root);
        }
        // now we have all words inserted and now we can backtrack on all of it
        vector<string> result;
        string curr;
        // we will try every position:
        // we will need a visited but can just use a sentinel value to mark it off
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->arr[board[i][j] - 'a']) {
                    char repl = board[i][j];
                    board[i][j] = '#';
                    backtrack(result, board, root->arr[repl - 'a'], i, j, curr + repl);
                    board[i][j] = repl;
                }
            }
        }
        return result;
    }
};
