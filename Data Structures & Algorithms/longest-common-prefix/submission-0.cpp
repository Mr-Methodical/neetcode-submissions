class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        string shortest = strs[0];
        for (int i = 1; i < n; ++i) {
            if (shortest.size() > strs[i].size()) {
                shortest = strs[i];
            }
        }
        int j = 0;
        for (char c : shortest) {
            // we will go through each letter and
            bool not_equal = false;
            for (int i = 0; i < n; ++i) {
                if (strs[i][j] != c) {
                    not_equal = true;
                    break;
                }
            } 
            if (not_equal) break;
            ans += c;
            j++;
        }
        return ans;
    }
};