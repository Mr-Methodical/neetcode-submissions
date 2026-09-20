class Solution {
public:
    bool dp(string& s, string& p, int s_idx, int p_idx, vector<vector<int>>& memo) {
        if (p_idx == p.size()) return s_idx == s.size();
        if (s_idx == s.size()) {
            // then we need to take more care because we might be fine if 
            // it has just 0 of each of the following
            if (p_idx < p.size() - 1 && p[p_idx + 1] == '*') {
                return dp(s, p, s_idx, p_idx + 2, memo);
            }
            // if that is not the case we can just return false because then 
            // means we would have had to take care of one more:
            return false;
        }
        if (memo[s_idx][p_idx] != -1) {
            return memo[s_idx][p_idx];
        }
        if (p_idx < p.size() - 1 && p[p_idx + 1] == '*') {
            // we can either go keep going with the star or skip it
            bool retval = false;
            if (s[s_idx] == p[p_idx] || p[p_idx] == '.') {
                // we can advance s forward
                retval = dp(s, p, s_idx + 1, p_idx, memo);
            }
            return memo[s_idx][p_idx] = (dp(s, p, s_idx, p_idx + 2, memo) || retval);
        } else {
            // normal case
            if (p[p_idx] == '.' || s[s_idx] == p[p_idx]) {
                return memo[s_idx][p_idx] = dp(s, p, s_idx + 1, p_idx + 1, memo);
            } else {
                // they are not equal so this could not work
                return memo[s_idx][p_idx] = false;
            }
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
        return dp(s, p, 0, 0, memo);
    }
};
