class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // we could do like a hash map of hte values we need
        unordered_map<int, int> value_to_index;
        for (int i = 0; i < nums.size(); ++i) {
            value_to_index[target - nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (value_to_index.contains(nums[i]) && value_to_index[nums[i]] != i) {
                int j = value_to_index[nums[i]];
                return {min(i, j), max(i, j)};
            }
        }
        return {-1, -1}; // never should happen because they said there will always be solution
    // one question I have though is if we are allowed to return it that way
    // are we giving back somethign that is stack allocated?
    }
};
