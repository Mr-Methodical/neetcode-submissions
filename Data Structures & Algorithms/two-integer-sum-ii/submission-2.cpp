class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        // idea is that when when less than we go down the other path
        while (left < right) {
            if (numbers[left] + numbers[right] == target) break;
            if (numbers[left] + numbers[right]  > target) {
                right--;
            } else {
                left++;
            }
        }
        return {left + 1, right + 1};
    }
};
