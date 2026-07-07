class Solution {
public:
    vector<int> manacher(string& s) {
        string t = "";
        for (int i = 0; i < s.size(); ++i) {
            t += '#';
            t += s[i];
        }
        t += '#';
        int n = t.size();
        vector<int> p(n, 0);
        int l = 0; 
        int r = 0;
        for (int i = 0; i < n; ++i) {
            int mirror = l + (r - i);
            // can we reuse some of the work
            if (i < r) {
                // it can't tell info outside the bound
                p[i] = min(r - i, p[mirror]);
            } // else p[i] would just stay 0 as it gives no information
            // needs to be in bounds and the outer needs to be equal
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            // we need to update the r to help us in the future to use the symmetry
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        return p;
    }
    string longestPalindrome(string s) {
        vector<int> p = manacher(s);
        int max_len = 0;
        int c = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] > max_len) {
                max_len = p[i];
                c = i;
            }
        }
        int pal_len = max_len;
        int l_start = (c - max_len) / 2;
        return s.substr(l_start, pal_len);
    }
};
