class Solution {
public:
    // we could do binary search to find the word in log n time where n is number of words in wordDict
    // but we won't do this right away
    bool dfs(string& s, vector<string>& wordDict, int idx, vector<bool>& memo) {
        if (memo[idx] != true) return false; // we already explored down and this path was bad
        if (idx == s.size()) return true;
        bool ret = false;
        for (string& word : wordDict) {
            int n = word.size();
            if (idx + n > s.size()) continue;
            bool match = true;
            for (int i = 0; i < n; ++i) {
                if (s[idx + i] != word[i]) {
                    match = false;
                    break;
                }
            }
            if (match && dfs(s, wordDict, idx + n, memo)) return true;
        }
        memo[idx] = false;
        return false;
    }   
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.size() + 1, true); // we would never return on true as it would be worthless
        return dfs(s, wordDict, 0, memo);
    }
};
