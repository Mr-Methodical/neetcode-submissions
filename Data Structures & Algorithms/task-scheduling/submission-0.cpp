class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // oh it is number of cycles before you can do something
        // we should do a priority queue with frequency of element, and then letter, and make it max heap
        // honestly it doesn't matter if we do 26
        // we could use a hash map to do this, char to freq
        unordered_map<char, int> freq;
        for (char task : tasks) freq[task]++;
        priority_queue<int> pq;
        for (const auto& [key, val] : freq) {
            pq.push(val);
        }
        int time = 0;
        // a queue for the ones that can't currently be used
        queue<pair<int, int>> q; // it will be frequency by time
        while (!pq.empty() || !q.empty()) {
            while (!q.empty() && q.front().second == time) {
                int val = q.front().first;
                pq.push(val);
                q.pop();
            }
            time++;
            if (pq.empty()) continue;
            int curr = pq.top();
            pq.pop();
            curr--;
            if (curr == 0) continue;
            q.push({curr, time + n});
        }
        return time;
    }
};
