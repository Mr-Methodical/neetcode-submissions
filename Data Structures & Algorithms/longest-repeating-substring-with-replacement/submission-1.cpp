class Solution {
public:
    int characterReplacement(string s, int k) {
        // in our window we could see what most freq is
        int arr[26] = {0};
        int left = 0;
        int longest = 0;
        for (int right = 0; right < s.size(); ++right) {
            arr[s[right] - 'A']++;
            int freq = 0;
            for (int i = 0; i < 26; ++i) {
                freq = max(freq, arr[i]);
            }
            if (right - left + 1 - freq > k) {
                arr[s[left] - 'A']--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
