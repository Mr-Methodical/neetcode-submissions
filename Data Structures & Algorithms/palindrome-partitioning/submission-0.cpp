class Solution {
public: 
    bool is_palindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& result, string& s, int idx, vector<string>& curr) {
        if (idx == s.size()) {
            result.push_back(curr);
            return;
        }
        // two options are that we go with what we currently have or keep expanding the substr
        for (int i = idx; i < s.size(); ++i) {
            if (is_palindrome(s, idx, i)) {
                // substr is a method where we put start and how long it is
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(result, s, i + 1, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // we might need a function to say if it is a palindrome or not
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(result, s, 0, curr);
        return result;
    }
};
