class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // we can just put it into a min heap and only keep k in it:
        priority_queue<int, vector<int>, greater<int>> pq; // greater goes to bottom
        for (int num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else if (num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();
        // the time complexity of this will be n * log k because that is the max size it can get to
    }
};
