class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> counts = {0};
        for (int i = 0; i < s.size(); ++i) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        // we need it all to be 0:
        for (int i = 0; i < 26; ++i) {
            if (counts.at(i) != 0) return false;
        }
        return true;
    }
};
