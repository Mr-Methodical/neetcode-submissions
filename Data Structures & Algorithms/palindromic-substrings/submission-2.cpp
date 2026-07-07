class Solution {
public:
    int expand(string& s, int left, int right) {
        int n = s.size();
        int count = 0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        // another way is that we could expand around each letter
        for (int i = 0; i < n; ++i) {
            count += expand(s, i, i);
            count += expand(s, i, i + 1);
        }
        return count;
    }
};
