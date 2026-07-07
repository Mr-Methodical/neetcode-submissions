class Solution {
public:
    vector<int> manacher(string& s) {
        // we will attach # between everything so we only have to worry about odd case
        string t = "";
        for (int i = 0; i < s.size(); ++i) {
            t += '#';
            t += s[i];
        }
        t += '#';
        int n = t.size();
        int r = 0;
        int l = 0;
        vector<int> p(n, 0);
        // i will be the iterator it will be the center we expand
        // we will expand smartly and always use our symmetry
        for (int i = 0; i < n; ++i) {
            int mirror = l + (r - i);
            if (i < r) {
                // as the old mirror could have expanded outside boundary
                p[i] = min(r - i, p[mirror]);
            }
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
            t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            // we might need to update boundary
            if (p[i] + i > r) {
                r = p[i] + i;
                l = i - p[i];
            }
        }
        return p;
    }
    string longestPalindrome(string s) {
        vector<int> w = manacher(s);
        int c = 0;
        int len = 0;
        for (int i = 0; i < w.size(); ++i) {
            if (w[i] > len) {
                len = w[i];
                c = i;
            }
        }
        int left = (c - len) / 2;
        return s.substr(left, len);
    }
};
