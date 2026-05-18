class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // everything appears double basically XOR will cancel them out
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) num ^= nums[i];
        return num;
    }
};
