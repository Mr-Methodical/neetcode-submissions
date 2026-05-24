class MedianFinder {
public:
    // we can do this with a min heap and a max heap
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    // The idea is that we should have bigger elements in the min_heap and smaller in max_heap
    void addNum(int num) {
        max_heap.push(num); // this will cause max_heap to never be less min_heap in size()
        // we need to keep the invariant that max_heap always has the smaller values in it:
        // this would only get them closer to being the correct size
        if (min_heap.size() > 0 && max_heap.top() > min_heap.top()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        // still could be the case that max_heap has more elements
        if (max_heap.size() - 1 > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        // if both of these ifs fired then it is possible that min_heap has two more elements in it, so:
        if (min_heap.size() > 0 && min_heap.size() - 1 > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        // assuming this can't be called when they are both empty
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else if (max_heap.size() < min_heap.size()) {
            return min_heap.top();
        } else {
            // equal size so we will have to take mean of the top 2
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
    }
};
