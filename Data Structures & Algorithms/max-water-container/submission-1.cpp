class Solution {
public:
    int maxArea(vector<int>& heights) {
        // you can only increase water by going to the next highest one
        int left = 0;
        int right = heights.size() - 1;
        int max_area = 0;
        while (left < right) {
            max_area = max(max_area, min(heights[left], heights[right]) * (right - left));
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }
        return max_area;
    }
};
