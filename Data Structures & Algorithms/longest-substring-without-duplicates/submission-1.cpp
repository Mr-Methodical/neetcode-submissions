class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max_len = 0;
        int temp_len = 0;
        unordered_set<char> seen;
        for (int right = 0; right < s.size(); ++right) {
            if (seen.contains(s[right])) {
                while (s[left] != s[right]) {
                    temp_len--;
                    seen.erase(s[left++]);
                }
                left++;
            } else {
                seen.insert(s[right]);
                temp_len++;
            }
            max_len = max(max_len, temp_len);
        }
        return max_len;
    }
};
