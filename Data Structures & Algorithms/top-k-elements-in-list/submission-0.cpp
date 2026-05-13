class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // let's do the fast bucket sort approach first
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }
        vector<int> result;
        for (int i = nums.size(); i >= 0; --i) {
            for (int element : buckets[i]) {
                result.push_back(element);
                --k;
            }
            if (k == 0) break;
        }
        return result;
    }
};
