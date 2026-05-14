class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // it is somewhat the min of them
        // I almost need a two pointer approach here as well honestly
        // I think I need a monotonically decreasing stack
        // we might have to keep track of pairs, but maybe we just do 
        // index on the stack so then we don't
        // something like if the biggest restriction is from the left side
        // then we should probably move the left side
        // oh we could do monotonically increasing stack to know what the 
        // highest is
        stack<int> s;
        int max_area = 0;
        int left = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                // idea is that if we are popping then we have something lower 
                // now, so we should think of this basically being the end
                int idx = s.top();
                s.pop();
                // if it is empty then that means no restrictions and can
                // extend all the way to the left else in the other case
                // it is again i is the rectangle we are not including so we
                // have to be one less to not count it, as the top would be the
                // limiting one, so if our new one at idx 4 on the right and then
                // the one on the left is at idx 3 then we would have area of 0
                // which is good because we really shouldn't count that since
                // our current one we are inserting is smaller and has another 
                // limiting factor
                int left = s.empty() ? 0 : s.top() + 1;
                max_area = max(max_area, (i - left) * heights[idx]);
            }
            s.push(i);
        }
        // there might still be some left in the stack so we see the top item
        // we will see and take the very end
        int end = heights.size();
        while (!s.empty()) {
            int idx = s.top();
            s.pop();
            int left = s.empty() ? 0 : s.top() + 1;
            max_area = max(max_area, (end - left) * heights[idx]);
        }
        return max_area;
    }
};
