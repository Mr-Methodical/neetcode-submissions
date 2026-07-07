class Solution {
public:
    int dfs(string& s, int idx, vector<int>& memo) {
        if (idx == s.size()) return 1;
        if (memo[idx] != -1) return memo[idx];
        if (s[idx] == '0') return 0;
        int res = dfs(s, idx + 1, memo);
        if (idx + 1 < s.size()) {
            int two = 10 * (s[idx] - '0') + (s[idx + 1] - '0');
            if (two <= 26) {
                res += dfs(s, idx + 2, memo);
            }
        }
        memo[idx] = res;
        return res;
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dfs(s, 0, memo);
    }
};
