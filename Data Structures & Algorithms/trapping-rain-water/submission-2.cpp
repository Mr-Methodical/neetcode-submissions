class Solution {
public:
    int trap(vector<int>& height) {
        int left = 1;
        int right = height.size() - 2;
        // we can maybe change the height to update for it
        int result = 0;
        // maybe we should only be incrementing the smallest one forward to 
        // be safe against it going to big
        int max_left = height[0];
        int max_right = height[height.size() - 1];
        while (left <= right) {
            if (max_left <= max_right) {
                max_left = max(max_left, height[left]);
                result += max_left - height[left];
                left++;
            } else {
                max_right = max(max_right, height[right]);
                result += max_right - height[right];
                right--;
            }
        }
        return result;
    }
};
