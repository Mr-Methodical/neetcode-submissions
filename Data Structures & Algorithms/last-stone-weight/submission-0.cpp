class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // O(n) with heapify:
        priority_queue<int> pq(stones.begin(), stones.end());
        // it is max_heap by default:
        while (pq.size() >= 2) {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if (top1 == top2) continue;
            pq.push(top1 - top2);
        }
        // in the case that they both destroy each other we should return 0:
        return (pq.size() == 1) ? pq.top() : 0;
    }
};
