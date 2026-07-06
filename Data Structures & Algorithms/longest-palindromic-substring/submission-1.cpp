class Solution {
public:
    int len_pal(string& s, int start, int end) {
        while (start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
        }
        return end - start - 1;
    }
    string longestPalindrome(string s) {
        int max_len = 0;
        int start_ind = -1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int l = len_pal(s, i, i);
            if (l > max_len) {
                max_len = l;
                // because the rounding down will be good as there
                // will be l / 2 on left and on right
                start_ind = i - (l / 2);
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            int l = len_pal(s, i, i + 1);
            if (l > max_len) {
                max_len = l;
                // it will be even number it gives
                start_ind = i + 1 - (l / 2);
            }
        }
        return s.substr(start_ind, max_len);
    }
};
