class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we could just do brute force way first:
        // idk how this is a linked list problem
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.contains(num)) return num;
            seen.insert(num);
        }
        return -1; // as this will never happen
    }
};
