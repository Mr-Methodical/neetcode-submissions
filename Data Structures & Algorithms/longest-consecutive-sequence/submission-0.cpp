class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ok so we will put into hash set
        // I guess we could keep track of everything after and then if we 
        // have something before that it will eventually pick it up
        unordered_set<int> s(nums.begin(), nums.end());
        int max_len = 0;
        for (int num : s) {
            if (!s.contains(num - 1)) {
                int len = 1;
                while (s.contains(num + len)) len++;
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
