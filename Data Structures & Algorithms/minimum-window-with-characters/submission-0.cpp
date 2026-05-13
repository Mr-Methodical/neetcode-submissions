class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> need;
        unordered_map <char, int> window;
        for (char c : t) need[c]++;
        int have = 0;
        int total = need.size();
        int left = 0;
        int min_len = INT_MAX;
        int min_left = 0;
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) {
                have++;
            }
            while (have == total) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }
                char l = s[left];
                left++;
                window[l]--;
                if (need.count(l) && window[l] < need[l]) {
                    have--;
                }
            }
        }
        if (min_len == INT_MAX) {
            return "";
        }
        return s.substr(min_left, min_len);
    }
};
