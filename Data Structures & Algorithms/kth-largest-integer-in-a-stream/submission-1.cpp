class KthLargest {
public:
    // create a min_heap:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int top;
    KthLargest(int k, vector<int>& nums) {
        // we could just have a min heap and keep k elements in it
        top = k;
        for (int val : nums) {
            if (min_heap.size() >= top && min_heap.top() < val) min_heap.pop();
            else if (min_heap.size() >= top) {
                // case that val is not a greater value
                continue;
            }
            min_heap.push(val);
        }
    }
    
    int add(int val) {
        if (min_heap.size() >= top) {
            // we are already at capacity, only add if it is greater than
            // the min value
            if (min_heap.top() < val) {
                min_heap.pop();
                min_heap.push(val);
            }
        } else {
            min_heap.push(val);
        }
        return min_heap.top();
    }
};
