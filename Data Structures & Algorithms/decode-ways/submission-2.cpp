class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int back1 = (s[n - 1] == '0') ? 0 : 1;
        int back2 = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0') {
                back2 = back1;
                back1 = 0; // this is not a possible path to go down
            } else {
                int curr = back1;
                int num = 10 * (s[i] - '0') + (s[i + 1] - '0');
                if (num <= 26) {
                    // then we could also count that back2 pairs we would get:
                    curr += back2; 
                }
                back2 = back1;
                back1 = curr;
            }
        }
        return back1;
    }
};
