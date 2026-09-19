class Solution {
public:
    int dp(string& s, string& t, int sc, int tc, vector<vector<int>>& memo) {
        if (memo[sc][tc] != -1) {
            return memo[sc][tc];
        }
        // these dont' really help us speed up memoization so we don't really need to
        // do them since they are already O(1)
        if (tc == t.size()) {
            return 1;
        } 
        if (sc == s.size()) {
            return 0;
        }
        // only sometimes do we have option of taking
        int total = 0;
        if (s[sc] == t[tc]) {
            total = dp(s, t, sc + 1, tc + 1, memo);
        }
        // we always have the option of skipping
        return memo[sc][tc] = total + dp(s, t, sc + 1, tc, memo);
    }
    int numDistinct(string s, string t) {
        // all that matters is where you are on both strings
        // as the count after will be the same
        vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
        if (t.size() > s.size()) return 0;
        return dp(s, t, 0, 0, memo);
    }
};
