class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // maybe we could have like a monotonic stack or something like that
        // we will put on index so then we have days since
        // we will do decreasing monotonic stack
        stack<int> s;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                // we will put the the highest temps down to the bottom
                result[s.top()] = i - s.top();
                s.pop(); 
            }
            s.push(i);
        }
        // since we intialized to 0 then it allows the ones that
        // didn't get picked to just have 0 so it not possible for htem
        // to have a warmer day
        return result;
    }
};
