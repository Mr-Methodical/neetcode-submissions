class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int right = 0; right < nums.size(); ++right) {
            // remove elements outside the window
            if (!dq.empty() && dq.front() <= right - k) {
                // the ijdea is that we are tracking by index so 
                // if we see one that is outside the index that we have we should get rid 
                // of it
                dq.pop_front();
            }
            // then we should remove smaller elements because they are garbage
            // we would never need them again when we have our current stuff
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
            // now we need to make sure we are passed the first few ones
            // like make sure it is an actual window
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
