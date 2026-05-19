class Solution {
public:
    int jump(vector<int>& nums) {
        int nxt_idx = 0;
        int end_window = 0;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            nxt_idx = max(nxt_idx, i + nums[i]);
            if (i == end_window) {
                count++;
                end_window = nxt_idx;
            }
        }
        return count;
    }
};
