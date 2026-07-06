class Solution {
public:
    bool pal(string& s, int start, int end) {
        // we are checking if it is a palindrome
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int best_start = 0;
        int best_end = 0;
        for (int start = 0; start < s.size(); ++start) {
            for (int end = start; end < s.size(); ++end) {
                if (pal(s, start, end)) {
                    if (end - start > best_end - best_start) {
                        best_start = start;
                        best_end = end;
                    }
                }
            }
        }
        return s.substr(best_start, best_end - best_start + 1);
    }
};
