class Solution {
public:
    int manacher(string& s) {
        int count = 0;
        // we want to do only odd case so #'s
        string t = "";
        for (int i = 0; i < s.size(); ++i) {
            t += '#';
            t += s[i];
        }
        t += '#';
        int n = t.size();
        // this will give radius of each palindrom out
        vector<int> p(n, 0);
        // for the biggest palindrome we have seen so far, we want the mirror
        // to help us
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; ++i) {
            // we expand out at each but first try mirror property
            if (i < r) {
                int mirror = l + (r - i);
                p[i] = min(p[mirror], r - i);
            }
            // now we will try expanding outwards while updating r
            // which allows this to be amortized O(n) because we keep pushing r on
            // the update
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++; // increase radius
            }
            if (i + p[i] > r) {
                r = i + p[i];
                l = i - p[i];
            }
            // odd should go up because that is one palindrome
            // #a# is 1 so 1 + 1 dvided by 2 is 1 good
            // for even ex. #a#a# this is only one palindrome so divide by 2 is right
            // for the even case we 
            count += (p[i] + 1) / 2;
        }
        return count;
    }
    int countSubstrings(string s) {
        return manacher(s);
    }
};
